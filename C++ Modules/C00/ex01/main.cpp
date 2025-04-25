/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:58:39 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/25 13:01:19 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook phonebook;
    std::string command;

    while (true)
	{
		command.clear();
		if (std::cin.eof())
			break ;
        std::cout << "Enter a command (ADD, SEARCH, EXIT): \n";
		if (!std::getline(std::cin, command))
            break;
		if (command == "ADD") {
            phonebook.add_contact();
        }
        else if (command == "SEARCH") {
            phonebook.search_contact();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    return 0;
}
