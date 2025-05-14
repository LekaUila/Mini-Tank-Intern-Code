/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionDeclaration.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:24:00 by lflandri          #+#    #+#             */
/*   Updated: 2025/05/14 12:04:27 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION8DECLARATION
# define FUNCTIONDECLARATION
# include "externalLibraryInclude.hpp"

unsigned int numberOfDeath(std::map<unsigned int, unsigned int> & deathCounter);
t_point rotate(t_point & M, t_point & O, float angle);


int	getPortFormParameters(char *charsPort);

std::string	readConnection(int fd);
void		sendMessage(int fd, std::string message);

bool						isMessageFullRecieved(std::string message);
std::string					removeEndSignal(std::string message);
std::vector<std::string>	splitString(std::string &str, std::string separator);

bool	isInt(std::string parameter);

int			randInt(int min, int max);
// std::string	nbToString(int nb);


/*template*/

template <typename T>
	std::string NumberToString ( T Number )
	{
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}


#endif