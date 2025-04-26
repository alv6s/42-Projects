/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:59:22 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 09:09:56 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : _nameA(name), _weaponB(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack(void){
	std::cout << _nameA << " attacks with his " << _weaponB.getType() << std::endl;
}