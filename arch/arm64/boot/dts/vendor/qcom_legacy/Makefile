# SPDX-License-Identifier: GPL-2.0

ifeq ($(CONFIG_BUILD_ARM64_DT_OVERLAY),y)
dtbo-$(CONFIG_ARCH_SM8150) += \
	sm8150-mtp-overlay.dtbo

sm8150-mtp-overlay.dtbo-base := sm8150.dtb sm8150-v2.dtb

dtbo-$(CONFIG_ARCH_SDMMAGPIE) += \
	sdmmagpie-idp-overlay.dtbo

sdmmagpie-idp-overlay.dtbo-base := sdmmagpie.dtb
else
dtb-$(CONFIG_ARCH_SM8150) += \
	sm8150.dtb \
	sm8150-v2.dtb \
	sm8150-mtp.dtb \
	sm8150-v2-mtp.dtb

dtb-$(CONFIG_ARCH_SDMMAGPIE) += \
	sdmmagpie.dtb \
	sdmmagpie-idp.dtb
endif

always		:= $(dtb-y)
subdir-y	:= $(dts-dirs)
clean-files    	:= *.dtb *.dtbo
