/* Paintbox register header file
 *
 * Copyright (C) 2016 The Android Open Source Project
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _IPU_REGS_H
#define _IPU_REGS_H

#include <linux/types.h>

#include "ipu-regs-v2-generated.h"

/* TODO(b/115416236):  The following information should be eventually be
 * generated by the generator script from the RTL.
 */

#define REG_UNUSED "UNKNOWN"

/* TODO(b/115413436):  Switch this to uint64_t once all the registers are
 * converted to 64bit.
 */
#define IPU_REG_WIDTH sizeof(uint32_t)

/* TODO(b/115413436): Switch these to IPU_REG_WIDTH_BYTES when the trace code is
 * fully switched over. b/115413436
 */
#define IPU_REG_WIDTH_BYTES sizeof(uint64_t)

/* Number of bytes allocated for each register trace when dumping the register
 * contents through verbose logging or debugfs.
 */
#define REG_DEBUG_BUFFER_SIZE 96

#define REG_INDEX(r) ((r) / IPU_REG_WIDTH)
#define REG_NAME_ENTRY(r)[(r) / IPU_REG_WIDTH] = #r

#define REG_INDEX64(r) ((r) / IPU_REG_WIDTH_BYTES)
#define REG_NAME_ENTRY64(r)[(r) / IPU_REG_WIDTH_BYTES] = #r

#define IO_AON_BLOCK_LEN     (AON_SPARE + IPU_REG_WIDTH_BYTES)
#define IO_AON_NUM_REGS      (IO_AON_BLOCK_LEN / IPU_REG_WIDTH_BYTES)

#define IO_APB_BLOCK_LEN     (IRQ_SPARE + IPU_REG_WIDTH)
#define IO_APB_NUM_REGS      (IO_APB_BLOCK_LEN / IPU_REG_WIDTH)

#define IO_AXI_BLOCK_LEN     (AXI_SPARE + IPU_REG_WIDTH)
#define IO_AXI_NUM_REGS      (IO_AXI_BLOCK_LEN / IPU_REG_WIDTH)

#define IO_JQS_BLOCK_LEN     (JQS_SYS_STAT + IPU_REG_WIDTH_BYTES)
#define IO_JQS_NUM_REGS      (IO_JQS_BLOCK_LEN / IPU_REG_WIDTH)

/* LBP Block Boundaries */
#define LBP_POOL_BLOCK_LEN   (LBP_PMON_CNT_1_STS + IPU_REG_WIDTH)
#define LBP_POOL_NUM_REGS    (LBP_POOL_BLOCK_LEN / IPU_REG_WIDTH)

#define LBP_BLOCK_LEN        (LBP_SPARE + IPU_REG_WIDTH)
#define LBP_NUM_REGS         (LBP_BLOCK_LEN / IPU_REG_WIDTH)

/* Block length for just the line buffer registers */
#define LB_BLOCK_START       LB_CTRL0
#define LB_BLOCK_LEN         (LBP_BLOCK_LEN - LB_BLOCK_START)
#define LB_NUM_REGS          (LB_BLOCK_LEN / IPU_REG_WIDTH)

#define STP_BLOCK_LEN        (STP_PMON_CNT_1_STS + IPU_REG_WIDTH)
#define STP_NUM_REGS          (STP_BLOCK_LEN / IPU_REG_WIDTH)

/* DMA Block Boundaries */
#define DMA_TOP_BLOCK_START  DMA_CTRL
#define DMA_TOP_BLOCK_END    (DMA_SPARE + IPU_REG_WIDTH_BYTES)
#define DMA_TOP_BLOCK_LEN    (DMA_TOP_BLOCK_END - DMA_TOP_BLOCK_START)
#define DMA_TOP_NUM_REGS     (DMA_TOP_BLOCK_LEN / IPU_REG_WIDTH)

