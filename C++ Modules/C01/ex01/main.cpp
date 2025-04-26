/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:30:54 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 08:55:45 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string zombieName;
	int 		zombieCount;
	int			i;

	i = -1;
	while(1)
	{
		std::cout << "How many Zombies are? ";
		std::cin >> zombieCount;
		if (std::cin.eof()) {
			std::cout << std::endl << "zombieHorde is over" << std::endl;
			break;
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Can't accept that input. Try 1 to 999 range." << std::endl;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (zombieCount <= 0 || zombieCount > 999)
		{
			std::cout << "Can't accept that input. Try a number between 1 and 999." << std::endl;
			continue;
		}
		std::cout << "What's the name of the Zombies?";
		std::getline(std::cin, zombieName);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Exiting the zombieHorde Simulation!" << std::endl;
			break;
		}
		if (zombieName.empty())
		{
			std::cout << "Please give a name." << std::endl;
			continue;
		}
		Zombie *zombies = zombieHorde(zombieCount, zombieName);
		while( ++i < zombieCount)
			zombies[i].announce();
		delete[] zombies;
		return 0;
}
}