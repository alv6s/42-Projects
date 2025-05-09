/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:16:34 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 20:03:04 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap:public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& src);
		void attack(const std::string& target);
		void guardGate();
};

#endif