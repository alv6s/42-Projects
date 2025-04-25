/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:54:37 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/13 17:16:52 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class humanB {
private:
    std::string _nameB;
    Weapon* _weaponB;

public:
    humanB(std::string name);
	~humanB();
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif
