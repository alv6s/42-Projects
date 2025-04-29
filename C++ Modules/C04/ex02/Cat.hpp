/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:43 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/29 18:35:27 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat:public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(const Cat &src);
		~Cat(void);
		
		Cat &operator=(const Cat &src);
		
		Brain*	getBrain(void) const;
		void makeSound(void) const;
};

#endif

