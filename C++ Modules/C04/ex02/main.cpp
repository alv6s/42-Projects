/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:52 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/27 19:16:15 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iomanip>

int main()
{
	const Animal* dog = new Dog();
    const Animal* cat = new Cat();

	dog->makeSound();
	cat->makeSound();

    delete dog;
    delete cat;
	
	return 0;
}