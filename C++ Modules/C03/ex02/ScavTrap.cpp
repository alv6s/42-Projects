/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:16:42 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 20:02:59 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Default ScavTrap")
{
	_attackDamage = 20;
	_energyPoints = 50;
	_hitPoints = 100;
	std::cout << "Default ScavTrap " << _name << " was created and ready for the fight!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " was created and ready for the fight!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " was destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
		std::cout << "[ScavTrap " << _name << " - Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << "]" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " can't attack!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_energyPoints > 0 && _hitPoints > 0)
		std::cout << "ScavTrap " << _name << " is in Gate keeper mode!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " can't be in Gate keeper mode!" << std::endl;
}