/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:36:06 by hefernan          #+#    #+#             */
/*   Updated: 2021/09/26 22:56:15 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format
{
	int		len;
	char	type;
}					t_format;

char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			ft_putchar(char c, t_format *magnum);
void			ft_putstring(char *str, t_format *magnum);
int				ft_printf(const char *str, ...);
void			aff_nbr(t_format *magnum, va_list lol);
void			parse_f(const char *str, t_format *magnum, int *n);
void			parg(t_format *magnum, va_list lol);
char			*ft_itoa_base(unsigned long n, char *base);

#endif