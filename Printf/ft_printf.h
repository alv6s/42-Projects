/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                              	        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:06:13 by pevieira          #+#    #+#             */
/*   Updated: 2023/05/17 16:28:33 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char *str, ...);
int			ft_putchar(int c);
int			ft_write_special(va_list args, const char s);
int			ft_putstr(char *str);
int			ft_hexparam(unsigned int nbr, const char s);
char		*ft_uitoa(unsigned int n);
int			ft_printpointer(unsigned long long nbr);
void		ft_hexconvertion(unsigned long long nbr, const char s);
int			ft_hexlen(unsigned long long nbr);
int			ft_unsigned_putdecimal(unsigned int nbr);
int			ft_putdecimal(int nbr);

#endif