/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:59:41 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 09:10:12 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _nameB(name) { _weaponB = NULL; }

HumanB::~HumanB() {}

void HumanB::attack(void){
	if (_weaponB == NULL)
		std::cout << _nameB << " has no weapon" << std::endl;
	else
		std::cout << _nameB << " attacks with his " << _weaponB->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
	_weaponB = &weapon;
}