/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:03:34 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 23:02:39 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

// Constructor by default
MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_materias[i] = 0;
	}
}

// Copy constructor 
MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < 4; i++)
	{
		// Deep copy
		if (other._materias[i])
			this->_materias[i] = (other._materias[i])->clone();
	}
	 std::cout << "MateriaSource copy constructor called" << std::endl;
}

// Copy assignement operator
MateriaSource & MateriaSource::operator=(MateriaSource const & ref)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		if (ref._materias[i])
			this->_materias[i] = (ref._materias[i])->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	std::cout << "Materia source was destoryed\n";
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	while ((this->_materias)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "Can't learn more than 4 Materia";
		return ;
	}
	(this->_materias)[i] = m;
	std::cout << "Materia " << m->getType() << " learned\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while ((this->_materias)[i] && ((this->_materias)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->_materias)[i])
	{
		std::cout << type << " materia does not exit\n";
		return (NULL);
	}
	std::cout << "Materia " << type << " created\n";
	return (((this->_materias)[i])->clone());
}
