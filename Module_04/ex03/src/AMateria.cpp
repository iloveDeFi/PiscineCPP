/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:26 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 17:02:00 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructor by default
AMateria::AMateria(void) : type("default") {
	std::cout << "AMateria default constructor called" << std::endl;
}

// Parametric constructor
AMateria::AMateria(const std::string &type) : type(type) {
	std::cout << "AMateria parametric constructor called" << std::endl;
}

// Copy constructor 
AMateria::AMateria(const AMateria &other) : type(other.type) {
	 std::cout << "AMateria copy constructor called" << std::endl;
}

// Copy assignment operator
AMateria& AMateria::operator=(const AMateria &other) {
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

// Destructor
AMateria::~AMateria(void) {
	std::cout << "AMateria destructor called" << std::endl;
}

// Methods, setters, getters
std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "using materia on " << target.getName()
		<< " *" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < SOURCE_SIZE; i++)
	{
		if (!materia_source[i])
		{
			materia_source[i] = m;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	size_t	i;

	for (i = 0; i < SOURCE_SIZE; i++)
	{
		if (materia_source[i] && materia_source[i]->getType() == type)
			return (materia_source[i]->clone());
	}
	return (NULL);
}
