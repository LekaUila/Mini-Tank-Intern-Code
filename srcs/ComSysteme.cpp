/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ComSysteme.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:40:49 by lflandri          #+#    #+#             */
/*   Updated: 2025/05/14 12:02:53 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class/ComSysteme.hpp"






static std::string	removeFirstCharacter(std::string str)
{
	std::string	result = "";
	for (std::size_t i = 1; i < str.size(); i++)
		result += str[i];

	return (result);
}


static bool	isConnectionOk(int fd)
{
	char	buf[1];

	return (read(fd, buf, 0) == 0);
}




ComSysteme::ComSysteme(unsigned int i, unsigned int p, std::string mdp)
{
	this->id = i;
	this->connection_status = DISCONNECTED;
	this->failed_try = 0;
	this->fd = -1;
	this->port = p;
	this->name = "Funny Bot !";
	this->password = mdp;
	this->tmpRecieved = "";
}

ComSysteme::~ComSysteme()
{

}


/*getter*/

unsigned int	ComSysteme::getId()
{
	return this->id;
}

int				ComSysteme::getStatus()
{
	return this->connection_status;

}

int				ComSysteme::getFailedTry()
{
	return this->failed_try;
}



	
/*setter*/


/*methode*/

void 	ComSysteme::init( void )
{
	this->connection_status = CONNECTING;
	this->fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->fd < 0)
		throw std::invalid_argument("Socket creation failed\n");

	t_sockaddr_in	addr;

	addr.sin_port = htons(this->port);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;

	if (connect(this->fd, (t_sockaddr *)&addr, sizeof(addr)) == -1)
	{
		this->stop();
		// throw std::invalid_argument("Connection to server failed\n");
		this->failed_try += 1;
		std::cout << "Connection to server failed\n" << std::endl;
		return ;
	}

	sendMessage(this->fd, "CAP LS 302");
	sendMessage(this->fd, "NICK " + this->name);
	sendMessage(this->fd, "USER " + this->name + " 0 * :realname");

	if (this->password != "")
		sendMessage(this->fd, "PASS " + this->password);

	std::cout << "Bot running as |" << this->name << "| on port " << this->port;
	if (this->password != "")
		std::cout << "| using key |" << this->password;
	std::cout << "|" << std::endl;
}


void	ComSysteme::updateDataRecieved( void )
{
	if (!isConnectionOk(this->fd))
	{
		this->stop();
		return ;
	}

	// Prepar poll struct
	t_pollfd	pollEvents[2];

	// Set fd listenning of standard entry
	pollEvents[0].fd = 0;
	pollEvents[0].events = POLLIN;

	// Set fd listenning of connection with server
	pollEvents[1].fd = this->fd;
	pollEvents[1].events = POLLIN;

	// Poll every fd set in struct tab
	int pollReturn = poll(pollEvents, 2, 100);

	// If poll crash
	if (pollReturn < 0)
		return ;

	// Check if something is write on standard entry
	if (pollEvents[0].revents & POLLIN)
	{
		std::string	buf;

		std::getline(std::cin, buf);
		if (buf == "stop")
		{
			this->stop();
			return ;
		}
	}

	// Check server send something
	if (pollEvents[1].revents & POLLIN)
	{
		this->tmpRecieved += readConnection(this->fd);

		if (isMessageFullRecieved(this->tmpRecieved))
		{
			this->tmpRecieved = removeEndSignal(this->tmpRecieved);

			if (this->tmpRecieved == "ERROR :Server shutdown")
			{
				std::cout << "\n[RECIEVED] |" << this->tmpRecieved << "|" << std::endl;
				this->stop();
				return ;
			}

			std::vector<std::string>	cmds = splitString(this->tmpRecieved, "\r\n");

			for (std::size_t i = 0; i < cmds.size(); i++)
			{
				std::cout << "\n[RECIEVED] |" << cmds[i] << "|" << std::endl;
				std::vector<std::string>	cmd = splitString(cmds[i], " ");

				if (cmd.size() > 0)
					this->commands.push_back(cmd);
			}
			this->tmpRecieved = "";
		}
	}

}


void	ComSysteme::executeCommands( void )
{
	for (std::size_t i = 0; i < this->commands.size(); i++)
	{
		std::vector<std::string>	command = commands[i];

		// Parse command recieved from user

	}

	this->commands.clear();
}


void	ComSysteme::stop( void )
{
	std::cout << "Stoping bot" << std::endl;

	if (this->fd > 2)
		close(this->fd);
	this->fd = -1;

	this->commands.clear();
	this->tmpRecieved = "";

	this->connection_status = DISCONNECTED;
}
