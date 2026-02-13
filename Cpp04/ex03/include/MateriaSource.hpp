/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:39:00 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 11:20:18 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  private:
    AMateria* _learned[4];

    void _clearLearned();
    void _copyLearned(const MateriaSource& src);

  public:
    MateriaSource();
    MateriaSource(const MateriaSource& src);
    MateriaSource& operator=(const MateriaSource& src);
    virtual ~MateriaSource();

    virtual void      learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const& type);
};

#endif
