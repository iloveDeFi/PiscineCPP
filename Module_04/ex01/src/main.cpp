/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:44:36 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/17 13:58:51 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Exercise purpose = Deep Copy Vs Shallow Copy
// Dog and Cat copies must be Deep Copies

int main() {
	std::cout << "--------------COPY CASE----------------" << std::endl;
	const int totalAnimal = 10;
	Animal* animals[totalAnimal];
	
    for (int i = 0; i < totalAnimal / 2; ++i) {
        animals[i] = new Dog();
    }
	
    for (int i = totalAnimal / 2; i < totalAnimal; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < totalAnimal; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < totalAnimal; ++i) {
        delete animals[i];
    }
	
	std::cout << "--------------TRUE CASE----------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << "--------------WRONG CASE----------------" << std::endl;
	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* iWrong = new WrongCat();

	std::cout << iWrong->getType() << " " << std::endl;
	
	iWrong->makeSound(); // will NOT output the cat sound!
	metaWrong->makeSound();
	
	delete meta;
	delete j;
	delete i;
	
	return (0);

}
