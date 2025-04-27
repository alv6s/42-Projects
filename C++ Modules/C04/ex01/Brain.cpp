/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:51:40 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/27 19:06:40 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain Copy Constructor Called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor Called" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain Assignation Operator Called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return ("Invalid i");
	return (ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		ideas[i] = idea;
	else
		std::cout << "Invalid i" << std::endl;
}