/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:00:28 by tobesnar          #+#    #+#             */
/*   Updated: 2025/11/27 14:29:51 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int		i = 1;
	int		j = 0;
	char	c;

	if (argc < 2)
		return ((std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl), 1);
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			c = toupper(argv[i][j]);
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
