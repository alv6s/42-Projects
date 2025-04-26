/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:53:59 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 09:09:33 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
private:
    std::string _nameA;
    Weapon& _weaponB;

public:
    HumanA(std::string name, Weapon &weapon);
	~HumanA();
    void attack(void);
};

#endif
