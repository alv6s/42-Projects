/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:16:12 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/24 20:13:39 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Tests ===" << std::endl;
    ClapTrap voldemort("Voldemort");
    ClapTrap harry("Harry P.");

    voldemort.attack("Harry P.");
    harry.takeDamage(2);
    voldemort.beRepaired(2);

    std::cout << "\n=== ScavTrap Tests ===" << std::endl;
    ScavTrap sauron("Sauron");
    ScavTrap gandalf("Gandalf");

    sauron.attack("Gandalf");
    gandalf.takeDamage(2);
    sauron.beRepaired(2);
    sauron.guardGate();
    gandalf.takeDamage(200);
    gandalf.guardGate();

    std::cout << "\n=== FragTrap Tests ===" << std::endl;
    FragTrap malefica("Malefica");
    FragTrap bela("Bela Adormecida");

    malefica.attack("Bela Adormecida");
    bela.takeDamage(2);
    malefica.beRepaired(2);
    malefica.highFivesGuys();

    bela.takeDamage(200);
    bela.beRepaired(200);
    bela.highFivesGuys();

    return 0;
}