/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflandri <liam.flandrinck.58@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:42:46 by lflandri          #+#    #+#             */
/*   Updated: 2025/05/14 13:54:42 by lflandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE
# define DEFINE

// # define SELF_ID 0

# define RECONNECTION_TIME 10

/*Resolution*/
# define RESOLUTION_X 850
# define RESOLUTION_Y 540
// # define RESOLUTION_X 1920
// # define RESOLUTION_Y 1080

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
# define INTERFACE_RADAR_DETECTION_DISTANCE 10
# define INTERFACE_RADAR_SPEED 40
# define INTERFACE_RADAR_MAIN_COLOR 0, 255, 0
# define INTERFACE_RADAR_LINE_NUMBER 400
# define INTERFACE_RADAR_LINE_SPACE 40
# define INTERFACE_RADAR_LINE_COLOR INTERFACE_RADAR_MAIN_COLOR
# define INTERFACE_TANK_MAIN_COLOR 0, 255, 0
# define INTERFACE_TANK_LIFE_BAR_BACK 255, 0, 0
# define INTERFACE_TANK_LIFE_BAR_FRONT INTERFACE_TANK_MAIN_COLOR
# define INTERFACE_FONT FONT_PATH_GUNPLAY_RG
# define INTERFACE_RELOADING_TIMER_PRECISION 10
# define INTERFACE_CATERPILLAR_TIMER_PRECISION 10
# define INTERFACE_PROJECTILE_SELECTOR_BASIC_COLOR 0, 100, 0
# define INTERFACE_PROJECTILE_SELECTOR_UNDERLINE_COLOR 0, 255 , 0
# define INTERFACE_PROJECTILE_SELECTOR_NO_ARMOR_COLOR 50, 50, 50

/*Projectil*/
# define STAT_PROJECTIL_AP_ID 0
# define STAT_PROJECTIL_AP_PENETRATION 0.01
# define STAT_PROJECTIL_AP_ARMOR_DAMAGE 15
# define STAT_PROJECTIL_AP_LIFE_DAMAGE 10
# define STAT_PROJECTIL_AP_NUMBER_AT_START -1

# define STAT_PROJECTIL_APCR_ID 1
# define STAT_PROJECTIL_APCR_PENETRATION 0.20
# define STAT_PROJECTIL_APCR_ARMOR_DAMAGE 20
# define STAT_PROJECTIL_APCR_LIFE_DAMAGE 10
# define STAT_PROJECTIL_APCR_NUMBER_AT_START 0

# define STAT_PROJECTIL_HE_ID 2
# define STAT_PROJECTIL_HE_PENETRATION 0
# define STAT_PROJECTIL_HE_ARMOR_DAMAGE 5
# define STAT_PROJECTIL_HE_LIFE_DAMAGE 25
# define STAT_PROJECTIL_HE_NUMBER_AT_START 0

# define STAT_PROJECTIL_HEAT_ID 3
# define STAT_PROJECTIL_HEAT_PENETRATION 0.20
# define STAT_PROJECTIL_HEAT_ARMOR_DAMAGE 20
# define STAT_PROJECTIL_HEAT_LIFE_DAMAGE 25
# define STAT_PROJECTIL_HEAT_NUMBER_AT_START 0





#endif