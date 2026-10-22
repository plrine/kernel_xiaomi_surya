// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2018-2020, The Linux Foundation. All rights reserved.
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/soc/qcom/llcc-qcom.h>

#define SCT_ENTRY(uid, sid, mc, p, fs, bway, rway, cmod, ptw, dca, wse, rp, a) \
	{					\
		.usecase_id = uid,		\
		.slice_id = sid,		\
		.max_cap = mc,			\
		.priority = p,			\
		.fixed_size = fs,		\
		.bonus_ways = bway,		\
		.res_ways = rway,		\
		.cache_mode = cmod,		\
		.probe_target_ways = ptw,	\
		.dis_cap_alloc = dca,		\
		.write_scid_en = wse,		\
		.retain_on_pc = rp,		\
		.activate_on_init = a,		\
	}

static struct llcc_slice_config sm6150_data[] =  {
	SCT_ENTRY(LLCC_CPUSS,     1, 128, 1, 0, 0xF, 0x0, 0, 0, 0, 0, 1, 1),
	SCT_ENTRY(LLCC_MDM,       8, 256, 0, 1, 0xF, 0x0, 0, 0, 0, 0, 1, 0),
	SCT_ENTRY(LLCC_GPUHTW,   11, 128, 1, 1, 0xF, 0x0, 0, 0, 0, 0, 1, 0),
	SCT_ENTRY(LLCC_GPU,      12, 128, 1, 0, 0xF, 0x0, 0, 0, 0, 0, 1, 0),
};

static int sm6150_qcom_llcc_probe(struct platform_device *pdev)
{
	return qcom_llcc_probe(pdev, sm6150_data,
				 ARRAY_SIZE(sm6150_data));
}

static const struct of_device_id sm6150_qcom_llcc_of_match[] = {
	{ .compatible = "qcom,sm6150-llcc", },
	{ },
};

static struct platform_driver sm6150_qcom_llcc_driver = {
	.driver = {
		.name = "sm6150-llcc",
		.of_match_table = sm6150_qcom_llcc_of_match,
	},
	.probe = sm6150_qcom_llcc_probe,
};
module_platform_driver(sm6150_qcom_llcc_driver);

MODULE_DESCRIPTION("Qualcomm Technologies Inc sm6150 LLCC driver");
MODULE_LICENSE("GPL v2");
