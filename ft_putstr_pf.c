/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:28:33 by jolivare          #+#    #+#             */
/*   Updated: 2026/09/10 14:15:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_pf(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static void	print_padding(char c, int count, size_t *cont)
{
	while (count-- > 0)
		ft_putchar_pf(c, cont);
}

void	ft_putstr_pf(char *str, size_t *cont, t_flags flags)
{
	int	len;
	int	spaces;
	int	i;

	if (!str)
		str = "(null)";
	len = ft_strlen_pf(str);
	if (flags.dot && flags.precision < len)
		len = flags.precision;
	spaces = 0;
	if (flags.width > len)
		spaces = flags.width - len;
	if (!flags.minus)
		print_padding(' ', spaces, cont);
	i = 0;
	while (i < len)
		ft_putchar_pf(str[i++], cont);
	if (flags.minus)
		print_padding(' ', spaces, cont);
}
