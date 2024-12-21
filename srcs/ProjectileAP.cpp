/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileAP.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:35:23 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:01:48 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/class/ProjectileAP.hpp"

ProjectileAP::ProjectileAP(/* args */)
: Projectile::Projectile(STAT_PROJECTIL_AP_LIFE_DAMAGE,
						STAT_PROJECTIL_AP_ARMOR_DAMAGE,
						STAT_PROJECTIL_AP_PENETRATION,
						STAT_PROJECTIL_AP_ID)
{
}


ProjectileAP::~ProjectileAP()
{
}