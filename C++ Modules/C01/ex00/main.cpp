/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:14 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/13 15:08:11 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string ZombieName;
    
    while(true) {
        std::cout << "Enter the Zombie Name: ";
        std::getline(std::cin, ZombieName); // Lê o nome do zumbi

        if (std::cin.eof()) {
            std::cout << std::endl << "Exiting the Zombie Simulation!" << std::endl;
            break; // Sai do loop se o usuário pressionar Ctrl+D ou EOF
        }
        
        if (ZombieName.empty()) {
            std::cout << "Please enter the Zombie name." << std::endl;
            continue;
        }
        Zombie *zombie = newZombie_heap(ZombieName);
        zombie->speak();
        delete zombie;
        std::cout << "Enter the Zombie Name: ";
        std::getline(std::cin, ZombieName);
        
        if (std::cin.eof()) {
            std::cout << std::endl << "Exiting the Zombie Simulation!" << std::endl;
            break;
        }
        if (ZombieName.empty()) {
            std::cout << "Please enter the Zombie name." << std::endl;
            continue;
        }
        randomChump_stack(ZombieName);
    }
    return 0;
}