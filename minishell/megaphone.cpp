/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:52:29 by pevieira          #+#    #+#             */
/*   Updated: 2024/10/09 15:55:14 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	toupper(std::string str)
{
	int 		i;
	std::string upperStr;

	i = 0;
	while(str.length() > 0 && str[i])
	{
		upperStr += std::toupper(str[i]);
		i++;
	}
	return (upperStr);
}

int	main(int ac, char **av)
{
	int			i;
	std::string	upperStr;

	i = 0;
	while (av[++i])
	{
		upperStr = toupper(av[i]);
		std::cout << upperStr;
	}
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << '\n';
	return (0);
}
