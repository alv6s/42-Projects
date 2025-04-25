/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:53:59 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/13 17:09:56 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class humanA {
private:
    std::string _nameA;
    Weapon& _weaponB;

public:
    humanA(std::string name, Weapon &weapon);
	~humanA();
    void attack(void);
};

#endif
