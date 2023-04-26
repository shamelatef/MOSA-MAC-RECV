/*
 * includes.h
 *
 *  Created on: Apr 22, 2023
 *      Author: shame
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_


// Standard includes
#include <time.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Simplelink includes
#include "simplelink.h"

//Driverlib includes
#include "hw_types.h"
#include "hw_ints.h"
#include "interrupt.h"
#include "utils.h"
#include "uart.h"
#include "hw_memmap.h"
#include "prcm.h"
#include "rom.h"
#include "rom_map.h"


//Common interface includes
#include "common.h"
#ifndef NOTERM
#include "uart_if.h"
#endif

#include "pinmux.h"


#define APPLICATION_NAME        " MOSA   "
#define APPLICATION_VERSION     "1.4.0"

#define PREAMBLE            1        /* Preamble value 0- short, 1- long */
#define CPU_CYCLES_1MSEC (80*1000)

// Application specific status/error codes
typedef enum{
    // Choosing -0x7D0 to avoid overlap w/ host-driver's error codes
    TX_CONTINUOUS_FAILED = -0x7D0,
    RX_STATISTICS_FAILED = TX_CONTINUOUS_FAILED - 1,
    DEVICE_NOT_IN_STATION_MODE = RX_STATISTICS_FAILED - 1,

    STATUS_CODE_MAX = -0xBB8
}e_AppStatusCodes;


typedef struct
{
    int choice;
    int channel;
    int packets;
    SlRateIndex_e rate;
    int Txpower;
}UserIn;



#endif /* INCLUDES_H_ */
