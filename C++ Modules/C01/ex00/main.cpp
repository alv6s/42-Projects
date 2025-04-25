/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:14 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/25 16:58:15 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string ZombieName;
    
    while(true) {
        std::cout << "1 - Enter the Heap Zombie Name: ";
        std::getline(std::cin, ZombieName);

        if (std::cin.eof()) {
            std::cout << std::endl << "Exiting the Zombie Simulation!" << std::endl;
            break;
        }
        if (ZombieName.empty()) {
            std::cout << "Please enter the Zombie name." << std::endl;
            continue;
        }
        Zombie *zombie = newZombie(ZombieName);
        zombie->announce();
        delete zombie;
        std::cout << "2 - Enter the Stack Zombie Name: ";
        std::getline(std::cin, ZombieName);
        if (std::cin.eof()) {
            std::cout << std::endl << "Exiting the Zombie Simulation!" << std::endl;
            break;
        }
        if (ZombieName.empty()) {
            std::cout << "Please enter the Zombie name." << std::endl;
            continue;
        }
        randomChump(ZombieName);
    }
    return 0;
}