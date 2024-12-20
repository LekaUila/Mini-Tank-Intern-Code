/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:37:04 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/20 18:58:10 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header_tank.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mini Tank Interface", sf::Style::Fullscreen);
    Tank tank = Tank();

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
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }

        // float delta = clock.restart().asSeconds();
        // std::cout << clock.getElapsedTime().asSeconds() << std::endl;
        // float fps = 1.0f / delta;
        // std::string title(std::to_string(fps));
        // window.setTitle(title);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
    }

    return 0;
}
