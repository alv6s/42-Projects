/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:16:21 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 20:53:56 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact(void) 
{}

Contact::~Contact(void) 
{}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phone, std::string secret) :
 _firstName(firstName), _lastName(lastName), _nickname(nickname), _phone(phone), _secret(secret) 
{}

 void Contact::show_contact(void) const
{
	std::cout << "THE CONTACT INFORMATION IS:" << std::endl;
	std::cout << "1. First Name: " << _firstName << std::endl;
	std::cout << "2. Last Name: " << _lastName << std::endl;
	std::cout << "3. Nickname: " << _nickname << std::endl;
	std::cout << "4. Phone Number: " << _phone << std::endl;
	std::cout << "5. Darkest Secret" << _secret << std::endl;
}

std::string Contact::show_first_name() const 
{
	return _firstName;
}

std::string Contact::show_last_name()  const 
{
	return _lastName;
}

std::string Contact::show_nickname()  const 
{
	return _nickname;
}
std::string Contact::show_phone()  const 
{
	return _phone;
}
std::string Contact::show_secret()  const 
{
	return _secret;
}

void Contact::set_contact_info(std::string firstName, std::string lastName, std::string nickname,
	std::string phone, std::string secret) 
	{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phone = phone;
	_secret = secret;
}
