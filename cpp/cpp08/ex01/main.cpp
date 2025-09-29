/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:17:53 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/02 08:01:58 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void randomAdd(int n, Span &sp) {
    std::vector<int> pool;
    for (int i = 0; i < n; i++)
        pool.push_back(i);

    std::srand(std::time(NULL));
    std::random_shuffle(pool.begin(), pool.end());

    for (int i = 0; i < n; i++)
        sp.addNumber(pool[i]);
}

int main() {
    try {
        std::cout << "===== Test 1: ejemplo básico =====" << std::endl;
        Span sp1 = Span(5);
        sp1.addNumber(6);
        sp1.addNumber(3);
        sp1.addNumber(17);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

        std::cout << std::endl << "===== Test 2: 10,000 números aleatorios =====" << std::endl;
        Span sp2 = Span(10000);
        randomAdd(10000, sp2);
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Excepción catched: " << e.what() << std::endl;
    }

    Span sp3 = Span(1);
    try
    {
        sp3.addNumber(42);
        std::cout << std::endl << "===== Test 3: excepción por pocos números =====" << std::endl;
        std::cout << sp3.shortestSpan() << std::endl; // Should throw an exception
    }
    catch(const std::exception& e)
    {
        std::cerr << "Excepción capturada: " << e.what() << '\n';
    }
    std::cout << std::endl << "===== Test 4: excepción por exceso de capacidad =====" << std::endl;
    try
    {
        sp3.addNumber(5);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Excepción capturada: " << e.what() << '\n';
    }
    return 0;
}
