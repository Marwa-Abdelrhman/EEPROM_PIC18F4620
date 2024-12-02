/* 
 * File:   mcal_interrupt_generated_cfg.h
 * Author: Marwa Abdelrahman
 *
 * Created on September 30, 2024, 2:25 PM
 */

#ifndef MCAL_INTERRUPT_GENERATED_CFG_H
#define	MCAL_INTERRUPT_GENERATED_CFG_H
/*.....................................Includes.....................................*/

#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"

/*.....................................Macros Declarations.....................................*/
#define INTERRUPT_FEATURE_ENABLE    1U
#define INTERRUPT_FEATURE_DISABLE   0


//#define INTERRUPT_PRIORITY_LEVELS_ENABLE                           INTERRUPT_FEATURE_ENABLE   
#define EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE                       INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_RBx_OnCahnge_FEATURE_ENABLE               INTERRUPT_FEATURE_ENABLE
/*.....................................Macros Functions Declarations.....................................*/




/*.....................................Data Types Declarations.....................................*/
/*.....................................Functions Declarations.....................................*/

#endif	/* MCAL_INTERRUPT_GENERATED_CFG_H */

