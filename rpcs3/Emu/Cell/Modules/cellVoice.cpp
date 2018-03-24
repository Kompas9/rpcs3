#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/Cell/PPUModule.h"

#include "cellVoice.h"

logs::channel cellVoice("cellVoice");


s32 cellVoiceConnectIPortToOPort(u32 ips, u32 ops)
{
	cellVoice.todo("cellVoiceConnectIPortToOPort(ips=%d, ops=%d)", ips, ops);
	return CELL_OK;
}

s32 cellVoiceCreateNotifyEventQueue()
{
	UNIMPLEMENTED_FUNC(cellVoice);
	return CELL_OK;
}

s32 cellVoiceCreatePort(vm::ptr<u32> portId, vm::cptr<CellVoicePortParam> pArg)
{
	cellVoice.todo("cellVoiceCreatePort(portId=*0x%x, pArg=*0x%x)", portId, pArg);
	return CELL_OK;
}

s32 cellVoiceDeletePort(u32 portId)
{
	cellVoice.todo("cellVoiceDeletePort(portId=%d)", portId);
	return CELL_OK;
}

s32 cellVoiceDisconnectIPortFromOPort(u32 ips, u32 ops)
{
	cellVoice.todo("cellVoiceDisconnectIPortFromOPort(ips=%d, ops=%d)", ips, ops);
	return CELL_OK;
}

s32 cellVoiceEnd()
{
	cellVoice.todo("cellVoiceEnd()");
	return CELL_OK;
}

s32 cellVoiceGetBitRate(u32 portId, vm::ptr<u32> bitrate)
{
	cellVoice.todo("cellVoiceGetBitRate(portId=%d, bitrate=*0x%x)", portId, bitrate);
	return CELL_OK;
}

s32 cellVoiceGetMuteFlag(u32 portId, vm::ptr<u16> bMuted)
{
	cellVoice.todo("cellVoiceGetMuteFlag(portId=%d, bMuted=*0x%x)", portId, bMuted);
	return CELL_OK;
}

s32 cellVoiceGetPortAttr(u32 portId, s32 attr, vm::ptr<void> attrValue)
{
	cellVoice.todo("cellVoiceGetPortAttr(portId=%d, attr=*0x%x, attrValue=*0x%x)", portId, attr, attrValue);
	return CELL_OK;
}

s32 cellVoiceGetPortInfo(u32 portId, vm::ptr<s32> attr)
{
	cellVoice.todo("cellVoiceGetPortInfo(portId=%d, attr=*0x%x)", portId, attr);
	return CELL_OK;
}

s32 cellVoiceGetSignalState(u32 portId, s32 attr, vm::ptr<void> attrValue)
{
	cellVoice.todo("cellVoiceGetSignalState(portId=%d, attr=*0x%x, attrValue=*0x%x)", portId, attr, attrValue);
	return CELL_OK;
}

s32 cellVoiceGetVolume(u32 portId, vm::ptr<f32> volume)
{
	cellVoice.todo("cellVoiceGetVolume(portId=%d, volume=*0x%x)", portId, volume);
	return CELL_OK;
}

s32 cellVoiceInit(vm::ptr<CellVoiceInitParam> pArg)
{
	cellVoice.todo("cellVoiceInit(pArg=*0x%x)", pArg);
	return CELL_OK;
}

s32 cellVoiceInitEx(vm::ptr<CellVoiceInitParam> pArg)
{
	cellVoice.todo("cellVoiceInitEx(pArg=*0x%x)", pArg);
	return CELL_OK;
}

s32 cellVoicePausePort(u32 portId)
{
	cellVoice.todo("cellVoicePausePort(portId=%d)", portId);
	return CELL_OK;
}

s32 cellVoicePausePortAll()
{
	cellVoice.todo("cellVoicePausePortAll()");
	return CELL_OK;
}

s32 cellVoiceRemoveNotifyEventQueue()
{
	UNIMPLEMENTED_FUNC(cellVoice);
	return CELL_OK;
}

s32 cellVoiceResetPort(u32 portId)
{
	cellVoice.todo("cellVoiceResetPort(portId=%d)", portId);
	return CELL_OK;
}

s32 cellVoiceResumePort(u32 portId)
{
	cellVoice.todo("cellVoiceResumePort(portId=%d)", portId);
	return CELL_OK;
}

s32 cellVoiceResumePortAll()
{
	cellVoice.todo("cellVoiceResumePortAll()");
	return CELL_OK;
}

s32 cellVoiceSetBitRate(u32 portId, s32 bitrate)
{
	cellVoice.todo("cellVoiceSetBitRate(portId=%d, bitrate=*0x%x)", portId, bitrate);
	return CELL_OK;
}

s32 cellVoiceSetMuteFlag(u32 portId, u16 bMuted)
{
	cellVoice.todo("cellVoiceSetMuteFlagAll(portId=%d, bMuted=%d)", portId, bMuted);
	return CELL_OK;
}

s32 cellVoiceSetMuteFlagAll(u16 bMuted)
{
	cellVoice.todo("cellVoiceSetMuteFlagAll(bMuted=%d)", bMuted);
	return CELL_OK;
}

s32 cellVoiceSetNotifyEventQueue()
{
	UNIMPLEMENTED_FUNC(cellVoice);
	return CELL_OK;
}

