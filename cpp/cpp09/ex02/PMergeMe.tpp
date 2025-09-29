/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:40:08 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/18 08:13:00 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

//Reorder pend using jacobsthals numbers
template <typename Container>
void PMergeMe::reorderPend(Container &pend, Container &pend_pos_ax, int level)
{
    int numBlocks = pend.size() / level;
    if (numBlocks == 0)
		return ;

    int M = numBlocks + 1; // theorical numbers of elements including B1

    // 1) Build Jacobsthal secuency J until fill M
    std::vector<int> J;
    J.push_back(0);
    J.push_back(1);
    while (J.back() < M) {
        int next = J[J.size() - 1] + 2 * J[J.size() - 2];
        if (next > M)
			next = M;
        J.push_back(next);
    }

    // 2) traverse segments(J[t-1], J[t]] 
    Container out_pend;
    Container out_pend_pos;

    for (size_t t = 1; t < J.size(); ++t) {
        int start = J[t - 1] + 1; // frist k on this segment
        int end   = J[t];      // last k on this segment

        // move from right to left
        for (int k = end; k >= start; --k) {
            if (k < 2)
				continue ; // B1 doesnt exist in the pend

            int pendIndex = k - 2; // translate to pend index
            if (pendIndex < 0 || pendIndex >= numBlocks)
				continue ;

            int base = pendIndex * level; // begining of the element in the pend
            for (int j = 0; j < level && base + j < (int)pend.size(); ++j) {
                out_pend.push_back(pend[base + j]);
            }
            out_pend_pos.push_back(pend_pos_ax[pendIndex]);
        }
    }

    // 3) Replace
    pend = out_pend;
    pend_pos_ax = out_pend_pos;
}

// Insert pend in the main using or not jacobsthal numbers
template <typename Container>
void	PMergeMe::binaryInsert(Container &pend, Container &main, Container &pend_pos_ax, int level)
{
	reorderPend(pend, pend_pos_ax, level);
	for (size_t i = 0; i < pend_pos_ax.size(); i++) //look pend_pos_ax pos
	{
		int value = pend[(i * level) + (level - 1)];
		int right = pend_pos_ax[i] / level;
		int left = 0;

		while (left < right)
		{
			int mid = left + (right - left) / 2;
			int mainAi = main[(mid * level) + (level - 1)];
			if (value < mainAi)
				right = mid;
			else
				left = mid + 1;
		}

		int insert_pos = left * level;
		main.insert( //insert
			main.begin() + insert_pos,
			pend.begin() + (i * level),
			pend.begin() + (i * level) + level
		);
		for (int z = 0; z < static_cast<int>(pend_pos_ax.size()); z++) //update pend_pos_ax
		{
			if (pend_pos_ax[z] > insert_pos)
				pend_pos_ax[z] += level;
		}
	}
}

