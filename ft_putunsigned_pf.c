/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:28:09 by jolivare          #+#    #+#             */
/*   Updated: 2026/09/10 14:15:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunsigned_recursive(unsigned int num, size_t *cont)
{
	if (num > 9)
		ft_putunsigned_recursive((num / 10), cont);
	ft_putchar_pf(('0' + num % 10), cont);
}

static void	print_padding(char c, int count, size_t *cont)
{
	while (count-- > 0)
		ft_putchar_pf(c, cont);
}

static void	get_counts(unsigned int n, t_flags flags, int *c)
{
	c[0] = ft_numlen_pf(n, 10);
	if (n == 0 && flags.dot && flags.precision == 0)
		c[0] = 0;
	c[1] = 0;
	if (flags.dot && flags.precision > c[0])
		c[1] = flags.precision - c[0];
	else if (flags.zero && !flags.minus && !flags.dot
		&& flags.width > c[0])
		c[1] = flags.width - c[0];
	c[2] = 0;
	if (flags.width > c[0] + c[1])
		c[2] = flags.width - c[0] - c[1];
}

void	ft_putunsigned_pf(unsigned int num, size_t *cont, t_flags flags)
{
	int	c[3];

	get_counts(num, flags, c);
	if (!flags.minus)
		print_padding(' ', c[2], cont);
	print_padding('0', c[1], cont);
	if (c[0] > 0)
		ft_putunsigned_recursive(num, cont);
	if (flags.minus)
		print_padding(' ', c[2], cont);
}
