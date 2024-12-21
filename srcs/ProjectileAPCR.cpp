/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileAPCR.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:35:23 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:02:53 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/class/ProjectileAPCR.hpp"

ProjectileAPCR::ProjectileAPCR(/* args */)
: Projectile::Projectile(STAT_PROJECTIL_APCR_LIFE_DAMAGE,
						STAT_PROJECTIL_APCR_ARMOR_DAMAGE,
						STAT_PROJECTIL_APCR_PENETRATION,
						STAT_PROJECTIL_APCR_ID)
{
}


ProjectileAPCR::~ProjectileAPCR()
{
}