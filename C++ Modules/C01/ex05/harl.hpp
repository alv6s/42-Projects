/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:55:49 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/14 19:56:21 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	private:
		void info(void);
		void warning(void);
		void debug(void);
		void error(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif