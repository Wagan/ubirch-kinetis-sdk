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
#include "board.h"
#include "fsl_qspi.h"
#include "fsl_debug_console.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_QSPI QuadSPI0
#define QSPI_CLOCK_SOURCE kCLOCK_McgPll0Clk
#define FLASH_PAGE_SIZE 256U
#define FLASH_SECTORE_SIZE 4096U
#define FLASH_SIZE 0x00400000U
#define DUMMY_MASTER (0xE)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
qspi_flash_config_t single_config = {
    .flashA1Size = FLASH_SIZE, /* 4MB */
    .flashA2Size = 0,
    .flashB1Size = FLASH_SIZE,
    .flashB2Size = 0,
    .lookuptable =
        {/* Seq0 :Quad Read */
             /* CMD:        0xEB - Quad Read, Single pad */
             /* ADDR:       0x18 - 24bit address, Quad pads */
             /* DUMMY:      0x06 - 6 clock cyles, Quad pads */
             /* READ:       0x80 - Read 128 bytes, Quad pads */
             /* JUMP_ON_CS: 0 */
             [0] = 0x0A1804EB, [1] = 0x0E0412A5, [2] = 0x24011E80,

             /* Seq1: Write Enable */
             /* CMD:      0x06 - Write Enable, Single pad */
             [4] = 0x406,

             /* Seq2: Erase All */
             /* CMD:    0x60 - Erase All chip, Single pad */
             [8] = 0x460,

             /* Seq3: Read Status */
             /* CMD:    0x05 - Read Status, single pad */
             /* READ:   0x01 - Read 1 byte */
             [12] = 0x1c010405,

             /* Seq4: Page Program */
             /* CMD:    0x02 - Page Program, Single pad */
             /* ADDR:   0x18 - 24bit address, Single pad */
             /* WRITE:  0x80 - Write 128 bytes at one pass, Single pad */
             [16] = 0x08180402, [17] = 0x2080,

             /* Seq5: Write Register */
             /* CMD:    0x01 - Write Status Register, single pad */
             /* WRITE:  0x01 - Write 1 byte of data, single pad */
             [20] = 0x20010401,

             /* Seq6: Read Config Register */
             /* CMD:  0x05 - Read Config register, single pad */
             /* READ: 0x01 - Read 1 byte */
             [24] = 0x1c010405,

             /* Seq7: Erase Sector */
             /* CMD:  0x20 - Sector Erase, single pad */
             /* ADDR: 0x18 - 24 bit address, single pad */
             [28] = 0x08180420,

             /* Seq8: Dummy */
             /* CMD:    0xFF - Dummy command, used to force SPI flash to exit continuous read mode */
             [32] = 0x4FF,

             /* Seq9: Fast Single read */
             /* CMD:        0x0B - Fast Read, Single Pad */
             /* ADDR:       0x18 - 24bit address, Single Pad */
             /* DUMMY:      0x08 - 8 clock cyles, Single Pad */
             /* READ:       0x80 - Read 128 bytes, Single Pad */
             /* JUMP_ON_CS: 0 */
             [36] = 0x0818040B, [37] = 0x1C800C08, [38] = 0x2400,

             /* Seq10: Fast Dual read */
             /* CMD:        0x3B - Dual Read, Single Pad */
             /* ADDR:       0x18 - 24bit address, Single Pad */
             /* DUMMY:      0x08 - 8 clock cyles, Single Pad */
             /* READ:       0x80 - Read 128 bytes, Dual pads */
             /* JUMP_ON_CS: 0 */
             [40] = 0x0818043B, [41] = 0x1D800C08, [42] = 0x2400,

             /* Match MISRA rule */
             [63] = 0},
    .dataHoldTime = 0,
    .CSHoldTime = 0,
    .CSSetupTime = 0,
    .cloumnspace = 0,
    .dataLearnValue = 0,
    .endian = kQSPI_64LittleEndian,
    .enableWordAddress = false};

static uint32_t buff[64]; /* Test data */

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Check if serial flash erase or program finished. */
void check_if_finished(void)
{
    uint32_t val = 0;
    /* Check WIP bit */
    do
    {
        while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
        {
        }
        QSPI_ClearFifo(EXAMPLE_QSPI, kQSPI_RxFifo);
        QSPI_ExecuteIPCommand(EXAMPLE_QSPI, 12U);
        while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
        {
        }
        val = *(volatile uint32_t *)(FSL_FEATURE_QSPI_ARDB_BASE);
        /* Clear ARDB area */
        QSPI_ClearErrorFlag(EXAMPLE_QSPI, kQSPI_RxBufferDrain);
    } while (val & 0x1);
}

/* Write enable command */
void cmd_write_enable(void)
{
    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
    {
    }
    QSPI_ExecuteIPCommand(EXAMPLE_QSPI, 4U);
}

/* Enable Quad mode */
void enable_quad_mode(void)
{
    uint32_t val[4] = {0x40, 0, 0, 0};

    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
    {
    }
    QSPI_SetIPCommandAddress(EXAMPLE_QSPI, FSL_FEATURE_QSPI_AMBA_BASE);

    /* Clear Tx FIFO */
    QSPI_ClearFifo(EXAMPLE_QSPI, kQSPI_TxFifo);

    /* Write enable */
    cmd_write_enable();

    /* Write data into TX FIFO, needs to write at least 16 bytes of data */
    QSPI_WriteBlocking(EXAMPLE_QSPI, val, 16U);

    /* Set seq id, write register */
    QSPI_ExecuteIPCommand(EXAMPLE_QSPI, 20);

    /* Wait until finished */
    check_if_finished();
}

/*Erase sector */
void erase_sector(uint32_t addr)
{
    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
    {
    }
    QSPI_ClearFifo(EXAMPLE_QSPI, kQSPI_TxFifo);
    QSPI_SetIPCommandAddress(EXAMPLE_QSPI, addr);
    cmd_write_enable();
    QSPI_ExecuteIPCommand(EXAMPLE_QSPI, 28U);
    check_if_finished();
}

/* Erase all command */
void erase_all(void)
{
    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
    {
    }
    QSPI_SetIPCommandAddress(EXAMPLE_QSPI, FSL_FEATURE_QSPI_AMBA_BASE);
    /* Write enable*/
    cmd_write_enable();
    QSPI_ExecuteIPCommand(EXAMPLE_QSPI, 8U);
    check_if_finished();
}

/* Program page into serial flash using QSPI polling way */
void program_page(uint32_t dest_addr, uint32_t *src_addr)
{
    uint32_t leftLongWords = 0;

    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
    {
    }
    QSPI_ClearFifo(EXAMPLE_QSPI, kQSPI_TxFifo);
    QSPI_SetIPCommandAddress(EXAMPLE_QSPI, dest_addr);
    cmd_write_enable();
    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & kQSPI_Busy)
    {
    }

    /* First write some data into TXFIFO to prevent from underrun */
    QSPI_WriteBlocking(EXAMPLE_QSPI, src_addr, FSL_FEATURE_QSPI_TXFIFO_DEPTH * 4);
    src_addr += FSL_FEATURE_QSPI_TXFIFO_DEPTH;

    /* Start the program */
    QSPI_SetIPCommandSize(EXAMPLE_QSPI, FLASH_PAGE_SIZE);
    QSPI_ExecuteIPCommand(EXAMPLE_QSPI, 16U);

    leftLongWords = FLASH_PAGE_SIZE - 16 * sizeof(uint32_t);
    QSPI_WriteBlocking(EXAMPLE_QSPI, src_addr, leftLongWords);

    /* Wait until flash finished program */
    check_if_finished();
    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & (kQSPI_Busy | kQSPI_IPAccess))
    {
    }
    QSPI_SoftwareReset(EXAMPLE_QSPI);
    while (QSPI_GetStatusFlags(EXAMPLE_QSPI) & (kQSPI_Busy | kQSPI_IPAccess))
    {
    }
}

/* Use QSPI polling way to program serial flash */
void qspi_polling(void)
{
    uint32_t i = 0;
    uint32_t err = 0;
    erase_sector(FSL_FEATURE_QSPI_AMBA_BASE);
    PRINTF("Erase finished!\r\n");
    /* Program a page */
    program_page(FSL_FEATURE_QSPI_AMBA_BASE, buff);
    PRINTF("Program data finished!\r\n");

    for (i = 0; i < 64; i++)
    {
        if (((uint32_t *)FSL_FEATURE_QSPI_AMBA_BASE)[i] != buff[i])
        {
            PRINTF("The data in %d is wrong!!\r\n", i);
            PRINTF("The flash value in %d is %d\r\n", i, ((uint32_t *)FSL_FEATURE_QSPI_AMBA_BASE)[i]);
            err++;
        }
    }
    if (err == 0)
    {
        PRINTF("Program through QSPI polling succeed!\r\n");
    }
}

int main(void)
{
    uint32_t i = 0;
    uint32_t clockSourceFreq = 0;
    qspi_config_t config = {0};

    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /*Enable QSPI clock */
    PRINTF("QSPI example started!\r\n");

    /*Get QSPI default settings and configure the qspi */
    QSPI_GetDefaultQspiConfig(&config);

    /*Set AHB buffer size for reading data through AHB bus */
    config.AHBbufferSize[3] = FLASH_PAGE_SIZE;
    clockSourceFreq = CLOCK_GetFreq(QSPI_CLOCK_SOURCE);
    QSPI_Init(EXAMPLE_QSPI, &config, clockSourceFreq);

    /*According to serial flash feature to configure flash settings */
    QSPI_SetFlashConfig(EXAMPLE_QSPI, &single_config);

    /*Initialize data buffer */
    for (i = 0; i < 64; i++)
    {
        buff[i] = i;
    }

    /* Enable Quad mode for the flash */
    enable_quad_mode();

    /* Use polling to program flash. */
    qspi_polling();

    while (1)
    {
    }
}
