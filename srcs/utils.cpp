/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:29 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 17:44:08 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_tank.hpp"

unsigned int numberOfDeath(std::map<unsigned int, unsigned int> & deathCounter)
{
	unsigned int counter = 0;
	for (std::pair<unsigned int, unsigned int>  pair: deathCounter)
	{
		counter += pair.second;
	}
	return counter;
}