/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileHE.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:35:23 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:03:09 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/class/ProjectileHE.hpp"

ProjectileHE::ProjectileHE(/* args */)
: Projectile::Projectile(STAT_PROJECTIL_HE_LIFE_DAMAGE,
						STAT_PROJECTIL_HE_ARMOR_DAMAGE,
						STAT_PROJECTIL_HE_PENETRATION,
						STAT_PROJECTIL_HE_ID)
{
}


ProjectileHE::~ProjectileHE()
{
}