/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:16:55 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 20:02:26 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default FragTrap")
{
	_energyPoints = 100;
	_attackDamage = 30;
	_hitPoints = 100;
	std::cout << "Default FragTrap was created and ready to fight!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " was created and ready to fight!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " was destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &src)
		ClapTrap::operator=(src);
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (_energyPoints > 0 && _hitPoints > 0)
		std::cout << "FragTrap " << _name << " want's to high-five!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " can't give high-fives!" << std::endl;
}