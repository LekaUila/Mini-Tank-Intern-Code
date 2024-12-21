/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileAP.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:08:19 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 18:42:37 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILEAP
# define PROJECTILEAP

# include "Projectile.hpp"

class ProjectileAP : public Projectile
{
private:
	float	damageHP;
	float	damageArmor;
	float	penetration;
public:
	ProjectileAP();
	~ProjectileAP();
};







#endif