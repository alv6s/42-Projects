/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:28:10 by pevieira          #+#    #+#             */
/*   Updated: 2023/06/19 10:31:33 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int	main(void)
// {
// 	char	x1;
// 	char	*x2;

// 	x1 = 'A';
// 	x2 = "Ola tudo bem?";
// 	ft_printf("O meu teste\n ^^^^^^^^^^\nCaracter: %c\nString: %s\nPointer: %p\nDecimal: %d\nInt: %i\nUnsigned Decimal: %u\nNbr hexadecimal: %x\nNBR HEXADECIMAL: %X\nicone: %%\n\n", x1, x2, &x2, 132, 0, 55, 42, 42);
// 	printf("O printf original\n^^^^^^^^^^\nCaracter: %c\nString: %s\nPointer: %p\nDecimal: %d\nInt: %i\nUnsigned Decimal: %u\nNbr hexadecimal: %x\nNBR HEXADECIMAL: %X\nicone: %%\n", x1, x2, &x2, 132, 0, 55, 42, 42);
// 	return (0);
// }
#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	char	string[] = "New String";
	// void	*ptr;
	int		returnlen;
	void *j = NULL;
	
	returnlen = ft_printf("Simple Print\n");
	printf("Len Simple Print: %d\n", returnlen);
	returnlen = printf("Simple Print\n");
	printf("Len Simple Print: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("Char: %c%c%c\n", 'A', 'B', 'C');
	printf("Len Char: %d\n", returnlen);
	returnlen = printf("Char: %c%c%c\n", 'A', 'B', 'C');
	printf("Len Char: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("String: %s\n", string);
	printf("Len String: %d\n", returnlen);
	returnlen = printf("String: %s\n", string);
	printf("Len String: %d\n", returnlen);
	
	printf("------------------------\n");
	
	returnlen = ft_printf("Pointer: %p\n", j);
	printf("Len Pointer: %d\n", returnlen);
	returnlen = printf("Pointer: %p\n", j);
	printf("Len Pointer: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Decimal: %d\n", 100);
	printf("Len Decimal: %d\n", returnlen);
	returnlen = printf("Decimal: %d\n", 100);
	printf("Len Decimal: %d\n", returnlen);
		
	printf("------------------------\n");	
	
	returnlen = ft_printf("Integer: %i\n", 3000);
	printf("Len Integer: %d\n", returnlen);
	returnlen = printf("Integer: %i\n", 3000);
	printf("Len Integer: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Unsigned Int: %u\n", 4294967295);
	printf("Len Unsigned Int: %d\n", returnlen);
	returnlen = printf("Unsigned Int: %lu\n", 4294967295);
	printf("Len Unsigned Int: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Hexadecimal X: %X\n", 0);
	printf("Len Hexadecimal: %d\n", returnlen);
	returnlen = printf("Hexadecimal X: %X\n", 0);
	printf("Len Hexadecimal: %d\n", returnlen);
	
	printf("------------------------\n");	
	
	returnlen = ft_printf("Hexadecimal x: %x\n", 2022);
	printf("Len hexadecimal: %d\n", returnlen);
	returnlen = printf("Hexadecimal x: %x\n", 2022);
	printf("Len hexadecimal: %d\n", returnlen);
	
	printf("------------------------\n");	
	returnlen = ft_printf("Percent sign: %%%%%%%%%%\n");
	printf("Len Percent: %d\n", returnlen);
	returnlen = printf("Percent sign: %%%%%%%%%%\n");
	printf("Len Percent: %d\n", returnlen);
	
	printf("--------testeavaliacao--------\n");
        ft_printf("cspdiuxX% \n");
        ft_printf("%i\n", 0);
        ft_printf("%p\n",j);
        ft_printf("%i\n", -2147483648);
        ft_printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 'O', "ola", j, 9, 100, 3144, 42, 42);
        ft_printf("%c, %c, %c", 'A', 'B', 'c');
        printf("--------original--------\n");
        printf("cspdiuxX\n");
        printf("%i\n", 0);
        printf("%p\n",j);
        printf("%li\n", -2147483648);
        printf("%c, %s, %p, %d, %i, %u, %x, %X, %%\n", 'O', "ola", j, 9, 100, 3144, 42, 42);
        printf("%c, %c, %c", 'A', 'B', 'c');

}