s32 cellVoiceSetPortAttr(u32 portId, s32 attr, vm::ptr<void> attrValue)
{
	cellVoice.todo("cellVoiceSetPortAttr(portId=%d, attr=*0x%x, attrValue=*0x%x)", portId, attr, attrValue);
	return CELL_OK;
}

s32 cellVoiceSetVolume(u32 portId, f32 volume)
{
	cellVoice.todo("cellVoiceSetVolume(portId=%d, volume=%f)", portId, volume);
	return CELL_OK;
}

s32 cellVoiceStart()
{
	cellVoice.todo("cellVoiceStart()");
	return CELL_OK;
}

s32 cellVoiceStartEx(vm::ptr<CellVoiceStartParam> pArg)
{
	cellVoice.todo("cellVoiceStartEx(pArg=*0x%x)", pArg);
	return CELL_OK;
}

s32 cellVoiceStop()
{
	cellVoice.todo("cellVoiceStop()");
	return CELL_OK;
}

s32 cellVoiceUpdatePort(u32 portId, vm::cptr<CellVoiceStartParam> pArg)
{
	cellVoice.todo("cellVoiceUpdatePort(portId=%d, pArg=*0x%x)", portId, pArg);
	return CELL_OK;
}

s32 cellVoiceWriteToIPort(u32 ips, vm::cptr<void> data, vm::ptr<u32> size)
{
	cellVoice.todo("cellVoiceWriteToIPort(ips=%d, data=*0x%x, size=*0x%x)", ips, data, size);
	return CELL_OK;
}

s32 cellVoiceWriteToIPortEx(u32 ips, vm::cptr<void> data, vm::ptr<u32> size, u32 numFrameLost)
{
	cellVoice.todo("cellVoiceWriteToIPortEx(ips=%d, data=*0x%x, size=*0x%x, numFrameLost=%d)", ips, data, size, numFrameLost);
	return CELL_OK;
}

s32 cellVoiceWriteToIPortEx2(u32 ips, vm::cptr<void> data, vm::ptr<u32> size, s16 frameGaps)
{
	cellVoice.todo("cellVoiceWriteToIPortEx(ips=%d, data=*0x%x, size=*0x%x, frameGaps=%d)", ips, data, size, frameGaps);
	return CELL_OK;
}

s32 cellVoiceReadFromOPort(u32 ops, vm::ptr<void> data, vm::ptr<u32> size)
{
	cellVoice.todo("cellVoiceReadFromOPort(ops=%d, data=*0x%x, size=*0x%x)", ops, data, size);
	return CELL_OK;
}

s32 cellVoiceDebugTopology()
{
	UNIMPLEMENTED_FUNC(cellVoice);
	return CELL_OK;
}

DECLARE(ppu_module_manager::cellVoice)("cellVoice", []()
{
	REG_FUNC(cellVoice, cellVoiceConnectIPortToOPort);
	REG_FUNC(cellVoice, cellVoiceCreateNotifyEventQueue);
	REG_FUNC(cellVoice, cellVoiceCreatePort);
	REG_FUNC(cellVoice, cellVoiceDeletePort);
	REG_FUNC(cellVoice, cellVoiceDisconnectIPortFromOPort);
	REG_FUNC(cellVoice, cellVoiceEnd);
	REG_FUNC(cellVoice, cellVoiceGetBitRate);
	REG_FUNC(cellVoice, cellVoiceGetMuteFlag);
	REG_FUNC(cellVoice, cellVoiceGetPortAttr);
	REG_FUNC(cellVoice, cellVoiceGetPortInfo);
	REG_FUNC(cellVoice, cellVoiceGetSignalState);
	REG_FUNC(cellVoice, cellVoiceGetVolume);
	REG_FUNC(cellVoice, cellVoiceInit);
	REG_FUNC(cellVoice, cellVoiceInitEx);
	REG_FUNC(cellVoice, cellVoicePausePort);
	REG_FUNC(cellVoice, cellVoicePausePortAll);
	REG_FUNC(cellVoice, cellVoiceRemoveNotifyEventQueue);
	REG_FUNC(cellVoice, cellVoiceResetPort);
	REG_FUNC(cellVoice, cellVoiceResumePort);
	REG_FUNC(cellVoice, cellVoiceResumePortAll);
	REG_FUNC(cellVoice, cellVoiceSetBitRate);
	REG_FUNC(cellVoice, cellVoiceSetMuteFlag);
	REG_FUNC(cellVoice, cellVoiceSetMuteFlagAll);
	REG_FUNC(cellVoice, cellVoiceSetNotifyEventQueue);
	REG_FUNC(cellVoice, cellVoiceSetPortAttr);
	REG_FUNC(cellVoice, cellVoiceSetVolume);
	REG_FUNC(cellVoice, cellVoiceStart);
	REG_FUNC(cellVoice, cellVoiceStartEx);
	REG_FUNC(cellVoice, cellVoiceStop);
	REG_FUNC(cellVoice, cellVoiceUpdatePort);
	REG_FUNC(cellVoice, cellVoiceWriteToIPort);
	REG_FUNC(cellVoice, cellVoiceWriteToIPortEx);
	REG_FUNC(cellVoice, cellVoiceWriteToIPortEx2);
	REG_FUNC(cellVoice, cellVoiceReadFromOPort);
	REG_FUNC(cellVoice, cellVoiceDebugTopology);
});
