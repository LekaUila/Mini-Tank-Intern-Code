/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ComSysteme.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:40:49 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/29 10:48:28 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/ComSysteme.hpp"

ComSysteme::ComSysteme(unsigned int i)
{
	this->id = i;
	this->connection_status = DISCONNECTED;
	this->failed_try = 0;
}

ComSysteme::~ComSysteme()
{

}


/*getter*/

unsigned int	ComSysteme::getId()
{
	return this->id;
}

int				ComSysteme::getStatus()
{
	return this->connection_status;

}

int				ComSysteme::getFailedTry()
{
	return this->failed_try;
}



	
/*setter*/


/*methode*/


