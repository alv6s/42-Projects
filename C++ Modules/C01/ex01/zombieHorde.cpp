/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:28:55 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 08:52:20 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) 
{
	Zombie *zombies = new Zombie[N];
	int	i;

	i=-1;
	while (++i < N)
		zombies[i].setName(name);
	return zombies;
}