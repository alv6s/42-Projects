/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:28:10 by pevieira          #+#    #+#             */
/*   Updated: 2023/05/19 13:09:02 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	x1;
	char	*x2;

	x1 = 'A';
	x2 = "Ola tudo bem?";
	ft_printf("O meu teste\n ____________\nCaracter: %c\nString: %s\nPointer: %p\nDecimal: %d\nInt: %i\nUnsigned Decimal: %u\nNbr hexadecimal: %x\nNBR HEXADECIMAL: %X\nicone: %%\n\n", x1, x2, &x2, 132, 0, 55, 42, 42);
	printf("O printf original\n ____________\nCaracter: %c\nString: %s\nPointer: %p\nDecimal: %d\nInt: %i\nUnsigned Decimal: %u\nNbr hexadecimal: %x\nNBR HEXADECIMAL: %X\nicone: %%\n", x1, x2, &x2, 132, 0, 55, 42, 42);
	return (0);
}
