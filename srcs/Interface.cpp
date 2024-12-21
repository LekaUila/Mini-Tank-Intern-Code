/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:02:51 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 13:59:37 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/Interface.hpp"


Interface::Interface(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
	this->inGame = false;
	this->otherPosition = std::map<unsigned int, t_point>();
	this->radarAngle = 0;

	std::cout << "loading : " << "../img/interfaceBackground.jpg" << std::endl;
	this->backgroundTexture = sf::Texture();
	if (!this->backgroundTexture.loadFromFile("../img/interfaceBackground.jpg"))
		throw std::runtime_error("Error : Can't load file \"../img/interfaceBackground.jpg\"." );
	this->backgroundTexture.setSmooth(true);
	this->backgroundSprite = sf::Sprite();
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setScale(double(x) / this->backgroundTexture.getSize().x ,
									double(y) / this->backgroundTexture.getSize().y);
	this->backgroundSprite.setPosition(0.0f, 0.0f);

	std::cout << "loading : " << "../img/tankTopView.png" << std::endl;
	this->tanTopViewTexture = sf::Texture();
	if (!this->tanTopViewTexture.loadFromFile("../img/tankTopView.png"))
		throw std::runtime_error("Error : Can't load file \"../img/tankTopView.png\"." );
	this->tanTopViewTexture.setSmooth(true);
	this->tanTopViewSprite = sf::Sprite();
	this->tanTopViewSprite.setTexture(this->tanTopViewTexture);
	this->tanTopViewSprite.setScale((double(x) / this->tanTopViewTexture.getSize().x) / 10,
									(double(y) / this->tanTopViewTexture.getSize().y) / 2.5);
	this->tanTopViewSprite.setPosition(	this->x / 6 * 4.5 - this->tanTopViewSprite.getGlobalBounds().width / 2, 
										 this->y / 6 * 2);
										 
	std::cout << "loading : " << INTERFACE_FONT << std::endl;
	this->interfaceFont = sf::Font();
	if (!this->interfaceFont.loadFromFile(INTERFACE_FONT))
		throw std::runtime_error("Error : Can't load file for interface font." );
}

Interface::~Interface()
{

}

void	Interface::setInGame(bool inGame)
{
	this->inGame = inGame;
}

	/*getter*/

	/*method*/


void	Interface::updatePoint(unsigned int ID, double x, double y)
{
	this->otherPosition[ID].x = x;
	this->otherPosition[ID].y = y;
}

void	Interface::tick()
{
	this->radarAngle -= INTERFACE_RADAR_SPEED;
	if (this->radarAngle <= 0)
		this->radarAngle += 360;
}

void	Interface::drawRadar(sf::RenderWindow & window)
{
	sf::RectangleShape	lineList[INTERFACE_RADAR_LINE_NUMBER];
	sf::CircleShape		radarBack(this->y / 3, 100);

	radarBack.setFillColor(sf::Color(0, 0, 0));
	radarBack.setPosition(this->x / 8, this->y / 6);
	radarBack.setOutlineThickness(this->x / 384);
	radarBack.setOutlineColor(sf::Color(INTERFACE_RADAR_MAIN_COLOR));
	window.draw(radarBack);

	for (size_t i = 0; i < INTERFACE_RADAR_LINE_NUMBER; i++)
	{
		sf::Color col = sf::Color(INTERFACE_RADAR_LINE_COLOR,
						255 - (i * 255 / INTERFACE_RADAR_LINE_NUMBER));
		lineList[i] = sf::RectangleShape((sf::Vector2f(1, this->y / 3)));
		lineList[i].setPosition(this->x / 8 + this->y / 3, 
		this->y / 6 + this->y / 3);
		lineList[i].setRotation(this->radarAngle + (i * 0.2) + 180);
		lineList[i].setFillColor(col);
		window.draw(lineList[i]);
	}
}

void	Interface::drawTankHP(Tank & tank, sf::RenderWindow & window)
{

	sf::RectangleShape	tankHpBack(sf::Vector2f(this->x / 6 * 2, this->y / 3 * 2));
	sf::Text			textHP;

	textHP.setFillColor(sf::Color(INTERFACE_TANK_MAIN_COLOR));
	textHP.setFont(this->interfaceFont);
	textHP.setScale(this->x / 1920, this->y / 1080);
	textHP.setCharacterSize(25);



	tankHpBack.setFillColor(sf::Color(0, 0, 0));
	tankHpBack.setPosition(this->x / 6 * 3.5, this->y / 6);
	tankHpBack.setOutlineThickness(this->x / 384);
	tankHpBack.setOutlineColor(sf::Color(100,100,100));
	window.draw(tankHpBack);

	window.draw(this->tanTopViewSprite);

	/*armor front*/
	textHP.setString(NumberToString(tank.getArmorFront()) + " / " + NumberToString(STAT_TANK_ARMOR_FRONT));
	textHP.setPosition(this->x / 6 * 4.5 - textHP.getGlobalBounds().width / 2,  this->y / 6 * 1.5);
	window.draw(textHP);

	/*armor left*/
	textHP.setString(NumberToString(tank.getArmorLeft()) + " / " + NumberToString(STAT_TANK_ARMOR_SIDE));
	textHP.setPosition(this->x / 6 * 3.75,  this->y / 6 * 2.75);
	window.draw(textHP);

	/*armor right*/
	textHP.setString(NumberToString(tank.getArmorRight()) + " / " + NumberToString(STAT_TANK_ARMOR_SIDE));
	textHP.setPosition(this->x / 6 * 5,  this->y / 6 * 2.75);
	window.draw(textHP);

	/*armor back*/
	textHP.setString(NumberToString(tank.getArmorBack()) + " / " + NumberToString(STAT_TANK_ARMOR_BACK));
	textHP.setPosition(this->x / 6 * 4.5 - textHP.getGlobalBounds().width / 2,  this->y / 6 * 4.5);
	window.draw(textHP);


}

void	Interface::draw(Tank & tank, sf::RenderWindow & window)
{	
	window.draw(this->backgroundSprite);
	this->drawRadar(window);
	this->drawTankHP(tank, window);

}
