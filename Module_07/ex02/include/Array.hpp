/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bat <bat@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:06:52 by bat               #+#    #+#             */
/*   Updated: 2024/07/31 17:17:07 by bat              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

class Array {
    private:
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array& operator=(const Array &src);
        ~Array();

        T arraySize() const;
};

#endif