/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:14 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 08:51:19 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string ZombieName;
    
	std::cout << "Welcome to the Horde of Zombies" << std::endl;
        std::cout << "1 - Enter the Heap Zombie Name: ";
        std::getline(std::cin, ZombieName);
        if (std::cin.eof()) {
            std::cout << std::endl << "Exiting the Zombie Simulation!" << std::endl;
        }
        if (ZombieName.empty()) {
            std::cout << "Please enter the Zombie name." << std::endl;
        }
        Zombie *zombie = newZombie(ZombieName);
        zombie->announce();
        delete zombie;
        std::cout << "2 - Enter the Stack Zombie Name: ";
        std::getline(std::cin, ZombieName);
        if (std::cin.eof()) {
            std::cout << std::endl << "Exiting the Zombie Simulation!" << std::endl;
        }
        if (ZombieName.empty()) {
            std::cout << "Please enter the Zombie name." << std::endl;
        }
        randomChump(ZombieName);
    }
    return 0;
}