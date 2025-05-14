/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:29 by lflandri          #+#    #+#             */
/*   Updated: 2025/05/14 12:04:18 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_tank.hpp"

unsigned int numberOfDeath(std::map<unsigned int, unsigned int> & deathCounter)
{
	unsigned int counter = 0;
	for (std::pair<unsigned int, unsigned int>  pair: deathCounter)
	{
		counter += pair.second;
	}
	return counter;
}


    /*------------------------------------------------------------------------------
    Retourne l'image d'un point par une rotation (repère X de gauche à droite, Y du
    haut vers le bas).
    ENTREE :
        M        Point à transformer
        O        Point centre de la rotation
        angle    Angle (en degrés)
    SORTIE :
        Image de M par la rotation d'angle angle autour de O (les coordonnées ne
        sont pas entières).
    ------------------------------------------------------------------------------*/

t_point rotate(t_point & M, t_point & O, float angle)
{
	t_point tmp;
	t_point new_M;
	float radiant_angle = angle * (M_PI / 180);
	tmp.x = M.x - O.x;
	tmp.y = M.y - O.y;
	new_M.x = tmp.x * cos (radiant_angle) + tmp.y * sin (radiant_angle) + O.x;
	new_M.y = - tmp.x * sin (radiant_angle) + tmp.y * cos (radiant_angle) + O.y;
	return new_M;
}


int	getPortFormParameters(char *charsPort)
{
	std::string	stringPort(charsPort);

	if (stringPort == "")
		throw std::invalid_argument("Empty port parameter");

	std::size_t	size = 0;
	while (size < stringPort.size() && '0' <= stringPort[size] && stringPort[size] <= '9')
		size++;

	if (size != stringPort.size())
		throw std::invalid_argument("Parameter must be an positive interger");

	long	value = 0;
	for (std::size_t i = 0; i < stringPort.size(); i++)
	{
		value = value * 10 + (stringPort[i] - '0');
		if (2147483647 < value || i > 10)
			throw std::invalid_argument("Parameter must be an positive interger");
	}

	if (65535 < value)
		throw std::invalid_argument("The maximum port is 65535");

	return (value);
}


std::string	readConnection(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		valread = recv(fd, buffer, BUFFER_SIZE, 0);

	if (valread < 0)
	{
		std::cout << "Read failed\n";
		return ("");
	}
	// Set the end of buffer
	buffer[valread] = '\0';
	std::string	message = buffer;
	return (buffer);
}


void	sendMessage(int fd, std::string message)
{
	std::cout << "[SEND] |" << message << "|\n";
	message += "\r\n";
	if (fd > -1)
		send(fd, message.c_str(), message.size(), 0);
}


bool	isMessageFullRecieved(std::string message)
{
	if (message.size() > 1 && message[message.size() - 1] == '\n')
		return (true);
	return (false);

}


std::string	removeEndSignal(std::string message)
{
	if (!isMessageFullRecieved(message))
		return (message);

	std::string	str = "";
	std::size_t	toRemove = 1;

	if (message.size() > 2 && message[message.size() - 2] == '\r' && message[message.size() - 1] == '\n')
		toRemove = 2;

	for (std::size_t i = 0; i < message.size() - toRemove; i++)
		str += message[i];

	return (str);
}


std::vector<std::string>	splitString(std::string &str, std::string separator)
{
	std::vector<std::string>	res;

	std::size_t	start, size;

	start = 0;
	size = 0;
	while (start + size < str.size())
	{
		if (start + size + separator.size() < str.size() && str.substr(start + size, separator.size()) == separator)
		{
			if (size > 0)
			{
				res.push_back(str.substr(start, size));
				start += size + separator.size();
				size = 0;
			}
			else
				size++;
		}
		else
			size++;
	}
	if (size > 0)
	{
		res.push_back(str.substr(start, size));
		start += size + separator.size();
	}

	return (res);
}


bool	isInt(std::string parameter)
{
	int	size = (int)parameter.size();

	if (size == 0)
		return (false);

	if (size > 11)
		return (false);

	int		sign = 1;
	long	number = 0;
	for (int i = 0; i < size; i++)
	{
		char c = parameter.at(i);

		if (c < '0' || '9' < c)
		{
			if (c == '-' || c == '+')
			{
				if (i != 0)
					return (false);
				else if (c == '-')
					sign = -1;
			}
			else
				return (false);
		}
		else
			number = number * 10 + c - '0';
	}

	number *= sign;
	return (-2147483648 <= number && number <= 2147483647);
}


int	randInt(int min, int max)
{
	int	diff = max - min;

	return (rand() % diff + min);
}


// std::string	nbToString(int nb)
// {
// 	return (static_cast<std::ostringstream*>( &(std::ostringstream() << nb) )->str());
// }
