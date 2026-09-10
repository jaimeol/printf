/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:52 by jolivare          #+#    #+#             */
/*   Updated: 2026/09/10 14:05:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_recursive(long num, size_t *cont)
{
	if (num > 9)
		ft_putnbr_recursive((num / 10), cont);
	ft_putchar_pf(('0' + num % 10), cont);
}

static void	print_padding(char c, int count, size_t *cont)
{
	while (count-- > 0)
		ft_putchar_pf(c, cont);
}

static void	get_counts(long n, t_flags flags, char sign, int *c)
{
	c[0] = ft_numlen_pf(n, 10);
	if (n == 0 && flags.dot && flags.precision == 0)
		c[0] = 0;
	c[1] = 0;
	if (flags.dot && flags.precision > c[0])
		c[1] = flags.precision - c[0];
	else if (flags.zero && !flags.minus && !flags.dot
		&& flags.width > c[0] + (sign != 0))
		c[1] = flags.width - c[0] - (sign != 0);
	c[2] = 0;
	if (flags.width > c[0] + c[1] + (sign != 0))
		c[2] = flags.width - c[0] - c[1] - (sign != 0);
}

void	ft_putnbr_pf(int num, size_t *cont, t_flags flags)
{
	long	n;
	char	sign;
	int		c[3];

	n = num;
	sign = 0;
	if (n < 0)
	{
		sign = '-';
		n = -n;
	}
	else if (flags.plus)
		sign = '+';
	else if (flags.space)
		sign = ' ';
	get_counts(n, flags, sign, c);
	if (!flags.minus)
		print_padding(' ', c[2], cont);
	if (sign)
		ft_putchar_pf(sign, cont);
	print_padding('0', c[1], cont);
	if (c[0] > 0)
		ft_putnbr_recursive(n, cont);
	if (flags.minus)
		print_padding(' ', c[2], cont);
}
