/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:36:43 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 19:01:13 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"
#include <algorithm>
#include <stdexcept>


static void	insert(std::vector<Node>& sorted, const Node& x, const Node& bound)
{
	size_t	pos = 0;
	while (pos < sorted.size())
	{
		if (sorted[pos].id == bound.id)
			break;
		++pos;
	}
	if (pos == sorted.size())
    	throw std::runtime_error("Error");
	
	std::vector<Node>::iterator it =
		std::lower_bound(sorted.begin(), sorted.begin() + static_cast<std::ptrdiff_t>(pos), x, ordered);
	sorted.insert(it, x);
}

static void	reorderSmallSet(const std::vector<Node>& sorted, std::vector<SmallNode>& smallSet)
{
	std::vector<SmallNode> temp = smallSet;
	for (size_t	i = 0; i < sorted.size(); ++i)
	{
		for (size_t	j = 0; j < temp.size(); ++j)
		{
			if (sorted[i].id == temp[j].bound.id)
			{
				smallSet[i] = temp[j];
				break ;
			}
		}
	}
}

static std::vector<Node>	fordJohnsonVector(std::vector<Node> input)
{
	const size_t n = input.size();
	if ( n <= 1)
		return (input);
	
	std::vector<Node>		largeSet;
	largeSet.reserve(input.size() / 2);
	std::vector<SmallNode>	smallSet;
	smallSet.reserve(input.size() / 2);

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		Node	small = input[i];
		Node	large = input[i + 1];
		if (!ordered(small, large))
			swap(small, large);

		largeSet.push_back(large); //safe large node in largeSet which we gonna solve with recursion 
		SmallNode	temp;
		temp.node = small; //safe small node with its corresponding large bound to insert it later efficently
		temp.bound = large;
		smallSet.push_back(temp);
	}

	Node	leftover;
	bool	hasLeftover = (n % 2 == 1);
	if (hasLeftover)
		leftover = input[n - 1];
	
	std::vector<Node>	sorted = fordJohnsonVector(largeSet);
	reorderSmallSet(sorted, smallSet);
	
	const size_t		k = smallSet.size();
	std::vector<size_t>	order = PmergeMe::buildInsertionOrder(k);
	
	for (size_t i = 0; i < order.size(); ++	i)
	{ 
		SmallNode	temp = smallSet[order[i]];
		insert(sorted, temp.node, temp.bound);
	}
	if (hasLeftover)
	{
		std::vector<Node>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), leftover, ordered);
		sorted.insert(it, leftover);
	}
	
	return (sorted);
}

void	PmergeMe::sortVector()
{
	std::vector<Node> nodes;
	nodes.reserve(_vec.size());
	for (size_t i = 0; i < _vec.size(); ++i)
		nodes.push_back(Node(_vec[i], static_cast<int>(i)));

	std::vector<Node> sorted = fordJohnsonVector(nodes);
	
	for (size_t i = 0; i < sorted.size(); ++i)
		_vec[i] = sorted[i].value;
}