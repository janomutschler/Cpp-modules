/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:37:17 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 19:04:24 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"
#include <algorithm>
#include <stdexcept>

static void	insert(std::deque<Node>& sorted, const Node& x, const Node& bound)
{
	size_t pos = 0;
	while (pos < sorted.size())
	{
		if (sorted[pos].id == bound.id)
			break;
		++pos;
	}
	if (pos == sorted.size())
    	throw std::runtime_error("Error");

	std::deque<Node>::iterator it =
		std::lower_bound(sorted.begin(), sorted.begin() + static_cast<std::ptrdiff_t>(pos), x, ordered);
	sorted.insert(it, x);
}

static void	reorderSmallSet(const std::deque<Node>& sorted, std::deque<SmallNode>& smallSet)
{
	std::deque<SmallNode> temp = smallSet;

	for (size_t i = 0; i < smallSet.size(); ++i)
	{
		for (size_t j = 0; j < temp.size(); ++j)
		{
			if (sorted[i].id == temp[j].bound.id)
			{
				smallSet[i] = temp[j];
				break;
			}
		}
	}
}

static std::deque<Node>	fordJohnsonDeque(std::deque<Node> input)
{
	const size_t n = input.size();
	if (n <= 1)
		return input;

	std::deque<Node>       largeSet;
	std::deque<SmallNode>  smallSet;

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		Node	small = input[i];
		Node	large = input[i + 1];
		if (!ordered(small, large))
			swap(small, large);

		largeSet.push_back(large);
		SmallNode tmp;
		tmp.node = small;
		tmp.bound = large;
		smallSet.push_back(tmp);
	}

	Node	leftover;
	bool	hasLeftover = (n % 2 == 1);
	if (hasLeftover)
		leftover = input[n - 1];

	std::deque<Node> sorted = fordJohnsonDeque(largeSet);
	reorderSmallSet(sorted, smallSet);

	const size_t k = smallSet.size();
	std::vector<size_t> order = PmergeMe::buildInsertionOrder(k);

	for (size_t i = 0; i < order.size(); ++i)
	{
		SmallNode tmp = smallSet[order[i]];
		insert(sorted, tmp.node, tmp.bound);
	}

	if (hasLeftover)
	{
		std::deque<Node>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), leftover, ordered);
		sorted.insert(it, leftover);
	}
	return sorted;
}

void	PmergeMe::sortDeque()
{
	std::deque<Node> nodes;
	for (size_t i = 0; i < _deq.size(); ++i)
		nodes.push_back(Node(_deq[i], static_cast<int>(i)));

	std::deque<Node> sorted = fordJohnsonDeque(nodes);

	for (size_t i = 0; i < sorted.size(); ++i)
		_deq[i] = sorted[i].value;
}
