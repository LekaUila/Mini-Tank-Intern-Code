/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:37 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/20 18:57:49 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TANK
# define TANK

# include "../header_tank.hpp"

class Tank
{
private:

	unsigned int	armorFront;
	unsigned int	armorLeft;
	unsigned int	armorRight;
	unsigned int	armorBack;
	unsigned int	hp;
	bool			caterpillarLeftStatus;
	sf::Clock		caterpillarLeftClock;
	bool			caterpillarRightStatus;
	sf::Clock		caterpillarRightClock;
	bool			reloadingTimeStatus;
	sf::Clock		reloadingTimeClock;


public:

	Tank(/* args */);
	~Tank();

	/*getter*/

	unsigned int		getArmorFront();
	unsigned int		getArmorLeft();
	unsigned int		getArmorRight();
	unsigned int		getArmorBack();
	unsigned int		getHP();
	bool				getCaterpillarLeftStatus();
	const sf::Clock	&	getCaterpillarLeftClock();
	bool				getCaterpillarRightStatus();
	const sf::Clock	&	getCaterpillarRightClock();
	bool				getReloadingTimeStatus();
	const sf::Clock	&	getReloadingTimeClock();

	
	/*setter*/


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