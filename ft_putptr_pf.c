/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:34:00 by jolivare          #+#    #+#             */
/*   Updated: 2026/09/10 14:15:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_padding(char c, int count, size_t *cont)
{
	while (count-- > 0)
		ft_putchar_pf(c, cont);
}

void	ft_putptr_pf(void *str, size_t *cont, t_flags flags)
{
	unsigned long	ptr;
	int				len;
	int				spaces;

	ptr = (unsigned long)str;
	if (!ptr)
		len = 5;
	else
		len = 2 + ft_numlen_pf(ptr, 16);
	spaces = 0;
	if (flags.width > len)
		spaces = flags.width - len;
	if (!flags.minus)
		print_padding(' ', spaces, cont);
	if (!ptr)
		ft_putstr_pf("(nil)", cont, ft_init_flags());
	else
	{
		ft_putstr_pf("0x", cont, ft_init_flags());
		ft_puthexlow_pf(ptr, cont, ft_init_flags());
	}
	if (flags.minus)
		print_padding(' ', spaces, cont);
}
