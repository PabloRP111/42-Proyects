/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:54:40 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/16 09:56:08 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME
#define PMERGEME

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <ctime>

class PMergeMe
{
	public:
		template <typename Container>
		void reorderPend(Container &pend, Container &pend_pos_ax, int level);

		template <typename Container>
		void binaryInsert(Container &pend, Container &main, Container &pend_pos_ax, int level);

		template <typename Container>
		Container getSecuencies(Container &main, Container &pend_pos_ax, int level);
		
		template <typename Container>
		void sortJacobsthal(Container &c, int level);

		template <typename Container>
		void sortPairs(Container &c, int level, bool descend);

		template <typename Container>
		void	fordJohnson(Container &c, std::string nameColl);

		PMergeMe();
		PMergeMe(PMergeMe &pm);
		~PMergeMe();
		PMergeMe &operator=(const PMergeMe &pm);
};

#include "PMergeMe.tpp"

#endif
