/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:45 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/29 18:29:36 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->_brain = new Brain();
	*this = src;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &src)
		_type = src._type;
	*this->_brain = *src._brain;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog: *Woof! Woof!*" << std::endl;
}

Brain	*Dog::getBrain() const{
	return _brain;
}