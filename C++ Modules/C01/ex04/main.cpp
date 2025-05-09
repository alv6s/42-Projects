/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pevieira <pevieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:17:40 by pevieira          #+#    #+#             */
/*   Updated: 2025/04/26 15:21:39 by pevieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

int	replace_s1_s2(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::string line;
	size_t	i;
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return (1);
	}
	std::ofstream outFile((filename + ".replace").c_str()); 
	if (!outFile.is_open())
	{
		std::cerr << "Error creating replace file!" << std::endl;
		return (1);
	}
	while (std::getline(inFile, line))
    {
		i = 0;
        while ((i = line.find(s1, i)) != std::string::npos)
        {
            std::string before = line.substr(0, i);
            std::string after = line.substr(i + s1.length());
            line = "";
            line.append(before);
            line.append(s2);
            line.append(after);
            i += s2.length();
        }
        outFile << line << std::endl;
    }
	outFile.close();
	inFile.close();
	return (0);
}
void		argumentsValidation(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "ERROR: Please use as follows\n " << "./sed <filename> <s1> <s2>" << std::endl;
		exit (1);
	}
	std::string		s1 = av[2];
	if (s1.empty())
	{
		std::cout << "ERROR: The String to find is empty" << std::endl;
		exit(1);
	}
}

int main(int ac, char **av)
{
	argumentsValidation(ac, av);
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (replace_s1_s2(filename, s1, s2))
		return (1);
	return (0);
}

