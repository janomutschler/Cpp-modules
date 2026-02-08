/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:06:17 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/08 14:38:57 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_max;

	public:
		explicit Span(unsigned int N);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();
		
		void	addNumber(int n);
		int		shortestSpan()	const;
		int		longestSpan()	const;

		template <typename It>
		void	addNumber(It first, It last)
		{
			size_t count = std::distance(first, last);
			if (_numbers.size() + count > _max)
				throw std::out_of_range("Span is full");

			while (first != last)
			{
				addNumber(*first);
				++first;
			}
		}
};

#endif