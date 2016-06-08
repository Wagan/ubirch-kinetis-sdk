/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __USB_DEVICE_CCID_H__
#define __USB_DEVICE_CCID_H__

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief MAX maxmessagelength of the CCID device. */
#define USB_DEVICE_CONFIG_CCID_MAX_MESSAGE_LENGTH (271U)

/*! @brief CCID device class code */
#define USB_DEVICE_CCID_CLASS_CODE (0x0BU)
/*! @brief CCID device subclass code */
#define USB_DEVICE_CCID_SUBCLASS_CODE (0x00U)
/*! @brief CCID device protocol code */
#define USB_DEVICE_CCID_PROTOCOL_CODE (0x00U)

/* CCID device class-specific descritpor length */
#define USB_DEVICE_CCID_DESCRIPTOR_LENGTH (0x36U)
/* CCID device class-specific descritpor type */
#define USB_DEVICE_CCID_DESCRIPTOR_TYPE (0x21U)

/* The voltage support in CCID device class-specific descritpor */
#define USB_DEVICE_CCID_DESCRIPTOR_VOLTAGE_SUPPORT_BM_5V (0x01U)
#define USB_DEVICE_CCID_DESCRIPTOR_VOLTAGE_SUPPORT_BM_3V (0x02U)
#define USB_DEVICE_CCID_DESCRIPTOR_VOLTAGE_SUPPORT_BM_1V8 (0x04U)

/* The protocol in CCID device class-specific descritpor */
#define USB_DEVICE_CCID_DESCRIPTOR_PROTOCOLS_BM_T0 (0x00000001U)
#define USB_DEVICE_CCID_DESCRIPTOR_PROTOCOLS_BM_T1 (0x00000002U)

/* The mechanical in CCID device class-specific descritpor */
#define USB_DEVICE_CCID_DESCRIPTOR_MECHANICAL_BM_NO (0x00000000U)
#define USB_DEVICE_CCID_DESCRIPTOR_MECHANICAL_BM_ACCEPT (0x00000001U)
#define USB_DEVICE_CCID_DESCRIPTOR_MECHANICAL_BM_EJECTION (0x00000002U)
#define USB_DEVICE_CCID_DESCRIPTOR_MECHANICAL_BM_CAPTURE (0x00000004U)
#define USB_DEVICE_CCID_DESCRIPTOR_MECHANICAL_BM_LOCK_UNLCOK (0x00000008U)

