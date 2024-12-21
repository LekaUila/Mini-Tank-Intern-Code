/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:12:52 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:21:39 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/class/Projectile.hpp"

Projectile::Projectile(/* args */)
{
	this->penetration = 0;
	this->damageHP = 0;
	this->damageArmor = 0;
	this->id = -1;
}

Projectile::Projectile(float dHP, float dArmor, float p, int id)
{
	this->damageHP = dHP;
	this->damageArmor = dArmor;
	this->penetration = p;
	this->id = id;
}


Projectile::~Projectile()
{
}

float Projectile::calculDamageArmor(float	armorP)
{
	if (armorP)
		return this->damageArmor;
	return 0;
	 
}

float Projectile::calculDamageHP(float	armorP)
{
	if (armorP)
	{
		if ( (1.0f - armorP) + this->penetration >= 1)
			return this->damageHP;
		return this->damageHP * (this->penetration + (1.0f - armorP));
	}
	 return this->damageHP;
}

int	Projectile::getId()
{
	return this->id;
}

