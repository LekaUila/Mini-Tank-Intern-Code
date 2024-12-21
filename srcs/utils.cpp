/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:29 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 13:47:10 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header_tank.hpp"

// size_t calculTextWith(sf::Text & text)
// {
// 	size_t	stringSize = text.getString().getSize();
// 	size_t	caractereSize = text.getCharacterSize();
// 	size_t	spacing = text.getLetterSpacing();
// 	std::cout << "NB caractere : " << stringSize
// 				<< " and caractere size : " << caractereSize 
// 				<< " and spacing size : " << spacing << std::endl;
// 	if (!stringSize)
// 		return 0;
// 	return (caractereSize * stringSize + spacing * (stringSize - 1));
// }