/* The features in CCID device class-specific descritpor */
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_NO (0x00000000U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_CONFIG_BASED_ON_ATR (0x00000002U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_ACTIVE_ON_INSERTING (0x00000004U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_VOLTAGE_SELECTION (0x00000008U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_FREQUENCY_CHANGE (0x00000010U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_BAUD_RATE_CHANGE (0x00000020U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_NEGOTIATION (0x00000040U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_PPS (0x00000080U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_CAN_SET_IN_STOP_MODE (0x00000100U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_NAD_VLAUE (0x00000200U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_AUTO_IFSD_EXCHANGE_AS_FIRST (0x00000400U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_TPDU_LEVEL_EXCHANGES (0x00010000U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_SHORT_APDU_LEVEL_EXCHANGES (0x00020000U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_SHORT_EXTENDED_APDU_LEVEL_EXCHANGES (0x00040000U)
#define USB_DEVICE_CCID_DESCRIPTOR_FEATURES_BM_SUPPORT_SUPPEND (0x00100000U)

/* The PIN support in CCID device class-specific descritpor */
#define USB_DEVICE_CCID_DESCRIPTOR_PIN_SUPPORT_BM_NO (0x00U)
#define USB_DEVICE_CCID_DESCRIPTOR_PIN_SUPPORT_BM_VERIFICATION_SUPPORTED (0x01U)
#define USB_DEVICE_CCID_DESCRIPTOR_PIN_SUPPORT_BM_MODIFICATION_SUPPORTED (0x02U)

/*! @brief CCID device class-specific control pipe requests */
#define USB_DEVICE_CCID_ABORT (0x01U)
#define USB_DEVICE_CCID_GET_CLOCK_FREQUENCIES (0x02U)
#define USB_DEVICE_CCID_GET_DATA_RATES (0x03U)

/*! @brief The message type of CCID device class-specific bulk-out pipe(Command pipe) */
#define USB_DEVICE_CCID_PC_TO_RDR_ICCPOWERON (0x62U)
#define USB_DEVICE_CCID_PC_TO_RDR_ICCPOWEROFF (0x63U)
#define USB_DEVICE_CCID_PC_TO_RDR_GETSLOTSTATUS (0x65U)
#define USB_DEVICE_CCID_PC_TO_RDR_XFRBLOCK (0x6FU)
#define USB_DEVICE_CCID_PC_TO_RDR_GETPARAMETERS (0x6CU)
#define USB_DEVICE_CCID_PC_TO_RDR_RESETPARAMETERS (0x6DU)
#define USB_DEVICE_CCID_PC_TO_RDR_SETPARAMETERS (0x61U)
#define USB_DEVICE_CCID_PC_TO_RDR_ESCAPE (0x6BU)
#define USB_DEVICE_CCID_PC_TO_RDR_ICCCLOCK (0x6EU)
#define USB_DEVICE_CCID_PC_TO_RDR_T0APDU (0x6AU)
#define USB_DEVICE_CCID_PC_TO_RDR_SECURE (0x69U)
#define USB_DEVICE_CCID_PC_TO_RDR_MECHANICAL (0x71U)
#define USB_DEVICE_CCID_PC_TO_RDR_ABORT (0x72U)
#define USB_DEVICE_CCID_PC_TO_RDR_SETDATARATEANDCLOCKFREQUENCY (0x73U)

/*! @brief The message type of CCID device class-specific bulk-in pipe(Response pipe) */
#define USB_DEVICE_CCID_RDR_TO_PC_DATABLOCK (0x80U)
#define USB_DEVICE_CCID_RDR_TO_PC_SLOTSTATUS (0x81U)
#define USB_DEVICE_CCID_CLCOK_STATUS_CLOCK_RUNNING (0x00U)
#define USB_DEVICE_CCID_CLCOK_STATUS_CLOCK_STOPPED_IN_L (0x01U)
#define USB_DEVICE_CCID_CLCOK_STATUS_CLOCK_STOPPED_IN_H (0x02U)
#define USB_DEVICE_CCID_CLCOK_STATUS_CLOCK_STOPPED_UNKNOWN (0x03U)
#define USB_DEVICE_CCID_RDR_TO_PC_PARAMETERS (0x82U)
#define USB_DEVICE_CCID_PROTOCOL_NUMBER_T0 (0x00U)
#define USB_DEVICE_CCID_PROTOCOL_NUMBER_T1 (0x01U)
#define USB_DEVICE_CCID_RDR_TO_PC_ESCAPE (0x83U)
#define USB_DEVICE_CCID_RDR_TO_PC_DATARATEANDCLOCKFREQUENCY (0x84U)

/*! @brief The message type of CCID device class-specific interrupt-in pipe */
#define USB_DEVICE_CCID_RDR_TO_PC_NOTIFYSLOTCHANGE (0x50U)
#define USB_DEVICE_CCID_RDR_TO_PC_HARDWAREERROR (0x51U)

/*! @brief Reporting Slot Error and Slot Status registers in Bulk-IN messages */
/* Slot error register when bmCommandStatus = 1U */
#define USB_DEVICE_CCID_SLOT_ERROR_COMMAND_NOT_SUPPORTED (0x00U)
#define USB_DEVICE_CCID_SLOT_ERROR_BAD_LENGTH (0x01U)
#define USB_DEVICE_CCID_SLOT_ERROR_SLOT_NOT_EXIST (0x05U)
#define USB_DEVICE_CCID_SLOT_ERROR_POWER_SELECT (0x07U)
#define USB_DEVICE_CCID_SLOT_ERROR_PROTOCOL_INVALID (0x07U)
#define USB_DEVICE_CCID_SLOT_ERROR_BAD_LEVEL_PARAMETER (0x08U)
#define USB_DEVICE_CCID_SLOT_ERROR_FI_DI_INVALID (0x0AU)
#define USB_DEVICE_CCID_SLOT_ERROR_INVALID_TCCKTS_PARAMETER (0x0BU)
#define USB_DEVICE_CCID_SLOT_ERROR_GUARD_TIME_NOT_SUPPORTED (0x0CU)
#define USB_DEVICE_CCID_SLOT_ERROR_xWI_INVALID (0x0DU)
#define USB_DEVICE_CCID_SLOT_ERROR_CLOCK_STOP_INVALID (0x0EU)
#define USB_DEVICE_CCID_SLOT_ERROR_IFSC_SIZE_INVALID (0x0FU)
#define USB_DEVICE_CCID_SLOT_ERROR_NAD_VALUE_INVALID (0x10U)

#define USB_DEVICE_CCID_SLOT_ERROR_CMD_ABORTED (0xFFU)
#define USB_DEVICE_CCID_SLOT_ERROR_ICC_MUTE (0xFEU)
#define USB_DEVICE_CCID_SLOT_ERROR_XFR_PARITY_ERROR (0xFDU)
#define USB_DEVICE_CCID_SLOT_ERROR_XFR_OVERRUN (0xFCU)
#define USB_DEVICE_CCID_SLOT_ERROR_HW_ERROR (0xFBU)
#define USB_DEVICE_CCID_SLOT_ERROR_BAD_ATR_TS (0xF8U)
#define USB_DEVICE_CCID_SLOT_ERROR_BAD_ATR_TCK (0xF7U)
#define USB_DEVICE_CCID_SLOT_ERROR_ICC_PROTOCOL_NOT_SUPPORTED (0xF6U)
#define USB_DEVICE_CCID_SLOT_ERROR_ICC_CLASS_NOT_SUPPORTED (0xF5U)
#define USB_DEVICE_CCID_SLOT_ERROR_PROCEDURE_BYTE_CONFICT (0xF4U)
#define USB_DEVICE_CCID_SLOT_ERROR_DEACTIVATED_PROCTOCL (0xF3U)
#define USB_DEVICE_CCID_SLOT_ERROR_BUSY_WITH_AUTO_SEQUENCE (0xF2U)
#define USB_DEVICE_CCID_SLOT_ERROR_PIN_TIMEOUT (0xF0U)
#define USB_DEVICE_CCID_SLOT_ERROR_PIN_CANCELLED (0xEFU)
#define USB_DEVICE_CCID_SLOT_ERROR_CMD_SLOT_BUSY (0xE0U)

#define USB_DEVICE_CCID_SLOT_ERROR_CMD_NOT_ABORTED (0xC0U)

/* CCID slot status code */
#define USB_DEVICE_CCID_SLOT_STATUS_ICC_STATUS_SHIFT (0x00U)
#define USB_DEVICE_CCID_SLOT_STATUS_ICC_STATUS_MASK (0x03U)
#define USB_DEVICE_CCID_SLOT_STATUS_COMMAND_STATUS_SHIFT (0x06U)
#define USB_DEVICE_CCID_SLOT_STATUS_COMMAND_STATUS_MASK (0xC0U)

/* bmICCStatus */
#define USB_DEVICE_CCID_SLOT_STATUS_ICC_PRESENT_ACTIVE (0x00U)
#define USB_DEVICE_CCID_SLOT_STATUS_ICC_PRESENT_INACTIVE (0x01U)
#define USB_DEVICE_CCID_SLOT_STATUS_ICC_NOT_PRESENT (0x02U)

/* bmCommandStatus */
#define USB_DEVICE_CCID_SLOT_STATUS_COMMAND_STATUS_PROCESSED_NO_ERROR (0x00U)
#define USB_DEVICE_CCID_SLOT_STATUS_COMMAND_STATUS_FAILED (0x40U)
#define USB_DEVICE_CCID_SLOT_STATUS_COMMAND_STATUS_TIME_EXTENSION_REQUESTED (0x80U)

/*! @brief The command header length of the bulk-out pipe message. */
#define USB_DEVICE_CCID_COMMAND_HEADER_LENGTH (0x0AU)
/*! @brief The response header length of the bulk-in pipe message. */
#define USB_DEVICE_CCID_RESPONSE_HEADER_LENGTH (0x0AU)

/*!
 * @brief Common command structure of the command message in the bulk-out pipe.
 *
 */
STRUCT_PACKED
struct _usb_device_ccid_common_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bParameter1;  /*!< Parameter1 of the message, message specific */
    uint8_t bParameter2;  /*!< Parameter2 of the message, message specific */
    uint8_t bParameter3;  /*!< Parameter3 of the message, message specific */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_common_command usb_device_ccid_common_command_t;

/*!
 * @brief ICC power on command structure of the command message in the bulk-out pipe.
 *
 * A PC_to_RDR_IccPowerOn message to an inactive slot will return an Answer To Reset (ATR) data.
 *
 * The response to this command message is the RDR_to_PC_DataBlock response message and the
 * data returned is the Answer To Reset (ATR) data.
 */
STRUCT_PACKED
struct _usb_device_ccid_power_on_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bPowerSelect; /*!< Voltage that is applied to the ICC */
    uint8_t bRFU[2];      /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_power_on_command usb_device_ccid_power_on_command_t;

/*!
 * @brief ICC power off command structure of the command message in the bulk-out pipe.
 *
 * The response to this command message is the RDR_to_PC_SlotStatus response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_power_off_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bRFU[3];      /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_power_off_command usb_device_ccid_power_off_command_t;

/*!
 * @brief Get slot status command structure of the command message in the bulk-out pipe.
 *
 * The response to this command message is the RDR_to_PC_SlotStatus response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_get_slot_status_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bRFU[3];      /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_get_slot_status_command usb_device_ccid_get_slot_status_command_t;

/*!
 * @brief Transfer data block command structure of the command message in the bulk-out pipe.
 *
 * The block should never exceed the dwMaxCCIDMessageLength-10 in the Class Descriptor.
 * Parameter bBWI is only used by CCIDs which use the character level and TPDU level of exchange
 * (as reported in the dwFeatures parameter in the CCID Functional Descriptor) and only for protocol T=1 transfers.
 *
 * The response to this command message is the RDR_to_PC_DataBlock response message.
 *
 * @note For reference, the absolute maximum block size for a TPDU T=0 block is 260U bytes (5U bytes command; 255U bytes
 * data),
 * or for a TPDU T=1 block is 259U bytes, or for a short APDU T=1 block is 261U bytes, or for an extended APDU T=1 block
 * is 65544U bytes.
 */
STRUCT_PACKED
struct _usb_device_ccid_transfer_block_command
{
    uint8_t bMessageType;     /*!< The message type */
    uint32_t dwLength;        /*!< Size of abData field of this message */
    uint8_t bSlot;            /*!< Identifies the slot number for this command */
    uint8_t bSeq;             /*!< Sequence number for command */
    uint8_t bBWI;             /*!< Used to extend the CCIDs Block Waiting Timeout for this current transfer */
    uint16_t wLevelParameter; /*!< Use changes depending on the exchange level reported by the class descriptor in
                                 dwFeatures field */
    uint8_t abData[1];        /*!< Data block sent to the CCID */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_transfer_block_command usb_device_ccid_transfer_block_command_t;

/*!
 * @brief Get ICC parameter command structure of the command message in the bulk-out pipe.
 *
 * The response to this command message is the RDR_to_PC_Parameters response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_get_parameters_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bRFU[3];      /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_get_parameters_command usb_device_ccid_get_parameters_command_t;

/*!
 * @brief Reset ICC parameter command structure of the command message in the bulk-out pipe.
 *
 * This command resets the slot parameters to their default values.
 *
 * The response to this command message is the RDR_to_PC_Parameters response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_reset_parameters_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bRFU[3];      /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_reset_parameters_command usb_device_ccid_reset_parameters_command_t;

/*!
 * @brief Set ICC parameter command structure of the command message in the bulk-out pipe.
 *
 * This command is used to change the parameters for a given slot.
 * A CCID which has no automatic features (dwFeatures=0, 100h, 200h, or 300h) depends on the driver to send this command
 * to set the protocol and other parameters to the right values necessary to correctly talk to the ICC located in the
 * selected slot.
 * A CCID which has automatic features will automatically set the protocol and certain parameters based on data received
 * from the ICC (ATR, PPS, IFSD, or proprietary algorithms). The level of automatism and design requirements will
 * determine which parameters the CCID will allow the driver to change.
 * If this command tries to change a parameter which is not changeable, then the CCID will not change any parameters and
 * the RDR_to_PC_GetParameters response will return a Command Failed status and the bError field will contain the offset
 * of the "offending" parameter.
 *
 * The response to this command message is the RDR_to_PC_Parameters response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_set_parameters_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Size of abProtocolDataStructure field of this message */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bProtocolNum; /*!< Specifies what protocol data structure follows. 00h = Structure for protocol T=0, 01h =
                             Structure for protocol T=1 */
    uint8_t bRFU[2];      /*!< Reserved for Future Use */
    uint8_t abProtocolDataStructure[1]; /*!< Protocol Data Structure. For T = 0U, refer to
                                           usb_device_ccid_set_parameters_t0_command_t, for T = 1U, refer to
                                           usb_device_ccid_set_parameters_t1_command_t. */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_set_parameters_command usb_device_ccid_set_parameters_command_t;

/*!
 * @brief Set ICC(T=0) parameter command structure of the command message in the bulk-out pipe.
 *
 * Protocol Data Structure for Protocol T=0 (bProtocolNum=0) (dwLength=00000005h).
 *
 * The response to this command message is the RDR_to_PC_Parameters response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_set_parameters_t0_command
{
    uint8_t bMessageType;      /*!< The message type */
    uint32_t dwLength;         /*!< (dwLength = 0x05U) */
    uint8_t bSlot;             /*!< Identifies the slot number for this command */
    uint8_t bSeq;              /*!< Sequence number for command */
    uint8_t bProtocolNum;      /*!< Structure for protocol T=0 */
    uint8_t bRFU[2];           /*!< Reserved for Future Use */
    uint8_t bmFindexDindex;    /*!< Bit7~4 - Fi, Bit3~0 - Di. */
    uint8_t bmTCCKST0;         /*!< Bit1 - Convention used(0U for direct, 1U for inverse), other bits is 0*/
    uint8_t bGuardTimeT0;      /*!< Extra Guardtime between two characters. */
    uint8_t bWaitingIntegerT0; /*!< WI for T= 0U used to define WWT */
    uint8_t bClockStop;        /*!< ICC Clock Stop Support */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_set_parameters_t0_command usb_device_ccid_set_parameters_t0_command_t;

/*!
 * @brief Set ICC(T=1) parameter command structure of the command message in the bulk-out pipe.
 *
 * Protocol Data Structure for Protocol T=1 (bProtocolNum=1) (dwLength=00000007h)
 *
 * The response to this command message is the RDR_to_PC_Parameters response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_set_parameters_t1_command
{
    uint8_t bMessageType;   /*!< The message type */
    uint32_t dwLength;      /*!< (dwLength = 0x07U) */
    uint8_t bSlot;          /*!< Identifies the slot number for this command */
    uint8_t bSeq;           /*!< Sequence number for command */
    uint8_t bProtocolNum;   /*!< Structure for protocol T=1 */
    uint8_t bRFU[2];        /*!< Reserved for Future Use */
    uint8_t bmFindexDindex; /*!< Bit7~4 - Fi, Bit3~0 - Di. */
    uint8_t bmTCCKST1; /*!< Bit0 - Checksum type(0U for LRC, 1U for CRC). Bit1 - Convention used(0U for direct, 1U for
                          inverse), Bit7~2 - 0b000100 */
    uint8_t bGuardTimeT1;        /*!< Extra Guardtime. */
    uint8_t bmWaitingIntegersT1; /*!< Bit7~4 - BWI(0~9 valid), Bit3~0 - CWI(0~0xF valid) */
    uint8_t bClockStop;          /*!< ICC Clock Stop Support */
    uint8_t bIFSC;               /*!< Size of negotiated IFSC */
    uint8_t bNadValue; /*!< Value = 0x00U if CCID doesn't support a value other then the default value. Else value
                          respects ISO/IEC 7816-3, 9.4.2.1 */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_set_parameters_t1_command usb_device_ccid_set_parameters_t1_command_t;

/*! @brief Set ICC parameter command union of the command message in the bulk-out pipe. */
typedef union _usb_device_ccid_set_parameters_command_common
{
    usb_device_ccid_set_parameters_command_t common; /*!< Set ICC parameter common structure */
    usb_device_ccid_set_parameters_t0_command_t t0;  /*!< Set ICC parameter structure for T0 */
    usb_device_ccid_set_parameters_t1_command_t t1;  /*!< Set ICC parameter structure for T1 */
} usb_device_ccid_set_parameters_command_common_t;

/*!
 * @brief Escape command structure of the command message in the bulk-out pipe.
 *
 * This command allows the CCID manufacturer to define and access extended features.
 * Information sent via this command is processed by the CCID control logic.
 *
 * The response to this command message is the RDR_to_PC_Escape response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_escape_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bRFU[3];      /*!< Reserved for Future Use */
    uint8_t abData[1];    /*!< Size of abData field of this message */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_escape_command usb_device_ccid_escape_command_t;

/*!
 * @brief Control ICC clock command structure of the command message in the bulk-out pipe.
 *
 * This command stops or restarts the clock.
 *
 * The response to this command message is the RDR_to_PC_SlotStatus response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_clock_command
{
    uint8_t bMessageType;  /*!< The message type */
    uint32_t dwLength;     /*!< Message-specific data length */
    uint8_t bSlot;         /*!< Identifies the slot number for this command */
    uint8_t bSeq;          /*!< Sequence number for command */
    uint8_t bClockCommand; /*!< 0x00U - Restart clock, 0x01U - Stop clock in the state shown in the bClockStop field of
                              the PC_to_RDR_SetParameters command and RDR_to_PC_Parameters message.*/
    uint8_t bRFU[2];       /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_clock_command usb_device_ccid_clock_command_t;

/*!
 * @brief Control ICC clock command structure of the command message in the bulk-out pipe.
 *
 * This command changes the parameters used to perform the transportation of APDU messages by the T=0 protocol.
 * It effects the CLA (class) byte used when issuing a Get Response command or a Envelope command to the ICC.
 *
 * This command is slot specific. It only effects the slot specified in the bSlot field.
 * Slots, when not powered, will change back to using the default behaviour defined in the CCID class descriptor.
 * Any newly inserted ICC will have the default behaviour until this command is issued for its slot.
 *
 * The response to this command message is the RDR_to_PC_SlotStatus response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_t0_apdu_command
{
    uint8_t bMessageType;      /*!< The message type */
    uint32_t dwLength;         /*!< Message-specific data length */
    uint8_t bSlot;             /*!< Identifies the slot number for this command */
    uint8_t bSeq;              /*!< Sequence number for command */
    uint8_t bmChanges;         /*!<
                                * The value is bitwise OR operation.
                                * Bit 0U is associated with field bClassGetResponse
                                * Bit 1U is associated with field bClassEnvelope
                                * Other bits are RFU. */
    uint8_t bClassGetResponse; /*!< Value to force the class byte of the header in a Get Response command */
    uint8_t bClassEnvelope;    /*!< Value to force the class byte of the header in a Envelope command */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_t0_apdu_command usb_device_ccid_t0_apdu_command_t;

/*!
 * @brief Secure command structure of the command message in the bulk-out pipe.
 *
 * This is a command message to allow entering the PIN for verification or modification.
 *
 * The response to this command message is the RDR_to_PC_DataBlock response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_secure_command
{
    uint8_t bMessageType;     /*!< The message type */
    uint32_t dwLength;        /*!< Size of abData field of this message */
    uint8_t bSlot;            /*!< Identifies the slot number for this command */
    uint8_t bSeq;             /*!< Sequence number for command */
    uint8_t bBWI;             /*!< Used to extend the CCIDs Block Waiting Timeout for this current transfer */
    uint16_t wLevelParameter; /*!< Use changes depending on the exchange level reported by CCID in the functional
                                 descriptor */
    uint8_t abData[1];        /*!<
                               * The value depends of wLevelParameters.
                               * When wLevelParameters is 0000h or 0001h abData = abPINOperationDataStructure.
                               * For other values of wLevelParameters this field is the continuation of the previously sent
                               * PC_to_RDR_Secure.
                               */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_secure_command usb_device_ccid_secure_command_t;

/*!
 * @brief Secure PIN operation command structure of the command message in the bulk-out pipe.
 *
 * This is a command message to allow entering the PIN for verification or modification.
 *
 * The response to this command message is the RDR_to_PC_DataBlock response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_secure_pin_operation_command
{
    uint8_t bMessageType;          /*!< The message type */
    uint32_t dwLength;             /*!< 1U + Size of abPINDataStructure field of this message */
    uint8_t bSlot;                 /*!< Identifies the slot number for this command */
    uint8_t bSeq;                  /*!< Sequence number for command */
    uint8_t bBWI;                  /*!< Used to extend the CCIDs Block Waiting Timeout for this current transfer */
    uint16_t wLevelParameter;      /*!< Use changes depending on the exchange level reported by CCID in the functional
                                      descriptor */
    uint8_t bPINOperation;         /*!<
                                    * Used to indicate the PIN operation:
                                    *   00h: PIN Verification
                                    *   01h: PIN Modification
                                    *   02h: Transfer PIN from secure CCID buffer
                                    *   03h: Wait ICC response
                                    *   04h: Cancel PIN function
                                    *   05h: Re-send last I-Block, valid only if T = 1.
                                    *   06h: Send next part of APDU, valid only T = 1.
                                    */
    uint8_t abPINDataStructure[1]; /* PIN Verification Data Structure or PIN Modification Data Structure */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_secure_pin_operation_command usb_device_ccid_secure_pin_operation_command_t;

/*!
 * @brief Secure PIN Verification operation command structure of the command message in the bulk-out pipe.
 *
 * This is a command message to allow entering the PIN for verification.
 *
 * The response to this command message is the RDR_to_PC_DataBlock response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_seucre_pin_verification_command
{
    uint8_t bMessageType;       /*!< The message type */
    uint32_t dwLength;          /*!< 12U + Size of abPINApdu field of this message */
    uint8_t bSlot;              /*!< Identifies the slot number for this command */
    uint8_t bSeq;               /*!< Sequence number for command */
    uint8_t bBWI;               /*!< Used to extend the CCIDs Block Waiting Timeout for this current transfer */
    uint16_t wLevelParameter;   /*!< Use changes depending on the exchange level reported by CCID in the functional
                                   descriptor */
    uint8_t bPINOperation;      /*!<
                                 * Used to indicate the PIN operation:
                                 *   00h: PIN Verification
                                 *   01h: PIN Modification
                                 *   02h: Transfer PIN from secure CCID buffer
                                 *   03h: Wait ICC response
                                 *   04h: Cancel PIN function
                                 *   05h: Re-send last I-Block, valid only if T = 1.
                                 *   06h: Send next part of APDU, valid only T = 1.
                                 */
    uint8_t bTimeOut;           /*!< Number of seconds */
    uint8_t bmFormatString;     /*!< Several parameters for the PIN format options */
    uint8_t bmPINBlockString;   /*!< Defines the length in bytes of the PIN block to present in the APDU command */
    uint8_t bmPINLengthFormat;  /*!< Allows the insertion of the PIN length in the APDU command */
    uint16_t wPINMaxExtraDigit; /*!< Bit15~8 - Minimum PIN size in digit, Bit7~0 - Maximum PIN size in digit */
    uint8_t bEntryValidationCondition; /*!< The value is a bit wise OR operation. 01h - Max size reached, 02h -
                                          Validation key pressed, 04h - Timeout occurred*/
    uint8_t bNumberMessage;            /*!< Number of messages to display for the PIN Verification management. */
    uint16_t wLangId;                  /*!< Language used to display the messages.*/
    uint8_t bMsgIndex;                 /*!< Message index in the Reader CCID message table (should be 00h). */
    uint8_t bTeoPrologue;              /*!< T=1 I-block prologue field to use. */
    uint8_t abPINApdu[1];              /*!< APDU to send to the ICC */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_seucre_pin_verification_command usb_device_ccid_seucre_pin_verification_command_t;

/*!
 * @brief Secure PIN Modification operation command structure of the command message in the bulk-out pipe.
 *
 * This is a command message to allow entering the PIN for modification.
 *
 * The response to this command message is the RDR_to_PC_DataBlock response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_secure_pin_modification_command
{
    uint8_t bMessageType;        /*!< The message type */
    uint32_t dwLength;           /*!< 20U + Size of abPINApdu field of this message */
    uint8_t bSlot;               /*!< Identifies the slot number for this command */
    uint8_t bSeq;                /*!< Sequence number for command */
    uint8_t bBWI;                /*!< Used to extend the CCIDs Block Waiting Timeout for this current transfer */
    uint16_t wLevelParameter;    /*!< Use changes depending on the exchange level reported by CCID in the functional
                                    descriptor */
    uint8_t bPINOperation;       /*!<
                                  * Used to indicate the PIN operation:
                                  *   00h: PIN Verification
                                  *   01h: PIN Modification
                                  *   02h: Transfer PIN from secure CCID buffer
                                  *   03h: Wait ICC response
                                  *   04h: Cancel PIN function
                                  *   05h: Re-send last I-Block, valid only if T = 1.
                                  *   06h: Send next part of APDU, valid only T = 1.
                                  */
    uint8_t bTimeOut;            /*!< Number of seconds */
    uint8_t bmFormatString;      /*!< Several parameters for the PIN format options */
    uint8_t bmPINBlockString;    /*!< Define the length of the PIN to present in the APDU command */
    uint8_t bmPINLengthFormat;   /*!< Allows the length PIN insertion in the APDU command */
    uint8_t bInsertionOffsetOld; /*!< Insertion position offset in byte for the current PIN */
    uint8_t bInsertionOffsetNew; /*!< Insertion position offset in byte for the new PIN */
    uint16_t wPINMaxExtraDigit;  /*!< Bit15~8 - Minimum PIN size in digit, Bit7~0 - Maximum PIN size in digit */
    uint8_t bConfirmPIN;         /*!< Indicates if a confirmation is requested before acceptance of a new PIN */
    uint8_t bEntryValidationCondition; /*!< The value is a bit wise OR operation. 01h - Max size reached, 02h -
                                          Validation key pressed, 04h - Timeout occurred*/
    uint8_t bNumberMessage;            /*!< Number of messages to display for the PIN Verification management. */
    uint16_t wLangId;                  /*!< Language used to display the messages.*/
    uint8_t bMsgIndex1;                /*!< Message index in the Reader message table(should be 00h or 01h). */
    uint8_t bMsgIndex2;                /*!< Message index in the Reader message table(should be 01h or 02h). */
    uint8_t bMsgIndex3;                /*!< Message index in the Reader message table(should be 02h). */
    uint8_t bTeoPrologue[3];           /*!< T=1 I-block prologue field to use. */
    uint8_t abPINApdu[1];              /*!< APDU to send to the ICC */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_secure_pin_modification_command usb_device_ccid_secure_pin_modification_command_t;

/*!
 * @brief Manage motorized type CCID functionality command structure of the command message in the bulk-out pipe.
 *
 * This command is used to manage motorized type CCID functionality.
 *
 * The response to this command message is the RDR_to_PC_SlotStatus response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_mechanical_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bFunction;    /*!< This value corresponds to the mechanical function being requested */
    uint8_t bRFU[2];      /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_mechanical_command usb_device_ccid_mechanical_command_t;

/*!
 * @brief Abort command structure of the command message in the bulk-out pipe.
 *
 * This command is used with the Control pipe Abort request to tell the
 * CCID to stop any current transfer at the specified slot and return to a state
 * where the slot is ready to accept a new command pipe Bulk-OUT message.
 *
 * The response to this command message is the RDR_to_PC_SlotStatus response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_abort_command
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for command */
    uint8_t bRFU[3];      /*!< Reserved for Future Use */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_abort_command usb_device_ccid_abort_command_t;

/*!
 * @brief Set data rate and clock frequency command structure of the command message in the bulk-out pipe.
 *
 * This command is used to manually set the data rate and clock frequency of a specific slot.
 *
 * The response to this command message is the RDR_to_PC_SlotStatus response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_set_data_rate_and_clock_frequency_command
{
    uint8_t bMessageType;      /*!< The message type */
    uint32_t dwLength;         /*!< Message-specific data length(8U bytes) */
    uint8_t bSlot;             /*!< Identifies the slot number for this command */
    uint8_t bSeq;              /*!< Sequence number for command */
    uint8_t bRFU[3];           /*!< Reserved for Future Use */
    uint32_t dwClockFrequency; /*!< ICC clock frequency in KHz. This is an integer value */
    uint32_t dwDataRate;       /*!< ICC data rate in bpd */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_set_data_rate_and_clock_frequency_command
    usb_device_ccid_set_data_rate_and_clock_frequency_command_t;

/*!
 * @brief Common response structure to response a command message in the bulk-in pipe.
 *
 */
STRUCT_PACKED
struct _usb_device_ccid_common_response
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for the corresponding command */
    uint8_t bStatus;      /*!< Slot status register */
    uint8_t bError;       /*!< Slot error register */
    uint8_t bParameter1;  /*!< Parameter1 of the message, message specific */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_common_response usb_device_ccid_common_response_t;

/*!
 * @brief Datablock response structure to response a command message in the bulk-in pipe.
 *
 * The device in response to the following command messages: "PC_to_RDR_IccPowerOn", "PC_to_RDR_Secure" and
 * "PC_to_RDR_XfrBlock" sends this response message.
 * For "PC_to_RDR_IccPowerOn" this response message is the answer to reset (ATR) data associated with the ICC power on.
 * In other cases, the response message has the following format: The response data will contain the
 * optional data returned by the ICC, followed by the 2U byte-size status words SW1-SW2.
 */
STRUCT_PACKED
struct _usb_device_ccid_data_block_response
{
    uint8_t bMessageType;    /*!< The message type */
    uint32_t dwLength;       /*!< Message-specific data length */
    uint8_t bSlot;           /*!< Identifies the slot number for this command */
    uint8_t bSeq;            /*!< Sequence number for the corresponding command */
    uint8_t bStatus;         /*!< Slot status register */
    uint8_t bError;          /*!< Slot error register */
    uint8_t bChainParameter; /*!< Use changes depending on the exchange level reported by the class descriptor in
                                dwFeatures field */
    uint8_t abData[1];       /*!< This field contains the data returned by the CCID. */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_data_block_response usb_device_ccid_data_block_response_t;

/*!
 * @brief Send slot status response structure to response a command message in the bulk-in pipe.
 *
 * The device in response to the following command messages: "PC_to_RDR_IccPowerOff", "PC_to_RDR_GetSlotStatus",
 * "PC_to_RDR_IccClock", "PC_to_RDR_T0APDU" and, "PC_to_RDR_Mechanical" sends this response message.
 * Also the device sends this response message when it has completed aborting a slot after receiving
 * both the Class Specific ABORT request and PC_to_RDR_Abort command message.
 */
STRUCT_PACKED
struct _usb_device_ccid_slot_status_response
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Message-specific data length */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for the corresponding command */
    uint8_t bStatus;      /*!< Slot status register */
    uint8_t bError;       /*!< Slot error register */
    uint8_t
        bClockStatus; /*!< 0x00U - Clock running, 0x01U - Clock stopped in L, 0x02U - clock stopped in H, and 0x03U -
                         clock stopped in an unknow state.*/
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_slot_status_response usb_device_ccid_slot_status_response_t;

/*!
 * @brief ICC parameter response structure to response a command message in the bulk-in pipe.
 *
 * The device in response to the following command messages: "PC_to_RDR_GetParameters", "PC_to_RDR_ResetParameters",
 * and, "PC_to_RDR_SetParameters" sends this response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_parameters_response
{
    uint8_t bMessageType;               /*!< The message type */
    uint32_t dwLength;                  /*!< Size of abProtocolDataStructure field of this message */
    uint8_t bSlot;                      /*!< Identifies the slot number for this command */
    uint8_t bSeq;                       /*!< Sequence number for the corresponding command */
    uint8_t bStatus;                    /*!< Slot status register */
    uint8_t bError;                     /*!< Slot error register */
    uint8_t bProtocolNum;               /*!< 0x00U = Structure for protocol T=0, 0x01U = Structure for protocol T=1 */
    uint8_t abProtocolDataStructure[1]; /*!< Protocol Data Structure */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_parameters_response usb_device_ccid_parameters_response_t;

/*!
 * @brief ICC T0 parameter response structure to response a command message in the bulk-in pipe.
 *
 * The device in response to the following command messages: "PC_to_RDR_GetParameters", "PC_to_RDR_ResetParameters",
 * and, "PC_to_RDR_SetParameters" sends this response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_parameters_T0_response
{
    uint8_t bMessageType;      /*!< The message type */
    uint32_t dwLength;         /*!< The value is 0x05U */
    uint8_t bSlot;             /*!< Identifies the slot number for this command */
    uint8_t bSeq;              /*!< Sequence number for the corresponding command */
    uint8_t bStatus;           /*!< Slot status register */
    uint8_t bError;            /*!< Slot error register */
    uint8_t bProtocolNum;      /*!< 0x00U = Structure for protocol T=0 */
    uint8_t bmFindexDindex;    /*!< Bit7~4 - Fi, Bit3~0 - Di. */
    uint8_t bmTCCKST0;         /*!< Bit1 - Convention used(0U for direct, 1U for inverse), other bits is 0*/
    uint8_t bGuardTimeT0;      /*!< Extra Guardtime between two characters. */
    uint8_t bWaitingIntegerT0; /*!< WI for T= 0U used to define WWT */
    uint8_t bClockStop;        /*!< ICC Clock Stop Support */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_parameters_T0_response usb_device_ccid_parameters_T0_response_t;

/*!
 * @brief ICC T1 parameter response structure to response a command message in the bulk-in pipe.
 *
 * The device in response to the following command messages: "PC_to_RDR_GetParameters", "PC_to_RDR_ResetParameters",
 * and, "PC_to_RDR_SetParameters" sends this response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_parameters_T1_response
{
    uint8_t bMessageType;   /*!< The message type */
    uint32_t dwLength;      /*!< The value is 0x07U */
    uint8_t bSlot;          /*!< Identifies the slot number for this command */
    uint8_t bSeq;           /*!< Sequence number for the corresponding command */
    uint8_t bStatus;        /*!< Slot status register */
    uint8_t bError;         /*!< Slot error register */
    uint8_t bProtocolNum;   /*!< 0x00U = Structure for protocol T=1 */
    uint8_t bmFindexDindex; /*!< Bit7~4 - Fi, Bit3~0 - Di. */
    uint8_t bmTCCKST1; /*!< Bit0 - Checksum type(0U for LRC, 1U for CRC). Bit1 - Convention used(0U for direct, 1U for
                          inverse), Bit7~2 - 0b000100 */
    uint8_t bGuardTimeT1;        /*!< Extra Guardtime. */
    uint8_t bmWaitingIntegersT1; /*!< Bit7~4 - BWI(0~9 valid), Bit3~0 - CWI(0~0xF valid) */
    uint8_t bClockStop;          /*!< ICC Clock Stop Support */
    uint8_t bIFSC;               /*!< Size of negotiated IFSC */
    uint8_t bNadValue; /*!< Value = 0x00U if CCID doesn't support a value other then the default value. Else value
                          respects ISO/IEC 7816-3, 9.4.2.1 */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_parameters_T1_response usb_device_ccid_parameters_T1_response_t;

/*! @brief ICC parameter response union to response a command message in the bulk-in pipe. */
typedef union _usb_device_ccid_parameters_response_common
{
    usb_device_ccid_parameters_response_t common; /*!< Response ICC parameter common structure */
    usb_device_ccid_parameters_T0_response_t t0;  /*!< Response ICC parameter structure for T0 */
    usb_device_ccid_parameters_T1_response_t t1;  /*!< Response ICC parameter structure for T1 */
} usb_device_ccid_parameters_response_common_t;

/*!
 * @brief Response structure to response the "PC_to_RDR_Escape" command message in the bulk-in pipe.
 *
 * The device in response to the following command messages: "PC_to_RDR_Escape" sends this response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_escape_response
{
    uint8_t bMessageType; /*!< The message type */
    uint32_t dwLength;    /*!< Size of abData field of this message */
    uint8_t bSlot;        /*!< Identifies the slot number for this command */
    uint8_t bSeq;         /*!< Sequence number for the corresponding command */
    uint8_t bStatus;      /*!< Slot status register */
    uint8_t bError;       /*!< Slot error register */
    uint8_t bRFU;         /*!< Reserved for Future Use */
    uint8_t abData[1];    /*!< Data sent from CCID */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_escape_response usb_device_ccid_escape_response_t;

/*!
 * @brief Response structure to response the "PC_to_RDR_SetDataRateAndClockFrequency" command message in the bulk-in
 * pipe.
 *
 * The device in response to the following command messages: "PC_to_RDR_SetDataRateAndClockFrequency" sends this
 * response message.
 */
STRUCT_PACKED
struct _usb_device_ccid_data_rate_and_clock_frequency_response
{
    uint8_t bMessageType;      /*!< The message type */
    uint32_t dwLength;         /*!< Message-specific data length */
    uint8_t bSlot;             /*!< Identifies the slot number for this command */
    uint8_t bSeq;              /*!< Sequence number for the corresponding command */
    uint8_t bStatus;           /*!< Slot status register */
    uint8_t bError;            /*!< Slot error register */
    uint8_t bRFU;              /*!< Reserved for Future Use */
    uint32_t dwClockFrequency; /*!< Current setting of the ICC clock frequency in KHz. This is an integer value */
    uint32_t dwDataRate;       /*!< Current setting of the ICC data rate in bps. This is an integer value */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_data_rate_and_clock_frequency_response
    usb_device_ccid_data_rate_and_clock_frequency_response_t;

/*! @brief Notification structure to notify Host the CCID device slot changed */
STRUCT_PACKED
struct _usb_device_ccid_notify_slot_chnage_notification
{
    uint8_t bMessageType;      /*!< The message type */
    uint8_t bmSlotICCState[1]; /*!< This field is reported on byte granularity. */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_notify_slot_chnage_notification usb_device_ccid_notify_slot_chnage_notification_t;

/*! @brief Notification structure to notify Host a hardware error happened in the CCID device */
STRUCT_PACKED
struct _usb_device_ccid_hardware_error_notification
{
    uint8_t bMessageType;       /*!< The message type */
    uint8_t bSlot;              /*!< Identifies the slot number for this command */
    uint8_t bSeq;               /*!< Sequence number of bulk out command when the hardware error occurred */
    uint8_t bHardwareErrorCode; /*!< 0x01U - Overcurrent. */
} STRUCT_UNPACKED;
typedef struct _usb_device_ccid_hardware_error_notification usb_device_ccid_hardware_error_notification_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#endif /* __USB_DEVICE_CCID_H__ */