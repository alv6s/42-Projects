/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:38 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/27 17:56:13 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(const Animal &src);
		virtual ~Animal(void);
		
		Animal &operator=(const Animal &src);
		
		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif