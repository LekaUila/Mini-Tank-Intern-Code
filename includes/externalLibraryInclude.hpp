/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externalLibraryInclude.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:29:25 by lflandri          #+#    #+#             */
/*   Updated: 2025/05/14 11:51:18 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNAL_LBRARY_INCLUDE
# define EXTERNAL_LBRARY_INCLUDE

# include <SFML/Graphics.hpp>
// # include <SFML/Audio.hpp>
# include <iostream>
# include <string>
# include <sstream>
# include <map>
# include <vector>
# include <math.h>
# include <stdexcept>
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <poll.h>
# include <list>
# include <stdexcept>
# include <algorithm>


# define BUFFER_SIZE 4096

typedef struct pollfd	t_pollfd;
typedef struct sockaddr	t_sockaddr;
typedef struct sockaddr_in	t_sockaddr_in;

# ifndef M_PI
#  define M_PI 3.14159
# endif 

#endif