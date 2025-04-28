/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:37 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/28 15:05:32 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TANK
# define TANK
# include <SFML/Audio.hpp>

# include "../header_tank.hpp"

class Tank
{
private:

	float	armorFront;
	float	armorLeft;
	float	armorRight;
	float	armorBack;
	float	hp;
	float	rotation;
	bool			caterpillarLeftStatus;
	sf::Clock		caterpillarLeftClock;
	bool			caterpillarRightStatus;
	sf::Clock		caterpillarRightClock;
	bool			reloadingTimeStatus;
	sf::Clock		reloadingTimeClock;
	// sf::SoundBuffer	shootBufferSound;


public:

	Tank(/* args */);
	~Tank();

	/*getter*/

	float		getArmorFront();
	float		getArmorLeft();
	float		getArmorRight();
	float		getArmorBack();
	float		getHP();
	bool				getCaterpillarLeftStatus();
	const sf::Clock	&	getCaterpillarLeftClock();
	bool				getCaterpillarRightStatus();
	const sf::Clock	&	getCaterpillarRightClock();
	bool				getReloadingTimeStatus();
	const sf::Clock	&	getReloadingTimeClock();
	float		getRotation();

	
	/*setter*/

	void	setRotation(float r);


	/*methodr*/


	void	reset();
	
	void	takeDamageOnArmorFront(	unsigned int	damage);
	void	takeDamageOnArmorLeft(	unsigned int	damage);
	void	takeDamageOnArmorRight(	unsigned int	damage);
	void	takeDamageOnArmorBack(	unsigned int	damage);
	//return True if tank is destroyed, else return False
	bool	takeDamageOnHP(	unsigned int	hp); 

	void	destroyCaterpillarRight();
	void	destroyCaterpillarLeft();
	void	shoot();

	void	tick();

};










#endif