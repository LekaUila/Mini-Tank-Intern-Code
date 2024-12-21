/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileAPCR.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:08:19 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:45:01 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILEAPCR
# define PROJECTILEAPCR

# include "Projectile.hpp"

class ProjectileAPCR : public Projectile
{
private:
	float	damageHP;
	float	damageArmor;
	float	penetration;
public:
	ProjectileAPCR();
	~ProjectileAPCR();
};







#endif