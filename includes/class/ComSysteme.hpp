/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ComSysteme.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:38:37 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/29 10:46:18 by lflandri         ###   ########.fr       */
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


public:

	ComSysteme(unsigned int i);
	~ComSysteme();

	/*getter*/
	
	unsigned int	getId();
	int				getStatus();
	int				getFailedTry();

	/*setter*/


	/*methode*/



};










#endif