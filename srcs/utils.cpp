/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:29 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/28 15:53:13 by lflandri         ###   ########.fr       */
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


    /*------------------------------------------------------------------------------
    Retourne l'image d'un point par une rotation (repère X de gauche à droite, Y du
    haut vers le bas).
    ENTREE :
        M        Point à transformer
        O        Point centre de la rotation
        angle    Angle (en degrés)
    SORTIE :
        Image de M par la rotation d'angle angle autour de O (les coordonnées ne
        sont pas entières).
    ------------------------------------------------------------------------------*/

t_point rotate(t_point & M, t_point & O, float angle)
{
	t_point tmp;
	t_point new_M;
	float radiant_angle = angle * (M_PI / 180);
	tmp.x = M.x - O.x;
	tmp.y = M.y - O.y;
	new_M.x = tmp.x * cos (radiant_angle) + tmp.y * sin (radiant_angle) + O.x;
	new_M.y = - tmp.x * sin (radiant_angle) + tmp.y * cos (radiant_angle) + O.y;
	return new_M;
}