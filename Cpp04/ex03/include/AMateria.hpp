/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:21:38 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 07:31:32 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
  protected:
    std::string _type;

  public:
    AMateria();
    AMateria(const AMateria& src);
    AMateria& operator=(const AMateria& src);
    virtual ~AMateria();

    AMateria(std::string const& type);

    std::string const&	getType() const;

    virtual AMateria*	clone() const = 0;
    virtual void		use(ICharacter& target);
};

#endif
