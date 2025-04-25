/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:20:33 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/21 20:21:30 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(Fixed const & src);
		Fixed(float const floatValue);
		Fixed(int const intValue);
		~Fixed();
		int toInt( void ) const;
		void setRawBits( int const raw );
		int getRawBits( void ) const;
		float toFloat( void ) const;
		
		Fixed operator+(Fixed const & src);
		Fixed & operator=(Fixed const & src);
		Fixed operator*(Fixed const & src);
		Fixed operator-(Fixed const & src);
		Fixed operator++(int);
		Fixed operator/(Fixed const & src);
		Fixed & operator++();
		Fixed operator--(int);
		Fixed & operator--();
		
		bool operator>=(Fixed const & src) const;
		bool operator<(Fixed const & src) const;
		bool operator>(Fixed const & src) const;
		bool operator<=(Fixed const & src) const;
		bool operator!=(Fixed const & src) const;
		bool operator==(Fixed const & src) const;

		static Fixed const & max(Fixed const & a, Fixed const & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif