/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:58:25 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 18:51:33 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>

// Main class driving the program
class PmergeMe
{
	private:
		// Input containers
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		double				_vecTime;
		double				_deqTime;

		//parseing.cpp
		void	parseInput(int argc, char** argv);

		// Sorting (separate implementations, as recommended)
		void	sortVector();
		void	sortDeque();

		
		// utils.cpp
		void	printBefore() const;
		void	printAfter() const;
		double	getTimeDiff(clock_t start, clock_t end) const;

	public:
		PmergeMe();
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
		~PmergeMe();

		void	run();

		static std::vector<size_t>	buildInsertionOrder(size_t k);
};

#endif
