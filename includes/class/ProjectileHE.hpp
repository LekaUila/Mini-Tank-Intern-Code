/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileHE.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:08:19 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:45:11 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILEHE
# define PROJECTILEHE

# include "Projectile.hpp"

class ProjectileHE : public Projectile
{
private:
	float	damageHP;
	float	damageArmor;
	float	penetration;
public:
	ProjectileHE();
	~ProjectileHE();
};







#endif