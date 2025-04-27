/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:52:17 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 16:19:37 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		static const int _fractionalBits = 8;
		int _value;
	public:
		Fixed();
		Fixed(Fixed const &copy);
		Fixed &operator=(Fixed const &copy);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif