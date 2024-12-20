/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionDeclaration.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:24:00 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 17:44:20 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION8DECLARATION
# define FUNCTIONDECLARATION
# include "externalLibraryInclude.hpp"

unsigned int numberOfDeath(std::map<unsigned int, unsigned int> & deathCounter);



/*template*/

template <typename T>
	std::string NumberToString ( T Number )
	{
		std::ostringstream ss;
		ss << Number;
		return ss.str();
	}


#endif