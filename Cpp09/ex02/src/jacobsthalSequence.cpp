/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jacobsthalSequence.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:04:53 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 19:14:20 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static std::vector<size_t>	buildJacobsthalBoundaries(size_t k)
{
	std::vector<size_t>	b;
	if (k == 0)
		return (b);

	size_t j1 = 1;
	size_t j2 = 1;
	b.push_back(j2);

	while (b.back() < k)
	{
		size_t jn = j2 + 2 * j1;
		j1 = j2;
		j2 = jn;
		b.push_back(j2);
	}
	return (b);
}

// Produce insertion order for indices [0..k-1] following Ford–Johnson batching
std::vector<size_t>	PmergeMe::buildInsertionOrder(size_t k)
{
	std::vector<size_t>	order;
	if (k == 0)
		return (order);

	std::vector<size_t>	bounds = buildJacobsthalBoundaries(k);

	// Insert first element first
	order.push_back(0);
	size_t	prev = 1;

	for (size_t	i = 1; i < bounds.size(); ++i)
	{
		size_t	curr = bounds[i];
		if (curr > k)
			curr = k;

		for (size_t x = curr; x > prev; --x)
			order.push_back(x - 1);

		prev = bounds[i];
		if (prev > k)
			prev = k;
		if (prev == k)
			break;
	}
	return (order);
}