/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:18:15 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/13 11:11:45 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook{
	private:
		Contact _contacts[8];
		int _i;
		int _total_added;
	public:
		Phonebook();
		~Phonebook();
    	void search_contact() const;
    	void add_contact();
};

#endif