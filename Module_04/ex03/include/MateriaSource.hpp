/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 08:55:31 by bbessard          #+#    #+#             */
/*   Updated: 2024/07/19 16:58:05 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	protected:
		std::string type;
		AMateria*       materias[4];
		
	public:
		MateriaSource(void);
		MateriaSource(const std::string &type);
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		virtual ~MateriaSource(void);
		
		std::string const & getType() const;
		virtual MateriaSource* clone() const = 0;
		virtual void use(ICharacter& target);
		
		virtual AMateria* createMateria(std::string const & type);
		virtual void learnMateria(AMateria *m);
};

#endif
