/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:02:51 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/25 20:09:13 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/Interface.hpp"


Interface::Interface(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
	this->inGame = false;
	this->otherPosition;
	this->radarAngle = 0;
	this->position.x = 0;
	this->position.y = 0;

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
	this->tanTopViewSprite.setPosition(	this->x / 6 * 3.75 - this->tanTopViewSprite.getGlobalBounds().width / 2, 
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
	sf::CircleShape		point(this->y / 100, 10);

	radarBack.setFillColor(sf::Color(0, 0, 0));
	radarBack.setPosition(this->x / 8 * 0.25, this->y / 6);
	radarBack.setOutlineThickness(this->x / 384);
	radarBack.setOutlineColor(sf::Color(INTERFACE_RADAR_MAIN_COLOR));
	window.draw(radarBack);

	for (size_t i = 0; i < INTERFACE_RADAR_LINE_NUMBER; i++)
	{
		sf::Color col = sf::Color(INTERFACE_RADAR_LINE_COLOR,
						255 - (i * 255 / INTERFACE_RADAR_LINE_NUMBER));
		lineList[i] = sf::RectangleShape((sf::Vector2f(1, this->y / 3)));
		lineList[i].setPosition(this->x / 8 * 0.25 + this->y / 3, 
		this->y / 6 + this->y / 3);
		lineList[i].setRotation(this->radarAngle + (i * 0.2) + 180);
		lineList[i].setFillColor(col);
		window.draw(lineList[i]);
	}

	for (auto &&other : this->otherPosition)
	{
		if (sqrt((other.second.x * other.second.x) + (other.second.y * other.second.y ))  > 10 )
			continue;

		t_point AB;
		AB.x = 0;
		AB.y = -5;
		t_point AC;
		AC.x = other.second.x;
		AC.y = other.second.y;
		double angle = acos((AB.x * AC.x + AB.y * AC.y) / (sqrt(AB.x * AB.x + AB.y * AB.y) * sqrt(AC.x * AC.x + AC.y * AC.y))) * 57.2958;
		double varieangle = 210;
		if (AC.x < 0)
			angle = 360 - angle;
		point.setFillColor(
			sf::Color(
				INTERFACE_RADAR_LINE_COLOR, 
				360 - int(angle - (int(this->radarAngle + varieangle) % 360)) * 255 / 360

			));

		point.setPosition(this->x / 8 * 0.25 + this->y / 3 - this->y / 100 + (other.second.x * (this->y / 3) / 10),
							this->y / 6 + this->y / 3 - this->y / 100 + (other.second.y * (this->y / 3) / 10));
		window.draw(point);
	}
}

void	Interface::drawTankHP(Tank & tank, sf::RenderWindow & window)
{

	sf::RectangleShape	tankHpBack(sf::Vector2f(this->x / 6 * 2, this->y / 3 * 2));
	sf::Text			textHP;
	sf::RectangleShape	barHP;

	textHP.setFillColor(sf::Color(INTERFACE_TANK_MAIN_COLOR));
	textHP.setFont(this->interfaceFont);
	textHP.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	textHP.setCharacterSize(25);



	tankHpBack.setFillColor(sf::Color(0, 0, 0));
	tankHpBack.setPosition(this->x / 6 * 2.75, this->y / 6);
	tankHpBack.setOutlineThickness(this->x / 384);
	tankHpBack.setOutlineColor(sf::Color(100,100,100));
	window.draw(tankHpBack);

	window.draw(this->tanTopViewSprite);

	/*armor front*/
	textHP.setString(NumberToString(tank.getArmorFront()) + " / " + NumberToString(STAT_TANK_ARMOR_FRONT));
	textHP.setPosition(this->x / 6 * 3.75 - textHP.getGlobalBounds().width / 2,  this->y / 6 * 1.5);
	window.draw(textHP);

	barHP.setPosition(textHP.getPosition().x, textHP.getPosition().y + textHP.getGlobalBounds().height + this->y / 180);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	barHP.setSize(sf::Vector2f(textHP.getGlobalBounds().width, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	barHP.setSize(sf::Vector2f(tank.getArmorFront() * textHP.getGlobalBounds().width /
									STAT_TANK_ARMOR_FRONT, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);


	/*armor left*/
	textHP.setString(NumberToString(tank.getArmorLeft()) + " / " + NumberToString(STAT_TANK_ARMOR_SIDE));
	textHP.setPosition(this->x / 6 * 3,  this->y / 6 * 2.75);
	window.draw(textHP);

	barHP.setPosition(textHP.getPosition().x, textHP.getPosition().y + textHP.getGlobalBounds().height + this->y / 180);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	barHP.setSize(sf::Vector2f(textHP.getGlobalBounds().width, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	barHP.setSize(sf::Vector2f(tank.getArmorLeft() * textHP.getGlobalBounds().width /
									STAT_TANK_ARMOR_SIDE, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);

	/*armor right*/
	textHP.setString(NumberToString(tank.getArmorRight()) + " / " + NumberToString(STAT_TANK_ARMOR_SIDE));
	textHP.setPosition(this->x / 6 * 4.25,  this->y / 6 * 2.75);
	window.draw(textHP);

	barHP.setPosition(textHP.getPosition().x, textHP.getPosition().y + textHP.getGlobalBounds().height + this->y / 180);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	barHP.setSize(sf::Vector2f(textHP.getGlobalBounds().width, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	barHP.setSize(sf::Vector2f(tank.getArmorRight() * textHP.getGlobalBounds().width /
									STAT_TANK_ARMOR_SIDE, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);

	/*armor back*/
	textHP.setString(NumberToString(tank.getArmorBack()) + " / " + NumberToString(STAT_TANK_ARMOR_BACK));
	textHP.setPosition(this->x / 6 * 3.75 - textHP.getGlobalBounds().width / 2,  this->y / 6 * 4.5);
	window.draw(textHP);

	barHP.setPosition(textHP.getPosition().x, textHP.getPosition().y + textHP.getGlobalBounds().height + this->y / 180);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	barHP.setSize(sf::Vector2f(textHP.getGlobalBounds().width, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	barHP.setSize(sf::Vector2f(tank.getArmorBack() * textHP.getGlobalBounds().width /
									STAT_TANK_ARMOR_BACK, textHP.getGlobalBounds().height / 2));
	window.draw(barHP);


	/*PV*/


	barHP.setPosition(this->x / 6 * 2.75, this->y / 6);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	barHP.setSize(sf::Vector2f(this->x / 6 * 2, this->y / 6 * 0.25));
	window.draw(barHP);
	barHP.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	barHP.setSize(sf::Vector2f(tank.getHP() * (this->x / 6 * 2) /
									STAT_TANK_LIFE, this->y / 6 * 0.25));

	window.draw(barHP);

	textHP.setFillColor(sf::Color(0,0,0));
	textHP.setFont(this->interfaceFont);
	textHP.setCharacterSize(35);
	textHP.setString("PV : " + NumberToString(tank.getHP()) + " / " + NumberToString(STAT_TANK_LIFE));
	textHP.setPosition(this->x / 6 * 3.75 - textHP.getGlobalBounds().width / 2,  this->y / 6 );
	window.draw(textHP);

}

void	Interface::drawReloading(Tank & tank, sf::RenderWindow & window)
{
	sf::Text			textReloading;
	sf::RectangleShape	reloadingBar;

	reloadingBar.setPosition(this->x / 6,  this->y / 6 * 5.25);
	reloadingBar.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	reloadingBar.setSize(sf::Vector2f(this->x / 6 * 4, this->y / 6 * 0.50));
	reloadingBar.setOutlineThickness(this->x / 384);
	reloadingBar.setOutlineColor(sf::Color(100,100,100));
	window.draw(reloadingBar);
	reloadingBar.setOutlineThickness(0);
	reloadingBar.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	if (tank.getReloadingTimeStatus())
		reloadingBar.setSize(sf::Vector2f(this->x / 6 * 4, this->y / 6 * 0.50));
	else
		reloadingBar.setSize(sf::Vector2f(tank.getReloadingTimeClock().getElapsedTime().asSeconds() * (this->x / 6 * 4) /
									STAT_TANK_RELOAD_TIME, this->y / 6 * 0.50));
	window.draw(reloadingBar);

	textReloading.setFont(this->interfaceFont);
	textReloading.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	textReloading.setFillColor(sf::Color(0,0,0));
	textReloading.setFont(this->interfaceFont);
	textReloading.setCharacterSize(85);
	if (tank.getReloadingTimeStatus())
		textReloading.setString("Systeme ready to fire");
	else
		textReloading.setString(NumberToString(STAT_TANK_RELOAD_TIME - (double(int(tank.getReloadingTimeClock().getElapsedTime().asSeconds() * INTERFACE_RELOADING_TIMER_PRECISION)) / INTERFACE_RELOADING_TIMER_PRECISION)));
	textReloading.setPosition(this->x / 6 * 3 - textReloading.getGlobalBounds().width / 2,  this->y / 6 * 5.20);
	window.draw(textReloading);
}

void	Interface::drawCaterpillarStatus(Tank & tank, sf::RenderWindow & window)
{
	sf::Text			CatterpilarName;
	sf::Text			CatterpilarStatus;
	sf::Text			CatterpilarTimer;

	CatterpilarName.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	CatterpilarStatus.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	CatterpilarTimer.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	CatterpilarName.setFont(this->interfaceFont);
	CatterpilarStatus.setFont(this->interfaceFont);
	CatterpilarTimer.setFont(this->interfaceFont);
	CatterpilarName.setCharacterSize(25);
	CatterpilarStatus.setCharacterSize(20);
	CatterpilarTimer.setCharacterSize(20);

	CatterpilarName.setString("Caterpillar left");
	if (tank.getCaterpillarLeftStatus())
	{
		CatterpilarStatus.setString("Status : OK");
		CatterpilarTimer.setString("");
		CatterpilarName.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
		CatterpilarStatus.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
		CatterpilarTimer.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	}
	else
	{
		CatterpilarStatus.setString("Status : KO");
		CatterpilarTimer.setString("Ready in : "
							+ NumberToString(STAT_TANK_CATTERPILAR_REPARATION_TIME -
							(double(int(tank.getCaterpillarLeftClock().getElapsedTime().asSeconds()
									* INTERFACE_CATERPILLAR_TIMER_PRECISION)) / INTERFACE_CATERPILLAR_TIMER_PRECISION)));
		CatterpilarName.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
		CatterpilarStatus.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
		CatterpilarTimer.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	}
	CatterpilarName.setPosition(this->x / 6 * 2.80,  this->y / 6 * 3.45);
	CatterpilarStatus.setPosition(this->x / 6 * 2.80,  this->y / 6 * 3.45 + CatterpilarName.getGlobalBounds().height + 6);
	CatterpilarTimer.setPosition(this->x / 6 * 2.80,  this->y / 6 * 3.45 + (CatterpilarName.getGlobalBounds().height + 6) * 2);
	window.draw(CatterpilarName);
	window.draw(CatterpilarStatus);
	window.draw(CatterpilarTimer);

	CatterpilarName.setString("Caterpillar right");
	if (tank.getCaterpillarRightStatus())
	{
		CatterpilarStatus.setString("Status : OK");
		CatterpilarTimer.setString("");
		CatterpilarName.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
		CatterpilarStatus.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
		CatterpilarTimer.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_FRONT));
	}
	else
	{
		CatterpilarStatus.setString("Status : KO");
		CatterpilarTimer.setString("Ready in : "
							+ NumberToString(STAT_TANK_CATTERPILAR_REPARATION_TIME -
							(double(int(tank.getCaterpillarRightClock().getElapsedTime().asSeconds()
									* INTERFACE_CATERPILLAR_TIMER_PRECISION)) / INTERFACE_CATERPILLAR_TIMER_PRECISION)));
		CatterpilarName.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
		CatterpilarStatus.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
		CatterpilarTimer.setFillColor(sf::Color(INTERFACE_TANK_LIFE_BAR_BACK));
	}
	CatterpilarName.setPosition(this->x / 6 * 4.15,  this->y / 6 * 3.45);
	CatterpilarStatus.setPosition(this->x / 6 * 4.15,  this->y / 6 * 3.45 + CatterpilarName.getGlobalBounds().height + 6);
	CatterpilarTimer.setPosition(this->x / 6 * 4.15,  this->y / 6 * 3.45 + (CatterpilarName.getGlobalBounds().height + 6) * 2);
	window.draw(CatterpilarName);
	window.draw(CatterpilarStatus);
	window.draw(CatterpilarTimer);
}

void	Interface::drawKillDeathCounter(std::map<unsigned int, unsigned int> & deathCounter, sf::RenderWindow & window)
{
	unsigned int counter = numberOfDeath(deathCounter);
	sf::Text			textHP;
	sf::RectangleShape	barHP;


	barHP.setPosition(this->x / 6,  this->y / 6 * 0.25);
	barHP.setSize(sf::Vector2f(this->x / 6 * 4, this->y / 6 * 0.50));
	barHP.setFillColor(sf::Color(0, 0, 0));
	barHP.setOutlineThickness(this->x / 384);
	barHP.setOutlineColor(sf::Color(100,100,100));
	window.draw(barHP);


	textHP.setFillColor(sf::Color(INTERFACE_TANK_MAIN_COLOR));
	textHP.setFont(this->interfaceFont);
	textHP.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	textHP.setCharacterSize(80);
	textHP.setString("Death : " + NumberToString(counter));
	textHP.setPosition(this->x / 6,  this->y / 6 * 0.25);
	window.draw(textHP);
	textHP.setString("Kill : 0");
	textHP.setPosition(this->x / 6 * 3,  this->y / 6 * 0.25);
	window.draw(textHP);
}

void	Interface::drawProjectileSelector(ProjectileManager & projectileManager, sf::RenderWindow & window)
{
	sf::RectangleShape	projectileSelector(sf::Vector2f(this->x / 6, this->y / 3 * 2));
	sf::Text			ProjectileName;
	sf::Text			ProjectileStock;
	const char			*nameProjectileList[4] = {"AP","APCR","HE","HEAT"};
	int					ProjectileNumber;

	ProjectileName.setFont(this->interfaceFont);
	ProjectileName.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	ProjectileName.setCharacterSize(35);	
	ProjectileStock.setFont(this->interfaceFont);
	ProjectileStock.setScale(this->x / RESOLUTION_X, this->y / RESOLUTION_Y);
	ProjectileStock.setCharacterSize(25);

	projectileSelector.setFillColor(sf::Color(0, 0, 0));
	projectileSelector.setPosition(this->x / 6 * 4.85, this->y / 6);
	projectileSelector.setOutlineThickness(this->x / 384);
	projectileSelector.setOutlineColor(sf::Color(100,100,100));
	window.draw(projectileSelector);
	
	for (size_t i = 0; i < 4; i++)
	{
		ProjectileNumber = projectileManager.getNumberOfProjectileFor(i);
		if (i == projectileManager.getSelectionIndice())
		{
			ProjectileName.setFillColor(sf::Color(INTERFACE_PROJECTILE_SELECTOR_UNDERLINE_COLOR));
			ProjectileStock.setFillColor(sf::Color(INTERFACE_PROJECTILE_SELECTOR_UNDERLINE_COLOR));
		}
		else if (ProjectileNumber)
		{
			ProjectileName.setFillColor(sf::Color(INTERFACE_PROJECTILE_SELECTOR_BASIC_COLOR));
			ProjectileStock.setFillColor(sf::Color(INTERFACE_PROJECTILE_SELECTOR_BASIC_COLOR));
		}
		else
		{
			ProjectileName.setFillColor(sf::Color(INTERFACE_PROJECTILE_SELECTOR_NO_ARMOR_COLOR));
			ProjectileStock.setFillColor(sf::Color(INTERFACE_PROJECTILE_SELECTOR_NO_ARMOR_COLOR));
		}
		ProjectileName.setPosition(this->x / 6 * 4.90, this->y / 6 * (i * 1 + 1));
		ProjectileStock.setPosition(this->x / 6 * 4.90, this->y / 6 * (i * 1 + 1.25));
		ProjectileName.setString(nameProjectileList[i]);
		if (ProjectileNumber == -1)
			ProjectileStock.setString("Stock : unlimited");
		else
			ProjectileStock.setString("Stock : " + NumberToString(ProjectileNumber));
		window.draw(ProjectileName);
		window.draw(ProjectileStock);
		

	}
	
}



void	Interface::draw(Tank & tank, std::map<unsigned int, unsigned int> & deathCounter,ProjectileManager & projectileManager, sf::RenderWindow & window)
{	
	window.draw(this->backgroundSprite);
	this->drawRadar(window);
	this->drawTankHP(tank, window);
	this->drawCaterpillarStatus(tank, window);
	this->drawReloading(tank, window);
	this->drawKillDeathCounter(deathCounter, window);
	this->drawProjectileSelector(projectileManager, window);
}
