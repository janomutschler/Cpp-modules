/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:44:36 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 18:47:18 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

struct Node {
    int value;
    int id;

	Node() : value(0), id(0) {}
	Node(int v, int i) : value(v), id(i) {}
};

struct SmallNode {
	Node	node;
	Node	bound;
};
		
bool	ordered(const Node& lhs, const Node& rhs);
void	swap(Node& a, Node& b);
		
#endif