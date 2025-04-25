/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:59:32 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/13 10:37:00 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phone;
		std::string _secret;
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, 
			std::string phone, std::string secret);

		void set_contact_info(std::string firstName, std::string lastName, std::string nickname,
			std::string phone, std::string secret);
		std::string show_first_name() const;
		std::string show_last_name() const;
		std::string show_nickname() const;
		std::string show_phone() const;
		std::string show_secret() const;
		void show_contact(void) const;
		
};

#endif