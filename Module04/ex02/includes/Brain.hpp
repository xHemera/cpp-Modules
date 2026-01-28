/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemera <hemera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:43:59 by hemera            #+#    #+#             */
/*   Updated: 2026/01/22 19:46:35 by hemera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
   private:
	std::string ideas[100];

   public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &assign);
	~Brain();
};

#endif
