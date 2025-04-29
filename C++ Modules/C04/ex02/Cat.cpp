/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:41 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/29 18:36:19 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat Default Constructor Called" << std::endl;
}


Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat Copy Constructor Called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat Copy Assignment Operator Called" << std::endl;
	if (this != &src)
	{
		_type = src._type;
	}
	*this->_brain = *src._brain;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat: *Meeooowww...*" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return _brain;
}