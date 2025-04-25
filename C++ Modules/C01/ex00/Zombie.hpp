/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:23:33 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/25 16:54:21 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iomanip>
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
		
	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void) const;
};

void randomChump(std::string name);
Zombie*  newZombie(std::string name);

#endif