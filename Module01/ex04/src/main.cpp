/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:00:11 by hemera            #+#    #+#             */
/*   Updated: 2025/12/12 14:24:16 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

void ft_error(const std::string& msg)
{
	std::cerr << "Error: " << msg << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	if (s1.empty())
	{
		ft_error("s1 cannot be empty");
		return 1;
	}
	std::string s2 = av[3];

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		ft_error("Could not open file");
		return 1;
	}

	std::string fileContent;
	std::string line;
	while (std::getline(inputFile, line))
	{
		fileContent += line;
		if (!inputFile.eof())
			fileContent += "\n";
	}
	inputFile.close();

	std::string result;
	size_t pos = 0;
	size_t found = fileContent.find(s1, pos);

	while (found != std::string::npos)
	{
		result += fileContent.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
		found = fileContent.find(s1, pos);
	}
	result += fileContent.substr(pos);

	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		ft_error("Could not create output file");
		return 1;
	}
	outputFile << result;
	outputFile.close();

	return 0;
}
