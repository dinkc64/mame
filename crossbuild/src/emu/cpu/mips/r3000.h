/***************************************************************************

    r3000.h
    Interface file for the portable MIPS R3000 emulator.
    Written by Aaron Giles

***************************************************************************/

#ifndef _R3000_H
#define _R3000_H

#include "cpuintrf.h"


/***************************************************************************
    COMPILE-TIME DEFINITIONS
***************************************************************************/


/***************************************************************************
    REGISTER ENUMERATION
***************************************************************************/

enum
{
	R3000_PC=1,R3000_SR,
	R3000_R0,R3000_R1,R3000_R2,R3000_R3,R3000_R4,R3000_R5,R3000_R6,R3000_R7,
	R3000_R8,R3000_R9,R3000_R10,R3000_R11,R3000_R12,R3000_R13,R3000_R14,R3000_R15,
	R3000_R16,R3000_R17,R3000_R18,R3000_R19,R3000_R20,R3000_R21,R3000_R22,R3000_R23,
	R3000_R24,R3000_R25,R3000_R26,R3000_R27,R3000_R28,R3000_R29,R3000_R30,R3000_R31
};


/***************************************************************************
    INTERRUPT CONSTANTS
***************************************************************************/

#define R3000_IRQ0		0		/* IRQ0 */
#define R3000_IRQ1		1		/* IRQ1 */
#define R3000_IRQ2		2		/* IRQ2 */
#define R3000_IRQ3		3		/* IRQ3 */
#define R3000_IRQ4		4		/* IRQ4 */
#define R3000_IRQ5		5		/* IRQ5 */


/***************************************************************************
    STRUCTURES
***************************************************************************/

struct r3000_config
{
	UINT8		hasfpu;			/* 1 if we have an FPU, 0 otherwise */
	size_t		icache;			/* code cache size */
	size_t		dcache;			/* data cache size */
};


/***************************************************************************
    PUBLIC FUNCTIONS
***************************************************************************/

extern void r3000be_get_info(UINT32 state, cpuinfo *info);
extern void r3000le_get_info(UINT32 state, cpuinfo *info);

extern void r3041be_get_info(UINT32 state, cpuinfo *info);
extern void r3041le_get_info(UINT32 state, cpuinfo *info);

#endif /* _JAGUAR_H */
