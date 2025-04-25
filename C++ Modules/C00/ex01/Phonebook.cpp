/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:25:35 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/25 13:09:09 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

bool is_valid_ascii(const std::string& input) {
    if (input.empty()) {
        std::cout << "The field can't be empty.\n";
        return false;
    }

    size_t i = 0;
    while (i < input.length()) {
        if (input[i] < 32 || input[i] > 126) {
            std::cout << "The text has invalid characters.\n";
            return false;
        }
        i++;
    }
    return true;
}

bool is_valid_phone(const std::string& input) {
    if (input.empty()) {
        std::cout << "The phone number can't be empty.\n";
        return false;
    }

    size_t i = 0;
    while (i < input.length()) {
        if (!isdigit(input[i])) {
            std::cout << "The phone number can only contain digits.\n";
            return false;
        }
        i++;
    }
    return true;
}


Phonebook::Phonebook() : _i(0), _total_added(0) {
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
}

Phonebook::~Phonebook() {
	std::cout << "Closing the phonebook. Goodbye!" << std::endl;
}


void Phonebook::add_contact() {
    std::string firstName, lastName, nickname, phone, secret;

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, firstName);
    } while (!is_valid_ascii(firstName));

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, lastName);
    } while (!is_valid_ascii(lastName));

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nickname);
    } while (!is_valid_ascii(nickname));

    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phone);
    } while (!is_valid_phone(phone));

    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, secret);
    } while (!is_valid_ascii(secret));

    _contacts[_i].set_contact_info(firstName, lastName, nickname, phone, secret);
    _i = (_i + 1) % 8;
    if (_total_added < 8)
        _total_added++;

    std::cout << "Contact added!" << std::endl;
}


void Phonebook::search_contact() const {
	if (this->_total_added == 0) {
		std::cout << "No contacts available!" << std::endl;
		return;
	}
    std::cout << "   Index   First Name  Last Name   Nickname\n";
    std::cout << "-------------------------------------------\n";
    
    int i = 0;
    while (i < _total_added) {
        std::cout << std::setw(10) << std::right << i;
        std::cout << "|" 
                  << std::setw(10) << std::right << (_contacts[i].show_first_name().substr(0, 9) + (_contacts[i].show_first_name().length() > 9 ? "." : ""))
                  << "|" 
                  << std::setw(10) << std::right << (_contacts[i].show_last_name().substr(0, 9) + (_contacts[i].show_last_name().length() > 9 ? "." : ""))
                  << "|" 
                  << std::setw(10) << std::right << (_contacts[i].show_nickname().substr(0, 9) + (_contacts[i].show_nickname().length() > 9 ? "." : ""))
                  << std::endl;
        i++;
    }
    int index;
	bool validInput = false;

	while (!validInput) {
        std::cout << "Enter the index of the contact you want to display:\n";
        std::cin >> index;
		if ( std::cin.eof())
		{
            return;
        }
        if (std::cin.fail() || index < 0 || index >= _total_added) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Please enter a valid index between 0 and " << _total_added - 1 << ".\n";
        } 
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            validInput = true;
        }
    }
    std::cout << "First Name: " << _contacts[index].show_first_name() << std::endl;
    std::cout << "Last Name: " << _contacts[index].show_last_name() << std::endl;
    std::cout << "Nickname: " << _contacts[index].show_nickname() << std::endl;
    std::cout << "Phone: " << _contacts[index].show_phone() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].show_secret() << std::endl;
}
