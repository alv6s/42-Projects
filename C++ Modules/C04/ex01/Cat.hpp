/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:43 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/27 16:57:48 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat:public Animal
{
	public:
		Cat(void);
		Cat(const Cat &src);
		~Cat(void);
		
		Cat &operator=(const Cat &src);
		
		void makeSound(void) const;
};

#endif