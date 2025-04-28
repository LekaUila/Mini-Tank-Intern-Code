/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionDeclaration.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:24:00 by lflandri          #+#    #+#             */
/*   Updated: 2025/04/28 15:26:54 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION8DECLARATION
# define FUNCTIONDECLARATION
# include "externalLibraryInclude.hpp"

unsigned int numberOfDeath(std::map<unsigned int, unsigned int> & deathCounter);
t_point rotate(t_point & M, t_point & O, float angle);



/*template*/

template <typename T>
	std::string NumberToString ( T Number )
	{
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}


#endif