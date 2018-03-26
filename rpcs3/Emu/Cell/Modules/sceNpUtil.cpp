#include "stdafx.h"
#include "Emu/Cell/PPUModule.h"

#include "sceNp.h"
#include "sceNpUtil.h"

logs::channel sceNpUtil("sceNpUtil");

s32 sceNpUtilBandwidthTestInitStart(u32 prio, u64 stack)
{
	sceNpUtil.todo("sceNpUtilBandwidthTestInitStart(prio=%d, stack=%d)", prio, stack);
	return CELL_OK;
}

s32 sceNpUtilBandwidthTestGetStatus()
{
	sceNpUtil.todo("sceNpUtilBandwidthTestGetStatus()");
	return CELL_OK;
}

s32 sceNpUtilBandwidthTestShutdown(vm::ptr<SceNpUtilBandwidthTestResult> result)
{
	sceNpUtil.todo("sceNpUtilBandwidthTestShutdown(result=*0x%x)", result);
	return CELL_OK;
}

s32 sceNpUtilBandwidthTestAbort()
{
	sceNpUtil.todo("sceNpUtilBandwidthTestAbort()");
	return CELL_OK;
}

DECLARE(ppu_module_manager::sceNpUtil)("sceNpUtil", []()
{
	REG_FUNC(sceNpUtil, sceNpUtilBandwidthTestInitStart);
	REG_FUNC(sceNpUtil, sceNpUtilBandwidthTestShutdown);
	REG_FUNC(sceNpUtil, sceNpUtilBandwidthTestGetStatus);
	REG_FUNC(sceNpUtil, sceNpUtilBandwidthTestAbort);
});
