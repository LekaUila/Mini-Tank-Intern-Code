/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjectileManager.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:07:04 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 19:34:17 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTILE_MANAGER
# define PROJECTILE_MANAGER

# include "ProjectileAP.hpp"
# include "ProjectileAPCR.hpp"
# include "ProjectileHE.hpp"
# include "ProjectileHEAT.hpp"

class ProjectileManager
{
private:
	
	std::vector<std::pair<int, Projectile *> >listProjectile;
	int	slectionIndice;

	
public:
	ProjectileManager(/* args */);
	~ProjectileManager();
	Projectile *getProjectilById(unsigned int id);
	void	reset();
	Projectile *shoot();
	void		addProjectile(unsigned int id, unsigned int number);

};




#endif