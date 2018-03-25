#include "stdafx.h"
#include "Emu/Cell/PPUModule.h"

#include "cellUsbPspcm.h"

logs::channel cellUsbPspcm("cellUsbPspcm");

s32 cellUsbPspcmInit(vm::cptr<CellUsbPspcmInitParam> pInitParam)
{
	cellUsbPspcm.todo("cellUsbPspcmInit(pInitParam=*0x%x)", pInitParam);
	return CELL_OK;
}

s32 cellUsbPspcmEnd()
{
	cellUsbPspcm.todo("cellUsbPspcmEnd()");
	return CELL_OK;
}

s32 cellUsbPspcmCalcPoolSize(vm::cptr<CellUsbPspcmInitParam> pInitParam)
{
	cellUsbPspcm.todo("cellUsbPspcmCalcPoolSize(pInitParam=*0x%x)", pInitParam);
	return CELL_OK;
}

s32 cellUsbPspcmRegister(vm::ptr<CellUsbPspcmConnectFunc> pFunc)
{
	cellUsbPspcm.todo("cellUsbPspcmRegister(pFunc=*0x%x)", pFunc);
	return CELL_OK;
}

s32 cellUsbPspcmUnregister(vm::ptr<CellUsbPspcmConnectFunc> pFunc)
{
	cellUsbPspcm.todo("cellUsbPspcmUnregister(pFunc=*0x%x)", pFunc);
	return CELL_OK;
}

s32 cellUsbPspcmGetAddr()
{
	cellUsbPspcm.todo("cellUsbPspcmGetAddr()");
	return CELL_OK;
}

s32 cellUsbPspcmBind(s32 addr)
{
	cellUsbPspcm.todo("cellUsbPspcmBind(addr=%d)", addr);
	return CELL_OK;
}

s32 cellUsbPspcmBindAsync(s32 addr)
{
	cellUsbPspcm.todo("cellUsbPspcmBindAsync(addr=%d)", addr);
	return CELL_OK;
}

s32 cellUsbPspcmWaitBindAsync(s32 addr)
{
	cellUsbPspcm.todo("cellUsbPspcmWaitBindAsync(addr=%d)", addr);
	return CELL_OK;
}

s32 cellUsbPspcmPollBindAsync(s32 addr)
{
	cellUsbPspcm.todo("cellUsbPspcmPollBindAsync(addr=%d)", addr);
	return CELL_OK;
}

s32 cellUsbPspcmCancelBind(s32 addr)
{
	cellUsbPspcm.todo("cellUsbPspcmCancelBind(addr=%d)", addr);
	return CELL_OK;
}

s32 cellUsbPspcmClose(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmClose(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmSend(s32 chIdx, vm::ptr<u8> buf, u64 size, u32 mode)
{
	cellUsbPspcm.todo("cellUsbPspcmSend(chIdx=%d, buf=*, size=%d, mode=%d)", chIdx, buf, size, mode);
	return CELL_OK;
}

s32 cellUsbPspcmSendAsync(s32 chIdx, vm::ptr<u8> buf, u64 size, u32 mode)
{
	cellUsbPspcm.todo("cellUsbPspcmSendAsync(chIdx=%d, buf=*, size=%d, mode=%d)", chIdx, buf, size, mode);
	return CELL_OK;
}

s32 cellUsbPspcmWaitSendAsync(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmWaitSendAsync(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmPollSendAsync(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmPollSendAsync(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmRecv(s32 chIdx, vm::ptr<u8> buf, u64 size, u32 mode)
{
	cellUsbPspcm.todo("cellUsbPspcmRecv(chIdx=%d, buf=*, size=%d, mode=%d)", chIdx, buf, size, mode);
	return CELL_OK;
}

s32 cellUsbPspcmRecvAsync(s32 chIdx, vm::ptr<u8> buf, u64 size, u32 mode)
{
	cellUsbPspcm.todo("cellUsbPspcmRecvAsync(chIdx=%d, buf=*, size=%d, mode=%d)", chIdx, buf, size, mode);
	return CELL_OK;
}

s32 cellUsbPspcmWaitRecvAsync(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmWaitRecvAsync(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmPollRecvAsync(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmPollRecvAsync(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmReset(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmReset(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmResetAsync(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmResetAsync(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmWaitResetAsync(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmWaitResetAsync(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmPollResetAsync(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmPollResetAsync(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmWaitData(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmWaitData(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmPollData(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmPollData(chIdx=%d)", chIdx);
	return CELL_OK;
}

s32 cellUsbPspcmCancelWaitData(s32 chIdx)
{
	cellUsbPspcm.todo("cellUsbPspcmCancelWaitData(chIdx=%d)", chIdx);
	return CELL_OK;
}

DECLARE(ppu_module_manager::cellUsbPspcm)("cellUsbPspcm", []()
{
	REG_FUNC(cellUsbPspcm, cellUsbPspcmInit);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmEnd);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmCalcPoolSize);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmRegister);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmUnregister);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmGetAddr);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmBind);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmBindAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmWaitBindAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmPollBindAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmCancelBind);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmClose);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmSend);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmSendAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmWaitSendAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmPollSendAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmRecv);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmRecvAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmWaitRecvAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmPollRecvAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmReset);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmResetAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmWaitResetAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmPollResetAsync);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmWaitData);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmPollData);
	REG_FUNC(cellUsbPspcm, cellUsbPspcmCancelWaitData);
});
