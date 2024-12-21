/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:42:46 by lflandri          #+#    #+#             */
/*   Updated: 2024/12/21 17:06:32 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE
# define DEFINE

/*Font path*/
# define FONT_PATH_ARMALITE_RIFLE "../font/armalite-rifle/armalite.tff"
# define FONT_PATH_BLACK_OPS_ONE "../font/black-ops-one/BlackOpsOne-Regular.tff"
# define FONT_PATH_GUNPLAY_3D "../font/gunplay/gunplay 3d.otf"
# define FONT_PATH_GUNPLAY_RG "../font/gunplay/gunplay rg.otf"
# define FONT_PATH_WARBAND_STENCIL "../font/warband-stencil/Warband Stencil.otf"

/*TANK STAT*/
# define STAT_TANK_ARMOR_FRONT 100
# define STAT_TANK_ARMOR_BACK 25
# define STAT_TANK_ARMOR_SIDE 50
# define STAT_TANK_LIFE 100
# define STAT_TANK_RELOAD_TIME 30
# define STAT_TANK_CATTERPILAR_REPARATION_TIME 90

/*INTERFACE*/
# define INTERFACE_RADAR_SPEED 2
# define INTERFACE_RADAR_MAIN_COLOR 0, 255, 0
# define INTERFACE_RADAR_LINE_NUMBER 200
# define INTERFACE_RADAR_LINE_COLOR INTERFACE_RADAR_MAIN_COLOR
# define INTERFACE_TANK_MAIN_COLOR 0, 255, 0
# define INTERFACE_TANK_LIFE_BAR_BACK 255, 0, 0
# define INTERFACE_TANK_LIFE_BAR_FRONT INTERFACE_TANK_MAIN_COLOR
# define INTERFACE_FONT FONT_PATH_GUNPLAY_RG
# define INTERFACE_RELOADING_TIMER_PRECISION 10
# define INTERFACE_CATERPILLAR_TIMER_PRECISION 10






#endif