/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:29:06 by jolivare          #+#    #+#             */
/*   Updated: 2026/09/10 14:10:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthexup_recursive(unsigned long num, size_t *cont)
{
	char	*hexbase;

	hexbase = "0123456789ABCDEF";
	if (num > 15)
		ft_puthexup_recursive((num / 16), cont);
	ft_putchar_pf(*(hexbase + (num % 16)), cont);
}

static void	print_padding(char c, int count, size_t *cont)
{
	while (count-- > 0)
		ft_putchar_pf(c, cont);
}

static void	get_counts(unsigned long n, t_flags flags, int prefix, int *c)
{
	c[0] = ft_numlen_pf(n, 16);
	if (n == 0 && flags.dot && flags.precision == 0)
		c[0] = 0;
	c[1] = 0;
	if (flags.dot && flags.precision > c[0])
		c[1] = flags.precision - c[0];
	else if (flags.zero && !flags.minus && !flags.dot
		&& flags.width > c[0] + prefix)
		c[1] = flags.width - c[0] - prefix;
	c[2] = 0;
	if (flags.width > c[0] + c[1] + prefix)
		c[2] = flags.width - c[0] - c[1] - prefix;
}

void	ft_puthexup_pf(unsigned long num, size_t *cont, t_flags flags)
{
	int	prefix;
	int	c[3];

	prefix = 0;
	if (flags.hash && num != 0)
		prefix = 2;
	get_counts(num, flags, prefix, c);
	if (!flags.minus)
		print_padding(' ', c[2], cont);
	if (prefix)
		ft_putstr_pf("0X", cont, ft_init_flags());
	print_padding('0', c[1], cont);
	if (c[0] > 0)
		ft_puthexup_recursive(num, cont);
	if (flags.minus)
		print_padding(' ', c[2], cont);
}
