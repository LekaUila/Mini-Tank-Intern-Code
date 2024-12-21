/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileHEAT.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:35:23 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:03:06 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/class/ProjectileHEAT.hpp"

ProjectileHEAT::ProjectileHEAT(/* args */)
: Projectile::Projectile(STAT_PROJECTIL_HEAT_LIFE_DAMAGE,
						STAT_PROJECTIL_HEAT_ARMOR_DAMAGE,
						STAT_PROJECTIL_HEAT_PENETRATION,
						STAT_PROJECTIL_HEAT_ID)
{
}


ProjectileHEAT::~ProjectileHEAT()
{
}