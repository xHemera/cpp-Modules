/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:26:30 by hemera            #+#    #+#             */
/*   Updated: 2026/01/21 17:31:30 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

int main()
{
	FragTrap frag("FR4G-TP");

	frag.attack("Target Dummy");
	frag.takeDamage(5);
	frag.beRepaired(3);
	frag.highFivesGuys();
	frag.takeDamage(10);
	frag.beRepaired(5);
	frag.attack("Another Target");
	return 0;

}
