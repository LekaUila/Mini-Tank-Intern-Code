/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ComSysteme.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:37 by lflandri          #+#    #+#             */
/*   Updated: 2025/05/14 13:56:31 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMSYSTEME
# define COMSYSTEME

# include "../header_tank.hpp"

enum ComSystemeStatus
{
	DISCONNECTED,
	CONNECTING,
	CONNECTED
};

class ComSysteme
{
private:

	unsigned int	id;
	int				connection_status;
	unsigned int	failed_try;
	// sf::SoundBuffer	shootBufferSound;
	int			port, fd;
	std::string	name, password, tmpRecieved;
	std::vector<std::vector<std::string> >	commands;
	std::vector<std::vector<std::string> >	commandsInWait;
	sf::Clock		reconnectionTimer;



public:

	ComSysteme(unsigned int i, unsigned int p, std::string mdp);
	~ComSysteme();

	/*getter*/
	
	sf::Clock	&	getReconnectionTimer();
	unsigned int	getId();
	int				getStatus();
	int				getFailedTry();

	/*setter*/


	/*methode*/

	void 			addFailedTry();
	void 			init( void );
	void			updateDataRecieved( void );
	void			executeCommands( void );
	void			stop( void );

};










#endif