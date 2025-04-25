/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:14:16 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 19:09:06 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap voldemort("Voldemort");
    voldemort.attack("Thanos");
    voldemort.takeDamage(3);
    voldemort.beRepaired(2);
    for (int i = 0; i < 10; i++) {
        voldemort.attack("Thanos");
    }
    voldemort.attack("Sauron");
    voldemort.takeDamage(20);
    voldemort.beRepaired(5);
    return 0;
}
