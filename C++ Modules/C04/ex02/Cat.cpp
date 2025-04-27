/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:41 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/27 18:07:27 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "Cat Default Constructor Called" << std::endl;
}


Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &src)
	{
		_type = src._type;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat: *Meeooowww...*" << std::endl;
}
