/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:44:36 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/18 08:07:44 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Exercise purpose = Understand Deep Copy Vs Shallow Copy
// Dog and Cat copies must be Deep Copies

void testDeepCopy() {
    Dog originalDog;
    Dog copiedDog(originalDog); // Utilise le constructeur de copie
    Dog assignedDog;
    assignedDog = originalDog; // Utilise l'opérateur d'affectation

    // Modifiez les données dans l'original et assurez-vous que les copies ne sont pas affectées
    originalDog.makeSound();
    copiedDog.makeSound();
    assignedDog.makeSound();
}

void testShallowCopy() {
    Brain originalBrain;
    Brain shallowCopiedBrain = originalBrain; // Utilise le constructeur de copie superficiel
    Brain shallowAssignedBrain;
    shallowAssignedBrain = originalBrain; // Utilise l'opérateur d'affectation superficiel

    // Modifiez les données dans l'original et vérifiez que les copies sont affectées (ce qui ne devrait pas être le cas)
    *originalBrain.ideas = "Changed idea";

    std::cout << "Original Brain idea: " << *originalBrain.ideas << std::endl;
    std::cout << "Shallow Copied Brain idea: " << *shallowCopiedBrain.ideas << std::endl;
    std::cout << "Shallow Assigned Brain idea: " << *shallowAssignedBrain.ideas << std::endl;
}

void testMemoryLeaks() {
    // Use tools to detect memory leaks
    Dog* dog = new Dog();
    delete dog;

    Cat* cat = new Cat();
    delete cat;
}

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
	
	delete meta;
	delete j;
	delete i;
	
	std::cout << "--------------WRONG CASE----------------" << std::endl;
	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* iWrong = new WrongCat();

	std::cout << iWrong->getType() << " " << std::endl;
	
	iWrong->makeSound(); // will NOT output the cat sound!
	metaWrong->makeSound();

	delete metaWrong;
	delete iWrong;
	
	std::cout << "--------------DEEP COPY TEST----------------" << std::endl;
    testDeepCopy();

    std::cout << "--------------SHALLOW COPY TEST----------------" << std::endl;
    testShallowCopy();

    std::cout << "--------------MEMORY LEAK TEST----------------" << std::endl;
    testMemoryLeaks();
	
	return (0);

}
