/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:52:17 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/25 12:52:34 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		static const int _fractionalBits = 8;
		int _value;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const & copy);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed & operator=(Fixed const & copy);
};

#endif