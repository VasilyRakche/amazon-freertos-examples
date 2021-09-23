/*
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/**
 * @file ota_demo_config.h
 * @brief Configuration options for the OTA related demos.
 */

#ifndef OTA_DEMO_CONFIG_H_
#define OTA_DEMO_CONFIG_H_

/**
 * @brief Certificate used for validating code signing signatures in the OTA PAL.
 */
#ifndef otapalconfigCODE_SIGNING_CERTIFICATE
    #define otapalconfigCODE_SIGNING_CERTIFICATE    "-----BEGIN CERTIFICATE-----\n" \
        "MIIBjTCCATKgAwIBAgIUN2bCrT68R86a6w87QO4W1+5rEUkwCgYIKoZIzj0EAwIw\n" \
        "MzExMC8GA1UEAwwodmFzaWxpamUucmFrY2V2aWNAYXVnbWVudGVkLXJvYm90aWNz\n" \
        "LmNvbTAeFw0yMTA5MDYwOTU1NDhaFw0yMjA5MDYwOTU1NDhaMDMxMTAvBgNVBAMM\n" \
        "KHZhc2lsaWplLnJha2NldmljQGF1Z21lbnRlZC1yb2JvdGljcy5jb20wWTATBgcq\n" \
        "hkjOPQIBBggqhkjOPQMBBwNCAASmuFzLWDLWicjYZuJQkdJdCUFwZtBePCemHuJK\n" \
        "xl+JGeE3aWlivKvEgEXJ1ToQcKhtl3an9+0Y74b5Ovf01qfnoyQwIjALBgNVHQ8E\n" \
        "BAMCB4AwEwYDVR0lBAwwCgYIKwYBBQUHAwMwCgYIKoZIzj0EAwIDSQAwRgIhAN5r\n" \
        "267gN4+pWIVVzTTcf7jKdqzlSw0S2zZJA9oCYQ0qAiEA35pAVfsqVtEG1PqYN87U\n" \
        "TLiJEF4R85+LC3P8CXaPzkQ=\n" \
        "-----END CERTIFICATE-----\n"
#endif

/**
 * @brief Major version of the firmware.
 *
 * This is used in the OTA demo to set the appFirmwareVersion variable
 * that is declared in the ota_appversion32.h file in the OTA library.
 */
#ifndef APP_VERSION_MAJOR
    #define APP_VERSION_MAJOR    0
#endif

/**
 * @brief Minor version of the firmware.
 *
 * This is used in the OTA demo to set the appFirmwareVersion variable
 * that is declared in the ota_appversion32.h file in the OTA library.
 */
#ifndef APP_VERSION_MINOR
    #define APP_VERSION_MINOR    9
#endif

/**
 * @brief Build version of the firmware.
 *
 * This is used in the OTA demo to set the appFirmwareVersion variable
 * that is declared in the ota_appversion32.h file in the OTA library.
 */
#ifndef APP_VERSION_BUILD
    #define APP_VERSION_BUILD    3
#endif

/**
 * @brief Timeout for which MQTT library keeps polling the transport interface,
 * when no byte is received.
 * The timeout is honoured only after the first byte is read and while remaining
 * bytes are read from network interface. Keeping this timeout to a sufficiently
 * large value so as to account for delay of receipt of a large block of message.
 */
#define MQTT_RECV_POLLING_TIMEOUT_MS            ( 1000U )

/**
 * @brief The length of the queue used to hold commands for the agent.
 */
#define MQTT_AGENT_COMMAND_QUEUE_LENGTH         ( 25 )

/**
 * @brief Dimensions the buffer used to serialise and deserialise MQTT packets.
 * @note Specified in bytes.  Must be large enough to hold the maximum
 * anticipated MQTT payload.
 */
#define MQTT_AGENT_NETWORK_BUFFER_SIZE          ( 5000 )

/**
 * @breif Maximum time MQTT agent waits in the queue for any pending MQTT
 * operations. The wait time is kept smallest possible to increase the
 * responsiveness of MQTT agent while processing  pending MQTT operations as
 * well as receive packets from network.
 */
#define MQTT_AGENT_MAX_EVENT_QUEUE_WAIT_TIME    ( 1U )

#endif /* OTA_DEMO_CONFIG_H_ */
