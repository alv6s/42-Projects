/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:59:22 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/13 17:09:26 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

humanA::humanA(const std::string name, Weapon &weapon) : _nameA(name), _weaponB(weapon) {}

humanA::~humanA() {}

void humanA::attack(void){
	std::cout << _nameA << " attacks with his " << _weaponB.getType() << std::endl;
}