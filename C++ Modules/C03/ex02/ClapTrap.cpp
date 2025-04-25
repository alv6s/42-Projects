/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:15:57 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 20:02:39 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _energyPoints(10), _attackDamage(0), _hitPoints(10)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _energyPoints(10), _attackDamage(0), _hitPoints(10)
{
		std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
		_hitPoints = src._hitPoints;
	}
	return (*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		if (_hitPoints <= amount)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		std::cout << "[ClapTrap " << _name << " - Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << "]" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already down and cannot take more damage!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
		std::cout << "[ClapTrap " << _name << " - Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << "]" << std::endl;
	}
	else	
		std::cout << "ClapTrap " << _name << " can't attack!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "[ClapTrap " << _name << " - Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << "]" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " can't be repaired!" << std::endl;
}
