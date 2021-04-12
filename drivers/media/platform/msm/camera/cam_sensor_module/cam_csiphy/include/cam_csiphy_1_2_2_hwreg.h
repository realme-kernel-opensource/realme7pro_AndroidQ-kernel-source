/* Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _CAM_CSIPHY_1_2_2_HWREG_H_
#define _CAM_CSIPHY_1_2_2_HWREG_H_

#include "../cam_csiphy_dev.h"

struct csiphy_reg_parms_t csiphy_v1_2_2 = {
	.mipi_csiphy_interrupt_status0_addr = 0x8B0,
	.mipi_csiphy_interrupt_clear0_addr = 0x858,
	.mipi_csiphy_glbl_irq_cmd_addr = 0x828,
	.csiphy_common_array_size = 7,
	.csiphy_reset_array_size = 5,
	.csiphy_2ph_config_array_size = 22,
	.csiphy_3ph_config_array_size = 38,
	.csiphy_2ph_clock_lane = 0x1,
	.csiphy_2ph_combo_ck_ln = 0x10,
};

struct csiphy_reg_t csiphy_common_reg_1_2_2[] = {
	{0x0814, 0xd5, 0x00, CSIPHY_LANE_ENABLE},
	{0x0818, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x081C, 0x02, 0x00, CSIPHY_2PH_REGS},
	{0x081C, 0x52, 0x00, CSIPHY_3PH_REGS},
	{0x0800, 0x03, 0x01, CSIPHY_DEFAULT_PARAMS},
	{0x0800, 0x02, 0x00, CSIPHY_2PH_REGS},
	{0x0800, 0x0E, 0x00, CSIPHY_3PH_REGS},
};

struct csiphy_reg_t csiphy_reset_reg_1_2_2[] = {
	{0x0814, 0x00, 0x05, CSIPHY_LANE_ENABLE},
	{0x0818, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x081C, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0800, 0x01, 0x01, CSIPHY_DEFAULT_PARAMS},
	{0x0800, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
};

struct csiphy_reg_t csiphy_irq_reg_1_2_2[] = {
	{0x082c, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0830, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0834, 0xFB, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0838, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x083c, 0x7F, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0840, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0844, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0848, 0xEF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x084c, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0850, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
	{0x0854, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
};

struct
csiphy_reg_t csiphy_2ph_v1_2_2_reg[MAX_LANES][MAX_SETTINGS_PER_LANE] = {
	{
		{0x0030, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0904, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0910, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0900, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0908, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0904, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x00C4, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x002C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0034, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0010, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x001C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0014, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0028, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x003C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0000, 0x91, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0004, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0020, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0008, 0x10, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x000c, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x0010, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0038, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
	{
		{0x0730, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C84, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C90, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C80, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C88, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C84, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x07C4, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x072C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0734, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0710, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x071C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0714, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0728, 0x04, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x073C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0700, 0x80, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0704, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0720, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0708, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x070c, 0xff, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0710, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0738, 0x1F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
	{
		{0x0230, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A04, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A10, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A00, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A08, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A04, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x02C4, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x022C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0234, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0210, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x021C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0214, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0228, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x023C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0200, 0x91, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0204, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0220, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0208, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x020c, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x0210, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0238, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
	{
		{0x0430, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B04, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B10, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B00, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B08, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B04, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x04C4, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x042C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0434, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0410, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x041C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0414, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0428, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x043C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0400, 0x91, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0404, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0420, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0408, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x040c, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x0410, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0438, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
	{
		{0x0630, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C04, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C10, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C00, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C08, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C04, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x06C4, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x062C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0634, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0610, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x061C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0614, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0628, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x063C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0600, 0x91, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0604, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0620, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0608, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x060c, 0x00, 0x00, CSIPHY_DNP_PARAMS},
		{0x0610, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0638, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
};

struct csiphy_reg_t
	csiphy_2ph_v1_2_2_combo_mode_reg[MAX_LANES][MAX_SETTINGS_PER_LANE] = {
	{
		{0x0030, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0904, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0910, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0900, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0908, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0904, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x002C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0034, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0010, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x001C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0014, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x003C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0000, 0x91, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0004, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0020, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0008, 0x10, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x0010, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0038, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x005C, 0xC0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0060, 0x0D, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0000, 0x00, 0x00, CSIPHY_DNP_PARAMS},
	},
	{
		{0x0730, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C84, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C90, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C80, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C88, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C84, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x072C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0734, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0710, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x071C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0714, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0728, 0x04, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x073C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0700, 0x80, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0704, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0720, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0708, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x070c, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0710, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0738, 0x1F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0000, 0x00, 0x00, CSIPHY_DNP_PARAMS},
	},
	{
		{0x0230, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A04, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A10, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A00, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A08, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A04, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x022C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0234, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0210, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x021C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0214, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x023C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0200, 0x91, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0204, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0220, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0208, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x0210, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0238, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x025C, 0xC0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0260, 0x0D, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0000, 0x00, 0x00, CSIPHY_DNP_PARAMS},
	},
	{
		{0x0430, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B04, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B10, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B00, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B08, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B04, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x042C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0434, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0410, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x041C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0414, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0428, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x043C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0400, 0x91, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0404, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0420, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0408, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x0410, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0438, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x045C, 0xC0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0460, 0x0D, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
	{
		{0x0630, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C04, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C10, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C00, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C08, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0C04, 0x07, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x062C, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0634, 0x0F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0610, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x061C, 0x0A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0614, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0628, 0x0E, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x063C, 0xB8, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0600, 0x80, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0604, 0x0C, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0620, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0608, 0x04, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x060c, 0xFF, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0610, 0x52, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0638, 0xFE, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0000, 0x00, 0x00, CSIPHY_DNP_PARAMS},
	},
};

struct
csiphy_reg_t csiphy_3ph_v1_2_2_reg[MAX_LANES][MAX_SETTINGS_PER_LANE] = {
	{
		{0x015C, 0x46, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0990, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0994, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0998, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0990, 0x08, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0994, 0x08, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0998, 0x1A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x098C, 0xAF, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0168, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x016C, 0x25, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0104, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x010C, 0x07, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x0108, 0x00, 0x00, CSIPHY_SETTLE_CNT_HIGHER_BYTE},
		{0x0114, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0150, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0188, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x018C, 0x7f, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0190, 0x7f, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0118, 0x3e, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x011C, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0120, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0124, 0x7F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0128, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x012C, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0144, 0x22, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0160, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x01CC, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0164, 0x33, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x01DC, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x09C0, 0x80, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x09C4, 0x7D, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x09C8, 0x7F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0984, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0988, 0x05, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0980, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x09B0, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x09B4, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x0E, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
	{
		{0x035C, 0x46, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A90, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A94, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A98, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A90, 0x08, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A94, 0x08, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A98, 0x1A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A8C, 0xAF, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0368, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x036C, 0x25, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0304, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x030C, 0x07, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x0308, 0x00, 0x00, CSIPHY_SETTLE_CNT_HIGHER_BYTE},
		{0x0314, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0350, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0388, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x038C, 0x7f, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0390, 0x7f, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0318, 0x3e, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x031C, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0320, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0324, 0x7F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0328, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x032C, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0344, 0x22, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0360, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x03CC, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0364, 0x33, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x03DC, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0AC0, 0x80, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0AC4, 0x7D, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0AC8, 0x7F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A84, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A88, 0x05, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0A80, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0AB0, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0AB4, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x0E, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
	{
		{0x055C, 0x46, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B90, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B94, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B98, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B90, 0x08, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B94, 0x08, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B98, 0x1A, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B8C, 0xAF, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0568, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x056C, 0x25, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0504, 0x06, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x050C, 0x07, 0x00, CSIPHY_SETTLE_CNT_LOWER_BYTE},
		{0x0508, 0x00, 0x00, CSIPHY_SETTLE_CNT_HIGHER_BYTE},
		{0x0514, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0550, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0588, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x058C, 0x7f, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0590, 0x7f, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0518, 0x3e, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x051C, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0520, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0524, 0x7F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0528, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x052C, 0x00, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0544, 0x22, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0560, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x05CC, 0x41, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0564, 0x33, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x05DC, 0x50, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0BC0, 0x80, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0BC4, 0x7D, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0BC8, 0x7F, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B84, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B88, 0x05, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0B80, 0x60, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0BB0, 0x01, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0BB4, 0x02, 0x00, CSIPHY_DEFAULT_PARAMS},
		{0x0800, 0x0E, 0x00, CSIPHY_DEFAULT_PARAMS},
	},
};

struct data_rate_settings_t data_rate_delta_table_1_2_2 = {
	.num_data_rate_settings = 3,
	.data_rate_settings = {
		{
			/* (2.5 * 10**3 * 2.28) rounded value*/
			.bandwidth = 5700000000,
			.data_rate_reg_array_size = 8,
			.csiphy_data_rate_regs = {
				{0x144, 0x22, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x344, 0x22, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x544, 0x22, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x984, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0xA84, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0xB84, 0xA0, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x0A98, 0x1F, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x0A8C, 0xBF, 0x00, CSIPHY_DEFAULT_PARAMS},
			}
		},
		{
			/* (3.5 * 10**3 * 2.28) rounded value */
			.bandwidth = 7980000000,
			.data_rate_reg_array_size = 8,
			.csiphy_data_rate_regs = {
				{0x144, 0xA2, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x344, 0xA2, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x544, 0xA2, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x984, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0xA84, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0xB84, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x0A98, 0x1A, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x0A8C, 0xAF, 0x00, CSIPHY_DEFAULT_PARAMS},
			},
		},
		{
			/* (4.5 * 10**3 * 2.28) rounded value */
			.bandwidth = 10260000000,
			.data_rate_reg_array_size = 8,
			.csiphy_data_rate_regs = {
				{0x144, 0xA2, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x344, 0xA2, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x544, 0xA2, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x984, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0xA84, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0xB84, 0x20, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x0A98, 0x1A, 0x00, CSIPHY_DEFAULT_PARAMS},
				{0x0A8C, 0xAF, 0x00, CSIPHY_DEFAULT_PARAMS},
			},
		}
	}
};
#endif /* _CAM_CSIPHY_1_2_2_HWREG_H_ */
