/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileHEAT.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:47:35 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:45:18 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILEHEAT
# define PROJECTILEHEAT

# include "Projectile.hpp"

class ProjectileHEAT : public Projectile
{
private:
	float	damageHP;
	float	damageArmor;
	float	penetration;
public:
	ProjectileHEAT();
	~ProjectileHEAT();
};







#endif