#define DMA_GRP_BLOCK_START  DMA_SEL
#define DMA_GRP_BLOCK_END    (DMA_GRP_SPARE + IPU_REG_WIDTH_BYTES)
#define DMA_GRP_BLOCK_LEN    (DMA_GRP_BLOCK_END - DMA_GRP_BLOCK_START)
#define DMA_GRP_NUM_REGS     (DMA_GRP_BLOCK_LEN / IPU_REG_WIDTH)
#else
#define DMA_CTRL_BLOCK_START  DMA_CTRL
#define DMA_CTRL_BLOCK_END    (DMA_PMON_CNT_3_STS + IPU_REG_WIDTH_BYTES)
#define DMA_CTRL_BLOCK_LEN    DMA_CTRL_BLOCK_END
#define DMA_CTRL_NUM_REGS     (DMA_CTRL_BLOCK_LEN / IPU_REG_WIDTH)

#define DMA_CHAN_BLOCK_START  DMA_CHAN_MODE
#define DMA_CHAN_BLOCK_END    (DMA_CHAN_DEPENDENCY + IPU_REG_WIDTH_BYTES)
#define DMA_CHAN_BLOCK_LEN    (DMA_CHAN_BLOCK_END - DMA_CHAN_BLOCK_START)
#define DMA_CHAN_NUM_REGS     (DMA_CHAN_BLOCK_LEN / IPU_REG_WIDTH)

#define DMA_STAT_BLOCK_START  DMA_STAT_CTRL
#define DMA_STAT_BLOCK_END    (DMA_SPARE + IPU_REG_WIDTH_BYTES)
#define DMA_STAT_BLOCK_LEN    (DMA_STAT_BLOCK_END - DMA_STAT_BLOCK_START)
#define DMA_STAT_NUM_REGS     (DMA_STAT_BLOCK_LEN / IPU_REG_WIDTH)

#define DMA_BLOCK_LEN         DMA_STAT_BLOCK_END
#define DMA_NUM_REGS          (DMA_BLOCK_LEN / IPU_REG_WIDTH)

/* LB_BASE Register Bits */
#define LB_BASE_FB_BASE_ALIGN_MASK  0x1F
#define LB_BASE_FB_BASE_ALIGN_SHIFT 5
#define LB_BASE_SB_BASE_ALIGN_MASK  0x1F
#define LB_BASE_SB_BASE_ALIGN_SHIFT 5

/* LB_STAT Register Bits */
#define LB_STAT_EMPTY0        (1 << 1)
#define LB_STAT_EMPTY1        (1 << 2)
#define LB_STAT_EMPTY2        (1 << 3)

/* MMU_ERR_LOG */
#define MMU_IOVA_SHIFT        12

/* MMU_ISR / MMU_IMR */
#define NUM_MMU_INTERRUPTS 1

/* BIF_ISR / BIF_IMR */
#define NUM_BIF_INTERRUPTS 1

/* DMA_CTRL Register Bits */
#define DMA_CTRL_AXI_SWIZZLE_NONE  0
#define DMA_CTRL_AXI_SWIZZLE_BIG_ENDIAN 1
#define DMA_CTRL_AXI_SWIZZLE_NEIGHBOR_BYTES 2

/* DMA_CHAN_MODE Register Bits */
#define DMA_CHAN_MODE_SRC_DRAM     0
#define DMA_CHAN_MODE_SRC_LBP      1
#define DMA_CHAN_MODE_SRC_STP      2
#define DMA_CHAN_MODE_SRC_MIPI_IN  3
#define DMA_CHAN_MODE_DST_DRAM     0
#define DMA_CHAN_MODE_DST_LBP      1
#define DMA_CHAN_MODE_DST_STP      2
#define DMA_CHAN_MODE_DST_MIPI_OUT 3

/* DMA_CHAN_IMG_FORMAT_BIT_DEPTH values */
#define DMA_CHAN_IMG_FORMAT_BIT_DEPTH8   0
#define DMA_CHAN_IMG_FORMAT_BIT_DEPTH10  1
#define DMA_CHAN_IMG_FORMAT_BIT_DEPTH12  2
#define DMA_CHAN_IMG_FORMAT_BIT_DEPTH14  3
#define DMA_CHAN_IMG_FORMAT_BIT_DEPTH16  4

#endif /* __IPU_REGS_H__ */
