/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:26:30 by hemera            #+#    #+#             */
/*   Updated: 2026/01/19 21:39:14 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
	ScavTrap scav("SC4V-TP");

	scav.attack("Target Dummy");
	scav.takeDamage(5);
	scav.beRepaired(3);
	scav.guardGate();
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.attack("Another Target");
	return 0;

}
