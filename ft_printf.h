/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare <jolivare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:08:47 by jolivare          #+#    #+#             */
/*   Updated: 2026/09/10 14:10:00 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flags
{
	int	hash;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	dot;
}	t_flags;

t_flags	ft_init_flags(void);
int		ft_printf(char const *str, ...);
int		ft_numlen_pf(unsigned long num, int base);
void	ft_putchar_pf(char c, size_t *cont);
void	ft_print_char(char c, size_t *cont, t_flags flags);
void	ft_putstr_pf(char *str, size_t *cont, t_flags flags);
void	ft_putnbr_pf(int num, size_t *cont, t_flags flags);
void	ft_puthexlow_pf(unsigned long num, size_t *cont, t_flags flags);
void	ft_puthexup_pf(unsigned long num, size_t *cont, t_flags flags);
void	ft_putunsigned_pf(unsigned int n, size_t *cont, t_flags flags);
void	ft_putptr_pf(void *str, size_t *cont, t_flags flags);

#endif
