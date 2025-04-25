/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:59:41 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/13 17:16:35 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

humanB::humanB(std::string name) : _nameB(name) { _weaponB = NULL; }

humanB::~humanB() {}

void humanB::attack(void){
	if (_weaponB == NULL)
		std::cout << _nameB << " has no weapon" << std::endl;
	else
		std::cout << _nameB << " attacks with his " << _weaponB->getType() << std::endl;
}

void humanB::setWeapon(Weapon &weapon){
	_weaponB = &weapon;
}