/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 12:32:05 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/02 08:18:35 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        // Constructors
        MutantStack() : std::stack<T>() { }
        MutantStack(const MutantStack<T> &ms) : std::stack<T>(ms) { }

        // Assignment operator
        MutantStack<T> &operator=(const MutantStack<T> &ms)
        {
            if (this != &ms)
                std::stack<T>::operator=(ms);
            return *this;
        }

        // Destructor
        ~MutantStack() { }

        // Iterator typedef
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        // Begin and End
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }

        const_iterator begin() const { return this->c.begin(); }
        const_iterator end()   const { return this->c.end(); }
};

#endif
