/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbessard <bbessard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:46:48 by tblaase           #+#    #+#             */
/*   Updated: 2024/08/07 11:19:45 by bbessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int	randomNumber = (std::rand() % 3);

	if (randomNumber == 0)
		return (new A);
	else if (randomNumber == 1)
		return (new B);
	else if (randomNumber == 2)
		return (new C);
	return (new A);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer to A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer to B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer to C" << std::endl;
	else if (p == NULL)
		std::cout << "Pointer is NULL" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Reference to A" << std::endl;
		return;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Reference to B" << std::endl;
		return;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Reference to C" << std::endl;
		return;
	}
	catch (std::bad_cast &bc)
	{
	}
}

int	main(void)
{
	Base	*newBase;
	newBase = generate();
	identify(newBase);
	identify(*newBase);
	delete newBase;
	return (0);
}