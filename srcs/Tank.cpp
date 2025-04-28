/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:40:49 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/28 15:06:43 by lflandri         ###   ########.fr       */
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
	this->rotation = 0;
	// sf::SoundBuffer	shootBufferSound;
	// std::cout << "loading : " << "../sound/shoot.wav" << std::endl;
	// if (this->shootBufferSound.loadFromFile("../sound/shoot.wav"))
	// 	throw std::runtime_error("Error : Can't load file \"../sound/shoot.wav\"." );
		
}

Tank::~Tank()
{
}

	/*getter*/


float		Tank::getArmorFront()
{
	return this->armorFront;
}

float		Tank::getArmorLeft()
{
	return this->armorLeft;
}

float		Tank::getArmorRight()
{
	return this->armorRight;
}

float		Tank::getArmorBack()
{
	return this->armorBack;
}

float		Tank::getHP()
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


float	Tank::getRotation()
{
	return 	this->rotation;
}

	
/*setter*/

void	Tank::setRotation(float r)
{
	this->rotation = r;
}

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
	// std::cout << "test" << std::endl;
	// sf::Sound sound;
	// sound.setBuffer(this->shootBufferSound);
	// sound.setVolume(100);
	// sound.play();
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

