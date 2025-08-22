/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:36:46 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/22 13:05:44 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FtReplace.hpp"

static int	checkInvalidInput(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
		return (1);
	}
	const std::string	s1 = argv[2];
	if (s1.empty())
	{
		std::cerr << "Invalid Input: s1 cant be empty\n";
		return (1);
	}
	return (0);
}
int main(int argc, char** argv)
{
	if (checkInvalidInput(argc, argv))
		return (1);

	const std::string	filename = argv[1];
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];

	std::ifstream in(filename.c_str());
    if (!in) 
	{
        std::cerr << "Error: cannot open input file '" << filename << "'.\n";
        return 3;
    }

    const std::string outFilename = filename + ".replace";
    std::ofstream out(outFilename.c_str());
    if (!out) 
	{
        std::cerr << "Error: cannot create output file '" << outFilename << "'.\n";
        return 1;
    }

	std::string	line;
	int			first = 1;
	while (std::getline(in, line))
	{
		if (!first)
			out << '\n';
		first = 0;
		out << ftReplace(line, s1, s2);
	}
	return (0);
}
