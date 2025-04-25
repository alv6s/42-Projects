/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:14:54 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 19:47:31 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap voldemort("Voldemort");
	ScavTrap thor("Thor");
	ScavTrap voldemort2(voldemort);
	ScavTrap thor2 = thor;

	voldemort.attack("Thor");
	voldemort.takeDamage(3);
	voldemort.beRepaired(2);
	thor.attack("Voldemort");
	thor.takeDamage(100);
	
	thor.guardGate();
	voldemort2.guardGate();
	thor2.guardGate();
	return (0);
}