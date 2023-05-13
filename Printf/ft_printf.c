/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:54:46 by pevieira          #+#    #+#             */
/*   Updated: 2023/05/13 16:40:42 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//a funcao que faz o  printezito e conta o buffer

va_arg(args, type)


int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int result;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i+1] "cspdiuxX%")    // 
		
	}
	va_end(args)

	return result;
}