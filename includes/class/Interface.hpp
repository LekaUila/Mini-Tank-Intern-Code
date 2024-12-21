/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:02:36 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 17:43:29 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE
# define INTERFACE

# include "../header_tank.hpp"
# include "Tank.hpp"


class Interface
{
private:
	
	std::map<unsigned int,t_point>	otherPosition;
	bool							inGame;
	double							radarAngle;
	size_t							x;
	size_t							y;

	//image
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	sf::Texture tanTopViewTexture;
	sf::Sprite tanTopViewSprite;

	//font
	sf::Font	interfaceFont;

	void	drawRadar(sf::RenderWindow & window);
	void	drawTankHP(Tank & tank, sf::RenderWindow & window);
	void	drawReloading(Tank & tank, sf::RenderWindow & window);
	void	drawCaterpillarStatus(Tank & tank, sf::RenderWindow & window);
	void	drawKillDeathCounter(std::map<unsigned int, unsigned int> & deathCounter,sf::RenderWindow & window);


public:
	Interface(size_t x, size_t y);
	~Interface();

	/*setter*/

	void	setInGame(bool inGame);

	/*getter*/

	/*method*/


	void	updatePoint(unsigned int ID, double x, double y);
	void	tick();
	void	draw(Tank & tank, std::map<unsigned int, unsigned int> & deathCounter, sf::RenderWindow & window);
};










#endif