/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:37:04 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 17:04:36 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/class/Tank.hpp"
#include "../includes/class/Interface.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // create the window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Mini Tank Interface",
                            sf::Style::Fullscreen, settings);
    Tank tank = Tank();
    Interface interface = Interface( window.getSize().x,  window.getSize().y);

    window.setFramerateLimit(60);

    sf::Clock clock;

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
                    tank.shoot();
                if (event.key.code == sf::Keyboard::K)
                    tank.destroyCaterpillarLeft();
                if (event.key.code == sf::Keyboard::M)
                    tank.destroyCaterpillarRight();
            
            }
        }

        // float delta = clock.restart().asSeconds();
        // std::cout << clock.getElapsedTime().asSeconds() << std::endl;
        // float fps = 1.0f / delta;
        // std::string title(std::to_string(fps));
        // window.setTitle(title);

        // clear the window with black color
        interface.tick();
        tank.tick();
        window.clear(sf::Color::Black);

        // draw everything here...
        interface.draw(tank, window);
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