// Usally in the conditions that i put "-1", it´s because i need to treat that
// that operator as his position in the array, when i don´t put it its becauses
// i need to treat as his literal value
template <typename Container>
Container PMergeMe::getSecuencies(Container &main, Container &pend_pos_ax, int level) //c == main
{
	Container indeterminate;
	Container index_element_del;
	bool push;

	int sub_range = 1;
	for (int i = 0; i < static_cast<int>(main.size()); i++)
	{
		push = false;
		if (i == level)
			sub_range++;
		if (i > level && i % level == 0)
			sub_range++;
		if (sub_range > static_cast<int>(main.size()) / level)
			break;
		if (i >= level * 2 && sub_range % 2 != 0)
		{
			push = true;
			if (sub_range < static_cast<int>(main.size()) / level) //if next sub_range exits
			{
				if (main[(sub_range * level) - 1] > main[((sub_range - 1) * level) - 1] //element bigger than previus element
					&& main[(sub_range * level) - 1] < main[((sub_range + 1) * level) - 1]) //element smaller than next element
					push = false;
			}
			else if (sub_range == static_cast<int>(main.size()) / level
				&& main[(sub_range * level) - 1] > main[((sub_range - 1) * level) - 1])
			{
				push = false;
			}
		}
		if (push)
		{
			if (pend_pos_ax.empty())
				pend_pos_ax.push_back((sub_range * level) - level);
			else if (pend_pos_ax.back() != (sub_range * level) - level)
				pend_pos_ax.push_back((sub_range * level) - level);
			indeterminate.push_back(main[i]);

			if ((i + 1) % level == 0)
				index_element_del.push_back(i);
		}
	}
	for (size_t i = 0; i < index_element_del.size(); i++)
	{
		for (size_t j = index_element_del[i]; j > index_element_del[i] - static_cast<size_t>(level); j--) { //Delete this bx of main
			main.erase(main.begin() + j);
		}
		for (size_t j = 0; j < pend_pos_ax.size(); j++) { //Update the pend_ax_pos because main has change him longitude
			if (pend_pos_ax[j] > index_element_del[i])
				pend_pos_ax[j] -= level;
		}
		for (size_t j = i; j < index_element_del.size(); j++)
		{
			if (index_element_del[i] < index_element_del[j])
				index_element_del[j] -= level;
		}
	}
	return indeterminate;
}

//join functions and control the program flow
template <typename Container>
void PMergeMe::sortJacobsthal(Container &c, int level)
{
	Container pend_pos_ax;
	Container pend = getSecuencies(c, pend_pos_ax, level);
	if (!pend.empty())
		binaryInsert(pend, c, pend_pos_ax, level);
	if (level > 1)
		sortJacobsthal(c, level / 2);
}

template <typename Container>
void PMergeMe::sortPairs(Container &c, int level, bool descend)
{
	Container ax;
	Container bx;

	for (int i = 0; i < static_cast<int>(c.size()); i++)
	{
		if ((i + 1) % (level) == 0)
		{
			if (ax.empty())
			{
				for (int j = i + 1 - level; j <= i; j++) {
					ax.push_back(c[j]);
				}
			}
			else {
				for (int j = i + 1 - level; j <= i; j++) {
					bx.push_back(c[j]);
				}
				if (ax.back() > bx.back())
				{
					for (int j = (i + 1) - (level * 2); j <= i - level; j++)
					{
						c[j] = bx.front();
						bx.erase(bx.begin());
					}
					for (int j = i + 1 - level; j <= i; j++)
					{
						c[j] = ax.front();
						ax.erase(ax.begin());
					}
				}
				bx.clear();
				ax.clear();
			}
		}
	}
	if (((static_cast<int>(c.size()) / 2) >= (level * 2) ) && descend)
		sortPairs(c, level * 2, true); // down
	else
		descend = false;
	if (level > 1 && !descend)
	{
		/*std::cout << " semi-sorted: ";
		for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl << std::endl;*/
		sortJacobsthal(c, level); // up
	}
}

template <typename Container>
void	PMergeMe::fordJohnson(Container &c, std::string nameColl)
{
	double elapsed;

	std::cout << std::endl << nameColl << " Before: ";
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	clock_t start = clock();
	if (c.size() >= 2)
		sortPairs(c, 1, true);
	clock_t end = clock();
	elapsed = double(end - start) / CLOCKS_PER_SEC; //secs
	double elapsed_us = elapsed * 1e6; // microsecs

	std::cout << nameColl << " After: ";
	for (typename Container::iterator it = c.begin(); it != c.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " <<  c.size()
		<< " elements with std::" << nameColl << " " << elapsed_us << " us, " << elapsed << " s" << std::endl << std::endl;
}

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(PMergeMe &pm) {
	*this = pm;
}

PMergeMe::~PMergeMe() {}

PMergeMe &PMergeMe::operator=(const PMergeMe &pm)
{
	if (this != &pm)
		*this = pm;
	return *this;
}
