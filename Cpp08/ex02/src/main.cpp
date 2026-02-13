/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:10:08 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/09 10:34:52 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "../inc/MutantStack.hpp"

int main()
{
	std::cout << "Default Test using deque as Container" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	
	std::cout << "\nVector as Container test" << std::endl;
	MutantStack<int, std::vector<int> > vMstack;
	vMstack.push(5);
	vMstack.push(17);
	std::cout << vMstack.top() << std::endl;
	vMstack.pop();
	std::cout << vMstack.size() << std::endl;
	vMstack.push(3);
	vMstack.push(5);
	vMstack.push(737);
	vMstack.push(0);
	MutantStack<int, std::vector<int> >::iterator vIt = vMstack.begin();
	MutantStack<int, std::vector<int> >::iterator vIte = vMstack.end();
	++vIt;
	--vIt;
	while (vIt != vIte)
	{
		std::cout << *vIt << std::endl;
		++vIt;
	}
	std::stack<int, std::vector<int> > vS(vMstack);

	std::cout << "\nList test (should match output of mutant stack)" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lIt = lst.begin();
    std::list<int>::iterator lIte = lst.end();

    ++lIt;
    --lIt;

    while (lIt != lIte)
    {
        std::cout << *lIt << std::endl;
        ++lIt;
    }
	return (0);
}