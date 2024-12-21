/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:08:19 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:22:47 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE
# define PROJECTILE

#include "../header_tank.hpp"

class Projectile
{
private:
	float	damageHP;
	float	damageArmor;
	float	penetration;
	int		id;
public:
	Projectile();
	Projectile(float dHP, float dArmor, float p, int id);
	virtual ~Projectile() = 0;
	float calculDamageHP(float	armorP);
	float calculDamageArmor(float	armorP);
	int	getId();
};







#endif