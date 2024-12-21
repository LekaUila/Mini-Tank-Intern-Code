/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileManager.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:34:12 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 20:11:04 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/class/ProjectileManager.hpp"

ProjectileManager::ProjectileManager()
{
	this->listProjectile = std::vector<std::pair<int, Projectile *> >(sizeof(std::pair<int, Projectile *>) * 4,
																		std::pair<int, Projectile *>(0, NULL));
	this->listProjectile[0] = std::pair<int, Projectile *>(STAT_PROJECTIL_AP_NUMBER_AT_START, new ProjectileAP());
	this->listProjectile[1] = std::pair<int, Projectile *>(STAT_PROJECTIL_APCR_NUMBER_AT_START, new ProjectileAPCR());
	this->listProjectile[2] = std::pair<int, Projectile *>(STAT_PROJECTIL_HE_NUMBER_AT_START, new ProjectileHE());
	this->listProjectile[3] = std::pair<int, Projectile *>(STAT_PROJECTIL_HEAT_NUMBER_AT_START, new ProjectileHEAT());
	this->slectionIndice = 0;
}

ProjectileManager::~ProjectileManager()
{
	delete this->listProjectile[0].second;
	delete this->listProjectile[1].second;
	delete this->listProjectile[2].second;
	delete this->listProjectile[3].second;
}

Projectile *ProjectileManager::getProjectilById(unsigned int id)
{

}

void	ProjectileManager::reset()
{
	this->slectionIndice = 0;
	this->listProjectile[0].first = STAT_PROJECTIL_AP_NUMBER_AT_START;
	this->listProjectile[1].first = STAT_PROJECTIL_APCR_NUMBER_AT_START;
	this->listProjectile[2].first = STAT_PROJECTIL_HE_NUMBER_AT_START;
	this->listProjectile[3].first = STAT_PROJECTIL_HEAT_NUMBER_AT_START;
}

Projectile *ProjectileManager::shoot()
{
	Projectile *toReturn = this->listProjectile[this->slectionIndice].second;

	if (this->slectionIndice)
	{
		this->listProjectile[this->slectionIndice].first--;
		if (!this->listProjectile[this->slectionIndice].first)
		{
			this->slectionIndice = 0;
		}
	}
}

void		ProjectileManager::addProjectile(unsigned int id, unsigned int number)
{
	this->listProjectile[id].first += number;
}
