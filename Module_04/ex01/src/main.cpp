/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:27:55 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 13:40:20 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "-------------CREATE 5 DOGS--------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	const int totalAnimals = 10;
    Animal *animals[totalAnimals];

    for (int i = 0; i < totalAnimals / 2; ++i) {
        animals[i] = new Dog();
    }

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "-------------CREATE 5 CATS--------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
    for (int i = totalAnimals / 2; i < totalAnimals; ++i) {
        animals[i] = new Cat();
    }

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "-------------TYPE && SOUND--------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < totalAnimals; ++i) {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }
	
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "-------------DELETING ANIMALS-----------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
    for (int i = 0; i < totalAnimals; ++i) {
        delete animals[i];
    }
	
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "--------------TRUE CASE----------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "--------------MORE CASES----------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	const int Munch = 6;
    Animal *monster[Munch];

    // Create dogs and cats
    monster[0] = new Dog();
    monster[1] = new Dog("Bulldog");
    monster[2] = new Cat();
    monster[3] = new Cat("Persian");
    
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "--COPY CONSTRUCTOR && COPY ASSIGNEMENT--" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	monster[4] = new Dog(*dynamic_cast<Dog*>(monster[1])); // Copy Bulldog
    monster[5] = new Cat(*dynamic_cast<Cat*>(monster[3])); // Copy Persian

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "-------------TYPE && SOUND--------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

    // Display types and sounds
    for (int i = 0; i < Munch; ++i) {
        std::cout << monster[i]->getType() << std::endl;
        monster[i]->makeSound();
    }

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "---------------DELETE ALL---------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

    for (int i = 0; i < Munch; ++i) {
        delete monster[i];
    }
	
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "--------------WRONG CASE----------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* iWrong = new WrongCat();

	std::cout << metaWrong->getType() << " " << std::endl;
	std::cout << iWrong->getType() << " " << std::endl;
	
	iWrong->makeSound(); // will NOT output the cat sound!
	metaWrong->makeSound();
	
	return (0);

}