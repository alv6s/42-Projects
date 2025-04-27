/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:48:52 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/27 19:13:58 by pevieira         ###   ########.fr       */
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
   
	
	// Teste básico de construção e destruição
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	delete dog;
	delete cat;
	
	std::string	listIdeas[4] = { "I need FOOD!", "Zzz... So sleepy...", "Woohoo I love it!", "I think therefore I am" };
	std::cout << "THE ANIMALS" << std::endl;

	// Array de animais
	const Animal* animals[4];
	for (int i = 0; i < 2; ++i) {
		animals[i] = new Dog();
	}
	for (int i = 2; i < 4; ++i) {
		animals[i] = new Cat();
	}

	for (int i = 0; i < 4; ++i) {
		delete animals[i];
	}

	std::cout << "---- Deep Copy Test ----" << std::endl;

	Dog dog1;
	dog1.getBrain()->setIdea(25, listIdeas[0]);
	dog1.getBrain()->setIdea(67, listIdeas[1]);


	Dog dog2 = dog1;
	dog2.getBrain()->setIdea(0, "Eat the food!");

	Cat cat1;
	cat1.getBrain()->setIdea(0, "Chase the mouse!");

	Cat cat2 = cat1;
	cat2.getBrain()->setIdea(0, "Eat the fish!");

	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;

    return 0;
}


