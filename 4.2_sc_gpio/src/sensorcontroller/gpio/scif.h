/** \mainpage Driver Overview
  *
  * \section section_drv_info Driver Information
  * This Sensor Controller Interface driver has been generated by the Texas Instruments Sensor Controller
  * Studio tool:
  * - <b>Project name</b>:     LED Blinker for LaunchPad
  * - <b>Project file</b>:     C:/Users/chenfei/Documents/Texas Instruments/Sensor Controller Studio/examples/led_blinker_launchpad/led_blinker_launchpad.scp
  * - <b>Code prefix</b>:      -
  * - <b>Operating system</b>: TI-RTOS
  * - <b>Tool version</b>:     1.5.0.188
  * - <b>Tool patches</b>:     None
  * - <b>Target chip</b>:      CC2640R2F, revision -, package QFN48 7x7 RGZ
  * - <b>Created</b>:          2017-11-27 09:05:51.787
  * - <b>Computer</b>:         CHENFEI-PC
  * - <b>User</b>:             chenfei
  *
  * No user-provided resource definitions were used to generate this driver.
  *
  * No user-provided procedure definitions were used to generate this driver.
  *
  * Do not edit the generated source code files other than temporarily for debug purposes. Any
  * modifications will be overwritten by the Sensor Controller Studio when generating new output.
  *
  * \section section_drv_modules Driver Modules
  * The driver is divided into three modules:
  * - \ref module_scif_generic_interface, providing the API for:
  *     - Initializing and uninitializing the driver
  *     - Task control (for starting, stopping and executing Sensor Controller tasks)
  *     - Task data exchange (for producing input data to and consume output data from Sensor Controller
  *       tasks)
  * - \ref module_scif_driver_setup, containing:
  *     - The AUX RAM image (Sensor Controller code and data)
  *     - I/O mapping information
  *     - Task data structure information
  *     - Driver setup data, to be used in the driver initialization
  *     - Project-specific functionality
  * - \ref module_scif_osal, for flexible OS support:
  *     - Interfaces with the selected operating system
  *
  * It is possible to use output from multiple Sensor Controller Studio projects in one application. Only
  * one driver setup may be active at a time, but it is possible to switch between these setups. When
  * using this option, there is one instance of the \ref module_scif_generic_interface and
  * \ref module_scif_osal modules, and multiple instances of the \ref module_scif_driver_setup module.
  * This requires that:
  * - The outputs must be generated using the same version of Sensor Controller Studio
  * - The outputs must use the same operating system
  * - The outputs must use different source code prefixes (inserted into all globals of the
  *   \ref module_scif_driver_setup)
  *
  *
  * \section section_project_info Project Description
  * Demonstrates LED blinking on the LaunchPad.
  * 
  * The Sensor Controller blinks the red LED, and notifies the System CPU application for every 16th
  * iteration. This causes the System CPU application to toggle the green LED.
  * The System CPU application also demonstrates starting and stopping of tasks, triggered by
  * push-buttons on the LaunchPad.
  * 
  * See the header in the application source file ("main.c" or similar) for further details and
  * instructions. This file is located in the source code output directory.
  *
  *
  * \subsection section_io_mapping I/O Mapping
  * Task I/O functions are mapped to the following pins:
  * - LED Blinker:
  *     - <b>O: LED control pin</b>: DIO6
  *
  *
  * \section section_task_info Task Description(s)
  * This driver supports the following task(s):
  *
  *
  * \subsection section_task_desc_led_blinker LED Blinker
  * Blinks LEDs on the SmartRF06 Evaluation Board.
  * 
  * A single LED is blinked, and a counter value is outputted periodically to the System CPU.
  *
  */




/** \addtogroup module_scif_driver_setup Driver Setup
  *
  * \section section_driver_setup_overview Overview
  *
  * This driver setup instance has been generated for:
  * - <b>Project name</b>:     LED Blinker for LaunchPad
  * - <b>Code prefix</b>:      -
  *
  * The driver setup module contains the generated output from the Sensor Controller Studio project:
  * - Location of task control and scheduling data structures in AUX RAM
  * - The AUX RAM image, and the size the image
  * - Task data structure information (location, size and buffer count)
  * - I/O pin mapping translation table
  * - Task resource initialization and uninitialization functions
  * - Hooks for run-time logging
  *
  * @{
  */
#ifndef SCIF_H
#define SCIF_H

#include <stdint.h>
#include <stdbool.h>
#include "scif_framework.h"
#include "scif_osal_tirtos.h"


/// Target chip name
#define SCIF_TARGET_CHIP_NAME_CC2640R2F
/// Target chip package
#define SCIF_TARGET_CHIP_PACKAGE_QFN48_7X7_RGZ

/// Number of tasks implemented by this driver
#define SCIF_TASK_COUNT 1

/// LED Blinker: Task ID
#define SCIF_LED_BLINKER_TASK_ID 0


/// LED Blinker I/O mapping: LED control pin
#define SCIF_LED_BLINKER_DIO_O_LED_CTRL 6


// All shared data structures in AUX RAM need to be packed
#pragma pack(push, 2)


/// LED Blinker: Task output data structure
typedef struct {
    uint16_t counter; ///< Incremented each time the driver is alerted
} SCIF_LED_BLINKER_OUTPUT_T;


/// LED Blinker: Task state structure
typedef struct {
    uint16_t counter; ///< Incremented once per task execution
} SCIF_LED_BLINKER_STATE_T;


/// Sensor Controller task data (configuration, input buffer(s), output buffer(s) and internal state)
typedef struct {
    struct {
        SCIF_LED_BLINKER_OUTPUT_T output;
        SCIF_LED_BLINKER_STATE_T state;
    } ledBlinker;
} SCIF_TASK_DATA_T;

/// Sensor Controller task generic control (located in AUX RAM)
#define scifTaskData    (*((volatile SCIF_TASK_DATA_T*) 0x400E00EA))


// Initialized internal driver data, to be used in the call to \ref scifInit()
extern const SCIF_DATA_T scifDriverSetup;


// Restore previous struct packing setting
#pragma pack(pop)


// AUX I/O re-initialization functions
void scifReinitTaskIo(uint32_t bvTaskIds);


// RTC-based tick generation control
void scifStartRtcTicks(uint32_t tickStart, uint32_t tickPeriod);
void scifStartRtcTicksNow(uint32_t tickPeriod);
void scifStopRtcTicks(void);


#endif
//@}


// Generated by CHENFEI-PC at 2017-11-27 09:05:51.787
