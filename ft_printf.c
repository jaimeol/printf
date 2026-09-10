/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:19:06 by jolivare          #+#    #+#             */
/*   Updated: 2026/09/10 14:10:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char c, size_t *cont, t_flags flags)
{
	if (c == 'c')
		ft_print_char(va_arg(va, int), cont, flags);
	else if (c == 's')
		ft_putstr_pf(va_arg(va, char *), cont, flags);
	else if (c == 'i' || c == 'd')
		ft_putnbr_pf(va_arg(va, int), cont, flags);
	else if (c == 'x')
		ft_puthexlow_pf(va_arg(va, unsigned int), cont, flags);
	else if (c == 'X')
		ft_puthexup_pf(va_arg(va, unsigned int), cont, flags);
	else if (c == 'u')
		ft_putunsigned_pf(va_arg(va, unsigned int), cont, flags);
	else if (c == 'p')
		ft_putptr_pf(va_arg(va, void *), cont, flags);
	else if (c == '%')
		ft_putchar_pf(c, cont);
}

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.dot = 0;
	return (flags);
}

static void	ft_parse_width_prec(const char *str, int *i, t_flags *f)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		f->width = f->width * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		f->dot = 1;
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			f->precision = f->precision * 10 + (str[*i] - '0');
			(*i)++;
		}
	}
}

int	ft_parse_flags(const char *str, t_flags *f)
{
	int	i;

	i = 0;
	while (str[i] == '#' || str[i] == ' ' || str[i] == '+'
		|| str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '#')
			f->hash = 1;
		else if (str[i] == ' ')
			f->space = 1;
		else if (str[i] == '+')
			f->plus = 1;
		else if (str[i] == '-')
			f->minus = 1;
		else if (str[i] == '0')
			f->zero = 1;
		i++;
	}
	ft_parse_width_prec(str, &i, f);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	cont;
	t_flags	flags;

	if (!str)
		return (0);
	cont = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flags = ft_init_flags();
			str += ft_parse_flags(str, &flags);
			if (*str)
				ft_format(va, *str, &cont, flags);
		}
		else
			ft_putchar_pf(*str, &cont);
		if (*str)
			str++;
	}
	va_end(va);
	return (cont);
}
