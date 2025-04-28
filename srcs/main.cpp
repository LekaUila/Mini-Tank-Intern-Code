/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:37:04 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/28 15:33:56 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/class/Tank.hpp"
#include "../includes/class/Interface.hpp"
#include "../includes/class/ProjectileManager.hpp"

int main(int ac, char **av)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // create the window
    sf::RenderWindow window(sf::VideoMode(RESOLUTION_X, RESOLUTION_Y), "Mini Tank Interface",
                            sf::Style::Fullscreen, settings);
    Tank tank = Tank();
    Interface interface = Interface( window.getSize().x,  window.getSize().y);
    ProjectileManager projectileManager = ProjectileManager();
    std::map<unsigned int, unsigned int>deathCounter;
    window.setFramerateLimit(60);

    sf::Clock clock;


    //TEST adding

    interface.setInGame(true);
    deathCounter[5] = 1;
    deathCounter[8] = 3;
    projectileManager.addProjectile(1, 1);
    projectileManager.addProjectile(3, 3);
    interface.updatePoint(4, 5, 7);
    interface.updatePoint(5, -5, 7);
    interface.updatePoint(3, 9, -2);
    interface.updatePoint(2, -1, -1);
    interface.updatePoint(6, 10, 10);



    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                // std::cout << window.getSize().x << " " << window.getSize().y << std::endl;
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                if (interface.getInGame())
                {
                    if (event.key.code == sf::Keyboard::Up)
                        tank.takeDamageOnArmorFront(5);
                    if (event.key.code == sf::Keyboard::Left)
                        tank.takeDamageOnArmorLeft(5);
                    if (event.key.code == sf::Keyboard::Right)
                        tank.takeDamageOnArmorRight(5);
                    if (event.key.code == sf::Keyboard::Down)
                        tank.takeDamageOnArmorBack(5);
                    if (event.key.code == sf::Keyboard::L)
                        tank.takeDamageOnHP(5);
                    if (event.key.code == sf::Keyboard::F)
                    {
                        tank.shoot();
                        projectileManager.shoot();
                    }
                    if (event.key.code == sf::Keyboard::K)
                        tank.destroyCaterpillarLeft();
                    if (event.key.code == sf::Keyboard::M)
                        tank.destroyCaterpillarRight();
                    if (event.key.code == sf::Keyboard::B)
                        projectileManager.goNextProjectile();
                    if (event.key.code == sf::Keyboard::N)
                        projectileManager.goLastProjectile();
                    if (event.key.code == sf::Keyboard::Q)
                        tank.setRotation(int(tank.getRotation() - 1) % 360);
                    if (event.key.code == sf::Keyboard::D)
                        tank.setRotation(int(tank.getRotation() + 1) % 360);
                }
            }
        }

        float delta = clock.restart().asSeconds();
        // std::cout << clock.getElapsedTime().asSeconds() << std::endl;
        float fps = 1.0f / delta;
        // std::cout << "fps : " << fps << std::endl;
        interface.tick(delta);
        tank.tick();
        // std::string title(std::to_string(fps));
        // window.setTitle(title);

        // clear the window with black color

        window.clear(sf::Color::Black);

        // draw everything here...
        interface.draw(tank, deathCounter, projectileManager, window);
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
