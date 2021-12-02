/******************************************************************************
* File Name: secure_http_server.h
*
* Description: This file contains configuration parameters for the secure HTTP
* server along with the HTML page that the server will host.
*
* Related Document: See README.md
*******************************************************************************
* $ Copyright 2021 Cypress Semiconductor $
*******************************************************************************/

/*******************************************************************************
* Include guard
*******************************************************************************/
#ifndef SECURE_HTTP_SERVER_H_
#define SECURE_HTTP_SERVER_H_

/* FreeRTOS header file */
#include <FreeRTOS.h>
#include <task.h>
#include "cy_wcm.h"
#include "cybsp.h"
#include "cy_lwip.h"
#include "cyhal_gpio.h"

/* Wi-Fi Credentials: Modify WIFI_SSID and WIFI_PASSWORD to match your Wi-Fi network
 * Credentials.
 */
#define WIFI_SSID                               "WIFI_SSID"
#define WIFI_PASSWORD                           "WIFI_PASSWORD"

/* Security type of the Wi-Fi access point. See 'cy_wcm_security_t' structure
 * in "cy_wcm.h" for more details.
 */
#define WIFI_SECURITY_TYPE                       CY_WCM_SECURITY_WPA2_AES_PSK

#define MAX_WIFI_RETRY_COUNT                     (3)

#define CHECK_RESULT(x)                          do { if (CY_RSLT_SUCCESS != x) { CY_ASSERT(0); } } while(0);
#define APP_INFO(x)                              do { printf("Info: "); printf x; } while(0);
#define ERR_INFO(x)                              do { printf("Error: "); printf x; } while(0);

#define ERR_INFO_MDNS(eval, msg, ret)            if ((eval))           \
                                                 {                     \
                                                      ERR_INFO((msg)); \
                                                      return (ret);    \
                                                 }

#define PRINT_AND_ASSERT(result, msg, args...)   do                                 \
                                                 {                                  \
                                                     if (CY_RSLT_SUCCESS != result) \
                                                     {                              \
                                                         ERR_INFO((msg, ## args));  \
                                                         CY_ASSERT(0);              \
                                                     }                              \
                                                 } while(0);

#define HTTPS_SERVER_NAME                        "mysecurehttpserver"
#define MDNS_TTL_SECONDS                         (255)
#define LED_STATUS_ON                            "ON"
#define LED_STATUS_OFF                           "OFF"
#define MAX_LED_STATUS_LENGTH                    (3)
#define HTTPS_PORT                               (50007)
#define MAX_SOCKETS                              (2)
#define HTTPS_GET_RESPONSE                       "Hello - Message from HTTPS server!"
#define REGISTER_RESOURCE_TASK_STACK_SIZE        (1024)
#define REGISTER_RESOURCE_TASK_PRIORITY          (tskIDLE_PRIORITY)
#define REGISTER_RESOURCE_QUEUE_LENGTH           (1)
#define NEW_RESOURCE_NAME_LENGTH                 (30)
#define HTTPS_RESOURCE_PUT_ERROR                 "Maximum resource name length is %d characters."
#define HTTPS_REQUEST_HANDLE_SUCCESS             (0)
#define HTTPS_REQUEST_HANDLE_ERROR               (-1)

#define HTTPS_STARTUP_WEBPAGE \
              "<!DOCTYPE html>" \
              "<html>" \
              "<head>" \
              "<title>HTTPS Server Demo</title>" \
              "</head>" \
              "<body>" \
                "<h1>HTTPS Server Demo</h1>" \
                "<form method=\"get\">" \
                    "<fieldset>" \
                        "<legend>HTTPS GET</legend>" \
                        "<input type=\"submit\" value=\"Get LED status\"/>" \
                        "<input type=\"text\" name=\"led_status\" value=\"%s\" size=\"3\" readonly/></br></br>" \
                    "</fieldset>" \
                    "</br>" \
                "</form>" \
                "<form method=\"post\">" \
                    "<fieldset>" \
                        "<legend>HTTPS POST</legend>" \
                        "<input type=\"submit\" name=\"toggle_led\" value=\"Toggle LED\"/></br></br>" \
                    "</fieldset>" \
                    "</br>" \
                "</form>" \
              "</body>" \
              "</html>"

#define MAX_HTTP_RESPONSE_LENGTH                 (sizeof(HTTPS_STARTUP_WEBPAGE) + sizeof(MAX_LED_STATUS_LENGTH) + 1)

/*******************************************************************************
* Function Prototypes
********************************************************************************/
void https_server_task(void *arg);
cy_rslt_t wifi_connect(void);
cy_rslt_t mdns_responder_start(void);

#endif /* SECURE_HTTP_SERVER_H_ */


/* [] END OF FILE */

