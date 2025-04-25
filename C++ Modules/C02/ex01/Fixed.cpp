/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:58:26 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/21 19:59:00 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const intValue)
{
	std::cout << "Int constructor called" << std::endl;
	_value = intValue << _fractionalBits;
}

Fixed::Fixed(float const floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignation operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return _value;
}

void Fixed::setRawBits( int const raw)
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
	return _value / (1 << _fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return o;
}