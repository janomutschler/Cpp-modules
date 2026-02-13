/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterPriv.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:45:30 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/04 21:56:05 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTERPRIV_HPP
#define SCALARCONVERTERPRIV_HPP

#include <string>

enum eType {
    T_INVALID,
    T_CHAR,
    T_INT,
    T_FLOAT,
    T_DOUBLE,
    T_PSEUDO_FLOAT,
    T_PSEUDO_DOUBLE
};

eType	detectType(const std::string& s);
void	convertType(const std::string& s, eType t);

#endif
