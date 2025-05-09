/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:52:29 by pevieira          #+#    #+#             */
/*   Updated: 2025/03/13 19:21:25 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void upperstring(std::string str)
{
	std::string	upperstring;
	int	i;

	i=0;
	while(str[i])
	{
		upperstring += toupper(str[i]);
		i++;
	}
	std::cout << upperstring;
}

int main(int ac, char **av)
{
	int	i;
	
	i = 0;
	if (ac > 1)
	{
		while (av[++i])
			upperstring(av[i]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << '\n';
	return (0);
}
