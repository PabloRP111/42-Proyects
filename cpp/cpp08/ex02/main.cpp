/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:17:53 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/02 08:21:21 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "Test con MutantStack:" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(42);

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "MutantStack top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "MutantStack top: " << mstack.top() << std::endl;
    std::cout << "MutantStack size: " << mstack.size() << std::endl;


    std::stack<int> s(mstack);

    std::cout << "\nTest con std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(42);

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    const MutantStack<int> cms(mstack);
    std::cout << "Const iteration:" << std::endl;
    for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
