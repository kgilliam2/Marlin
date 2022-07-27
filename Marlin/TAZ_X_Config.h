#include "src/core/macros.h"

//NOTE: This repo is based on drunken octopus MASTER!!! Not bugfix.
#define TAZX_HEX_DIRECT   1
#define TAZX_E3DV6_BOWDEN 2
#define TAZX_MOAR_DIRECT  3

#define TAZ_X_CURRENT_CFG TAZX_E3DV6_BOWDEN

#define BOWDEN true
#define DIRECT false



#if ( (TAZ_X_CURRENT_CFG == TAZX_HEX_DIRECT) || \
      (TAZ_X_CURRENT_CFG == TAZX_MOAR_DIRECT) )
    #define IS_BOWDEN false
#elif (TAZ_X_CURRENT_CFG == TAZX_E3DV6_BOWDEN)
    #define IS_BOWDEN true
#endif

#if IS_BOWDEN
    #define TAZX_E0_INVERT false//true
    #define EXT_GEAR_RATIO 5.18
#else
    #define TAZX_E0_INVERT false
    #define EXT_GEAR_RATIO 1
#endif

#define E0_FEEDRATE (unsigned int)( 60 * EXT_GEAR_RATIO ) //was 60 7/26/22


/* Machine Name String */
#if (TAZ_X_CURRENT_CFG == TAZX_HEX_DIRECT)
    #define TAZX_MACHINE_NAME STRINGIFY_ (TAZX_HEX_DIRECT)
#elif (TAZ_X_CURRENT_CFG == TAZX_E3DV6_BOWDEN)
    #define TAZX_MACHINE_NAME STRINGIFY_ (TAZX_E3DV6_BOWDEN)
#endif

/* Extruder motor current */
#define BONDTECH_QR_EXT_CURR 1200
#define DIRECT_EXT_CURR

#if (TAZ_X_CURRENT_CFG == TAZX_HEX_DIRECT)
    #define TAZX_E0_CURR  DIRECT_EXT_CURR
#elif (TAZ_X_CURRENT_CFG == TAZX_E3DV6_BOWDEN)
    #define TAZX_E0_CURR BONDTECH_QR_EXT_CURR
#endif


/* Hotend max temp */
#define HEXAGON_MAX_TEMP 305
#define E3DV6_MAX_TEMP   285

#if (TAZ_X_CURRENT_CFG == TAZX_HEX_DIRECT)
    #define TAZX_HOTEND_MAXTEMP HEXAGON_MAX_TEMP
#elif (TAZ_X_CURRENT_CFG == TAZX_E3DV6_BOWDEN)
    #define TAZX_HOTEND_MAXTEMP E3DV6_MAX_TEMP
#endif

//#define DEFAULT_AXIS_STEPS_PER_UNIT   {100.5,100.5,1600,}

/* E Steps per mm*/
#define HEXAGON_E_STEPS_PER_UNIT 761.48
#define BONDTECH_BOWDEN_E_STEPS_PER_UNIT   492.45 //For 2.85mm filament

#if (TAZ_X_CURRENT_CFG == TAZX_HEX_DIRECT)
    #define TAZX_E_STEPS_PER_UNIT HEXAGON_E_STEPS_PER_UNIT
#elif (TAZ_X_CURRENT_CFG == TAZX_E3DV6_BOWDEN)
    #define TAZX_E_STEPS_PER_UNIT BONDTECH_BOWDEN_E_STEPS_PER_UNIT
#endif

/* Hotend PID gains */
#define HEXAGON_Kp 28.20
#define HEXAGON_Ki 1.61
#define HEXAGON_Kd 123.50

#define E3DV6_Kp 28.20
#define E3DV6_Ki 1.61
#define E3DV6_Kd 123.50

#if (TAZ_X_CURRENT_CFG == TAZX_HEX_DIRECT)
    #define TAZX_HOTEND_Kp HEXAGON_Kp
    #define TAZX_HOTEND_Ki HEXAGON_Ki
    #define TAZX_HOTEND_Kd HEXAGON_Kd
#elif (TAZ_X_CURRENT_CFG == TAZX_E3DV6_BOWDEN)
    #define TAZX_HOTEND_Kp E3DV6_Kp
    #define TAZX_HOTEND_Ki E3DV6_Ki
    #define TAZX_HOTEND_Kd E3DV6_Kd
#endif


// Homing speeds (mm/min)
#define HOMING_FEEDRATE_XY (50*60)
#define HOMING_FEEDRATE_Z  (6*60)