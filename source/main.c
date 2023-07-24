/******************************************************************************
* File Name: main.c
*
* Description:
*   This is the main application file which initializes the BSP and starts
*   the RTOS scheduler. It starts a task that connects to the Wi-Fi Access
*   Point, starts the mDNS (multicast DNS) and then starts the HTTP server
*   in secure mode. All the HTTP security keys are configured in the file
*   secure_http_server.h using openSSL utility. See README.md to understand
*   how the security keys are generated.
*
* Related Document: See README.md
*
*
*******************************************************************************
* $ Copyright 2021-2023 Cypress Semiconductor $
*******************************************************************************/

/* Header file includes */

#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "secure_http_server.h"
#include <FreeRTOS.h>
#include <task.h>

/******************************************************************************
* Macros
******************************************************************************/
/* RTOS related macros. */
#define HTTPS_SERVER_TASK_STACK_SIZE        (5 * 1024)
#define HTTPS_SERVER_TASK_PRIORITY          (1)

/*******************************************************************************
* Global Variables
********************************************************************************/
/* This enables RTOS aware debugging */
volatile int uxTopUsedPriority;

/* HTTPS server task handle. */
TaskHandle_t https_server_task_handle;

/*******************************************************************************
 * Function Name: main
 *******************************************************************************
 * Summary:
 *  Entry function for the application.
 *  This function initializes the BSP, UART port for debugging, initializes the
 *  user LED on the kit, and starts the RTOS scheduler.
 *
 * Parameters:
 *  void
 *
 * Return:
 *  int: Should never return.
 *
 *******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    /* This enables RTOS aware debugging in OpenOCD */
    uxTopUsedPriority = configMAX_PRIORITIES - 1;

    /* Initialize the Board Support Package (BSP) */
    result = cybsp_init();

    CHECK_RESULT(result);

    /* Enable global interrupts */
    __enable_irq();

    /* Initialize retarget-io to use the debug UART port */
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);

    /* Initialize the User LED. */
    cyhal_gpio_init(CYBSP_LED2, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, CYBSP_LED_STATE_OFF);

    /* \x1b[2J\x1b[;H - ANSI ESC sequence to clear screen */
    APP_INFO(("\x1b[2J\x1b[;H"));
    APP_INFO(("===================================\n"));
    APP_INFO(("CYW43907 Secure HTTP Server\n"));
    APP_INFO(("===================================\n\n"));

    /* Starts the HTTPS server in secure mode. */
    xTaskCreate(https_server_task, "HTTPS Server", HTTPS_SERVER_TASK_STACK_SIZE, NULL,
                HTTPS_SERVER_TASK_PRIORITY, &https_server_task_handle);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    /* Should never get here */
    CY_ASSERT(0);
}

/* [] END OF FILE */


