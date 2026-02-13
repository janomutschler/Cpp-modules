/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:18:34 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 17:12:16 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::out_of_range("easyfind: target not found");
	return (it);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int target)
{
	typename T::const_iterator	it = std::find(container.begin(), container.end(), target);
	if (it == container.end())
		throw std::out_of_range("easyfind: target not found");
	return (it);
}
