/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * HYGON Secure Processor interface
 *
 * Copyright (C) 2024 Hygon Info Technologies Ltd.
 *
 * Author: Liyang Han <hanliyang@hygon.cn>
 */

#ifndef __CCP_HYGON_SP_DEV_H__
#define __CCP_HYGON_SP_DEV_H__

#include <linux/processor.h>
#include <linux/ccp.h>

#include "../ccp-dev.h"
#include "../sp-dev.h"
#include "psp-dev.h"

#ifdef CONFIG_X86_64
static inline bool is_vendor_hygon(void)
{
	return boot_cpu_data.x86_vendor == X86_VENDOR_HYGON;
}
#else
static inline bool is_vendor_hygon(void) { return false; }
#endif

extern const struct sp_dev_vdata hygon_dev_vdata[];

#ifdef CONFIG_PM_SLEEP

int hygon_sp_suspend(struct sp_device *sp);
int hygon_sp_resume(struct sp_device *sp);
int hygon_sp_freeze(struct sp_device *sp);
int hygon_sp_thaw(struct sp_device *sp);
int hygon_sp_poweroff(struct sp_device *sp);
int hygon_sp_restore(struct sp_device *sp);

void hygon_set_pm_cb(struct pci_driver *drv);

#endif

#endif	/* __CCP_HYGON_SP_DEV_H__ */
