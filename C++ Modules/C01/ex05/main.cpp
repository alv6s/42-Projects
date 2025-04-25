/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:10:17 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/14 20:11:45 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac != 2){
		std::cerr << "Error, please use as follows: " << "./harl <level>" << std::endl;
		return 1;
	}
	harl.complain(av[1]);
	return (0);
}