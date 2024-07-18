/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:27:55 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 11:53:02 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "--------------TEST CASE----------------" << std::endl;

	const int totalAnimals = 10;
    Animal *animals[totalAnimals];

    for (int i = 0; i < totalAnimals / 2; ++i) {
        animals[i] = new Dog();
    }

    for (int i = totalAnimals / 2; i < totalAnimals; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < totalAnimals; ++i) {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    for (int i = 0; i < totalAnimals; ++i) {
        delete animals[i];
    }

    return 0;
	
	std::cout << "--------------TRUE CASE----------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	// std::cout << "--------------WRONG CASE----------------" << std::endl;
	// const WrongAnimal* metaWrong = new WrongAnimal();
	// const WrongAnimal* iWrong = new WrongCat();

	// std::cout << metaWrong->getType() << " " << std::endl;
	// std::cout << iWrong->getType() << " " << std::endl;
	
	// iWrong->makeSound(); // will NOT output the cat sound!
	// metaWrong->makeSound();
	
	return (0);

}