/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:40:49 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 17:06:00 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/Tank.hpp"

Tank::Tank(/* args */)
{
	this->armorBack = STAT_TANK_ARMOR_BACK;
	this->armorFront = STAT_TANK_ARMOR_FRONT;
	this->armorLeft = STAT_TANK_ARMOR_SIDE;
	this->armorRight = STAT_TANK_ARMOR_SIDE;
	this->hp = STAT_TANK_LIFE;
	this->caterpillarLeftClock = sf::Clock();
	this->caterpillarRightClock = sf::Clock();
	this->reloadingTimeClock = sf::Clock();
	this->caterpillarLeftStatus = true;
	this->caterpillarRightStatus = true;
	this->reloadingTimeStatus = true;
}

Tank::~Tank()
{
}

	/*getter*/


unsigned int		Tank::getArmorFront()
{
	return this->armorFront;
}

unsigned int		Tank::getArmorLeft()
{
	return this->armorLeft;
}

unsigned int		Tank::getArmorRight()
{
	return this->armorRight;
}

unsigned int		Tank::getArmorBack()
{
	return this->armorBack;
}

unsigned int		Tank::getHP()
{
	return this->hp;
}

bool				Tank::getCaterpillarLeftStatus()
{
	return this->caterpillarLeftStatus;
}

const sf::Clock	&	Tank::getCaterpillarLeftClock()
{
	return this->caterpillarLeftClock;
}

bool				Tank::getCaterpillarRightStatus()
{
	return this->caterpillarRightStatus;
}

const sf::Clock	&	Tank::getCaterpillarRightClock()
{
	return this->caterpillarRightClock;
}

bool				Tank::getReloadingTimeStatus()
{
	return this->reloadingTimeStatus;
}

const sf::Clock	&	Tank::getReloadingTimeClock()
{
	return this->reloadingTimeClock;
}


/*setter*/

/*methodr*/

void	Tank::reset()
{
	this->armorBack = STAT_TANK_ARMOR_BACK;
	this->armorFront = STAT_TANK_ARMOR_FRONT;
	this->armorLeft = STAT_TANK_ARMOR_SIDE;
	this->armorRight = STAT_TANK_ARMOR_SIDE;
	this->hp = STAT_TANK_LIFE;
	this->caterpillarLeftClock.restart();
	this->caterpillarRightClock.restart();
	this->reloadingTimeClock.restart();
	this->caterpillarLeftStatus = true;
	this->caterpillarRightStatus = true;
	this->reloadingTimeStatus = true;
}

void	Tank::takeDamageOnArmorFront(	unsigned int	damage)
{
	if (damage >= this->armorFront)
		this->armorFront = 0;
	else
		this->armorFront -= damage;
}

void	Tank::takeDamageOnArmorLeft(	unsigned int	damage)
{
	if (damage >= this->armorLeft)
		this->armorLeft = 0;
	else
		this->armorLeft -= damage;
}

void	Tank::takeDamageOnArmorRight(	unsigned int	damage)
{
	if (damage >= this->armorRight)
		this->armorRight = 0;
	else
		this->armorRight -= damage;
}

void	Tank::takeDamageOnArmorBack(	unsigned int	damage)
{
	if (damage >= this->armorBack)
		this->armorBack = 0;
	else
		this->armorBack -= damage;
}

bool	Tank::takeDamageOnHP(	unsigned int	damage)
{
	if (damage >= this->hp)
	{
		this->hp = 0;
		return true;
	}
	this->hp -= damage;
	return false;
}

void	Tank::destroyCaterpillarRight()
{
	this->caterpillarRightClock.restart();
	this->caterpillarRightStatus = false;
}

void	Tank::destroyCaterpillarLeft()
{
	this->caterpillarLeftClock.restart();
	this->caterpillarLeftStatus = false;
}
void	Tank::shoot()
{
	this->reloadingTimeClock.restart();
	this->reloadingTimeStatus = false;
}


void	Tank::tick()
{
	if (this->reloadingTimeClock.getElapsedTime().asSeconds() >= STAT_TANK_RELOAD_TIME)
		this->reloadingTimeStatus = true;

	if (this->caterpillarLeftClock.getElapsedTime().asSeconds() >= STAT_TANK_CATTERPILAR_REPARATION_TIME)
		this->caterpillarLeftStatus = true;

	if (this->caterpillarRightClock.getElapsedTime().asSeconds() >= STAT_TANK_CATTERPILAR_REPARATION_TIME)
		this->caterpillarRightStatus = true;
}

