#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/Cell/PPUModule.h"

#include "cellMic.h"

logs::channel cellMic("cellMic");

s32 cellMicInit()
{
	cellMic.warning("cellMicInit()");

	return CELL_OK;
}

s32 cellMicEnd()
{
	cellMic.warning("cellMicEnd()");

	return CELL_OK;
}

s32 cellMicOpen(s32 dev_num, s32 samprate)
{
	cellMic.todo("cellMicOpen(dev_num=%d, samprate=%d)", dev_num, samprate);
	return CELL_OK;
}

s32 cellMicClose(s32 dev_num)
{
	cellMic.todo("cellMicClose(dev_num=%d)", dev_num);
	return CELL_OK;
}

s32 cellMicGetDeviceGUID(s32 dev_num, vm::ptr<u32> ptr_guid)
{
	cellMic.todo("cellMicGetDeviceGUID(dev_num=%d, ptr_guid=*0x%x)", dev_num, ptr_guid);
	return CELL_OK;
}

s32 cellMicGetType(s32 dev_num, vm::ptr<s32> ptr_type)
{
	cellMic.todo("cellMicGetType(dev_num=%d, ptr_type=*0x%x)", dev_num, ptr_type);
	return CELL_OK;
}

s32 cellMicIsAttached(s32 dev_num)
{
	cellMic.todo("cellMicIsAttached(dev_num=%d)", dev_num);
	return 0;
}

s32 cellMicIsOpen(s32 dev_num)
{
	cellMic.todo("cellMicIsOpen(dev_num=%d)", dev_num);
	return 0;
}

s32 cellMicGetDeviceAttr(s32 dev_num, u32 dev_attrib, vm::ptr<s32> arg1, vm::ptr<s32> arg2)
{
	cellMic.todo("cellMicGetDeviceAttr(dev_num=%d, dev_attrib=%d, arg1=*0x%x, arg2=*0x%x)", dev_num, dev_attrib, arg1, arg2);
	return CELL_OK;
}

s32 cellMicSetDeviceAttr(s32 dev_num, u32 dev_attrib, s32 arg1, s32 arg2)
{
	cellMic.todo("cellMicSetDeviceAttr(dev_num=%d, dev_attrib=%d, arg1=%d, arg2=%d)", dev_num, dev_attrib, arg1, arg2);
	return CELL_OK;
}

s32 cellMicGetSignalAttr(s32 dev_num, f32 sig_attrib, vm::ptr<void> value)
{
	cellMic.todo("cellMicGetSignalAttr(dev_num=%d, sig_attrib=%f, value=*0x%x)", dev_num, sig_attrib, value);
	return CELL_OK;
}

s32 cellMicSetSignalAttr(s32 dev_num, f32 sig_attrib, vm::ptr<void> value)
{
	cellMic.todo("cellMicSetSignalAttr(dev_num=%d, sig_attrib=%f, value=*0x%x)", dev_num, sig_attrib, value);
	return CELL_OK;
}

s32 cellMicGetSignalState(s32 dev_num, s32 sig_state, vm::ptr<void> value)
{
	cellMic.todo("cellMicGetSignalState(dev_num=%d, sig_state=%d, value=*0x%x)", dev_num, sig_state, value);
	return CELL_OK;
}

s32 cellMicStart(s32 dev_num)
{
	cellMic.todo("cellMicStart(dev_num=%d)", dev_num);
	return CELL_OK;
}

s32 cellMicRead(s32 dev_num, vm::ptr<void> data, s32 max_bytes)
{
	cellMic.todo("cellMicRead(dev_num=%d, data=*0x%x, max_bytes=%d)", dev_num, data, max_bytes);
	return CELL_OK;
}

s32 cellMicStop(s32 dev_num)
{
	cellMic.todo("cellMicStop(dev_num=%d)", dev_num);
	return CELL_OK;
}

s32 cellMicReset(s32 dev_num)
{
	cellMic.todo("cellMicReset(dev_num=%d)", dev_num);
	return CELL_OK;
}

s32 cellMicSetNotifyEventQueue()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicSetNotifyEventQueue2()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicRemoveNotifyEventQueue()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicOpenEx(s32 dev_num, s32 raw_samprate, s32 raw_channel, s32 dsp_samprate, s32 bufms, s32 sigtype)
{
	cellMic.todo("cellMicOpenEx(dev_num=%d, raw_samprate=%d, raw_channel=%d, dsp_samprate=%d, bufms=%d, sigtype=%d)", dev_num, raw_samprate, raw_channel, dsp_samprate, bufms, sigtype);
	return CELL_OK;
}

s32 cellMicStartEx(s32 dev_num, u32 iFlags)
{
	cellMic.todo("cellMicStartEx(dev_num=%d, iFlags=%d)", dev_num, iFlags);
	return CELL_OK;
}

s32 cellMicGetFormatRaw(s32 dev_num, vm::ptr<CellMicInputFormatI> format)
{
	cellMic.todo("cellMicGetFormatRaw(dev_num=%d, format=*0x%x)", dev_num, format);
	return CELL_OK;
}

s32 cellMicGetFormatAux(s32 dev_num, vm::ptr<CellMicInputFormatI> format)
{
	cellMic.todo("cellMicGetFormatAux(dev_num=%d, format=*0x%x)", dev_num, format);
	return CELL_OK;
}

s32 cellMicGetFormatDsp(s32 dev_num, vm::ptr<CellMicInputFormatI> format)
{
	cellMic.todo("cellMicGetFormatDsp(dev_num=%d, format=*0x%x)", dev_num, format);
	return CELL_OK;
}

s32 cellMicOpenRaw(s32 dev_num, s32 samprate, s32 channel)
{
	cellMic.todo("cellMicOpenRaw(dev_num=%d, samprate=%d, channel=%d)", dev_num, samprate, channel);
	return CELL_OK;
}

s32 cellMicReadRaw(s32 dev_num, vm::ptr<void> data, s32 max_bytes)
{
	cellMic.todo("cellMicReadRaw(dev_num=%d, data=*0x%x, max_bytes=%d)", dev_num, data, max_bytes);
	return CELL_OK;
}

s32 cellMicReadAux(s32 dev_num, vm::ptr<void> data, s32 max_bytes)
{
	cellMic.todo("cellMicReadAux(dev_num=%d, data=*0x%x, max_bytes=%d)", dev_num, data, max_bytes);
	return CELL_OK;
}

s32 cellMicReadDsp(s32 dev_num, vm::ptr<void> data, s32 max_bytes)
{
	cellMic.todo("cellMicReadDsp(dev_num=%d, data=*0x%x, max_bytes=%d)", dev_num, data, max_bytes);
	return CELL_OK;
}

s32 cellMicGetStatus()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicStopEx()
{
	fmt::throw_exception("Unexpected function" HERE);
}

s32 cellMicSysShareClose()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicGetFormat()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicSetMultiMicNotifyEventQueue()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicGetFormatEx()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicSysShareStop()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicSysShareOpen()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicCommand()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicSysShareStart()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicSysShareInit()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicSysShareEnd()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

s32 cellMicGetDeviceIdentifier()
{
	UNIMPLEMENTED_FUNC(cellMic);
	return CELL_OK;
}

DECLARE(ppu_module_manager::cellMic)("cellMic", []()
{
	REG_FUNC(cellMic, cellMicInit);
	REG_FUNC(cellMic, cellMicEnd);
	REG_FUNC(cellMic, cellMicOpen);
	REG_FUNC(cellMic, cellMicClose);
	REG_FUNC(cellMic, cellMicGetDeviceGUID);
	REG_FUNC(cellMic, cellMicGetType);
	REG_FUNC(cellMic, cellMicIsAttached);
	REG_FUNC(cellMic, cellMicIsOpen);
	REG_FUNC(cellMic, cellMicGetDeviceAttr);
	REG_FUNC(cellMic, cellMicSetDeviceAttr);
	REG_FUNC(cellMic, cellMicGetSignalAttr);
	REG_FUNC(cellMic, cellMicSetSignalAttr);
	REG_FUNC(cellMic, cellMicGetSignalState);
	REG_FUNC(cellMic, cellMicStart);
	REG_FUNC(cellMic, cellMicRead);
	REG_FUNC(cellMic, cellMicStop);
	REG_FUNC(cellMic, cellMicReset);
	REG_FUNC(cellMic, cellMicSetNotifyEventQueue);
	REG_FUNC(cellMic, cellMicSetNotifyEventQueue2);
	REG_FUNC(cellMic, cellMicRemoveNotifyEventQueue);
	REG_FUNC(cellMic, cellMicOpenEx);
	REG_FUNC(cellMic, cellMicStartEx);
	REG_FUNC(cellMic, cellMicGetFormatRaw);
	REG_FUNC(cellMic, cellMicGetFormatAux);
	REG_FUNC(cellMic, cellMicGetFormatDsp);
	REG_FUNC(cellMic, cellMicOpenRaw);
	REG_FUNC(cellMic, cellMicReadRaw);
	REG_FUNC(cellMic, cellMicReadAux);
	REG_FUNC(cellMic, cellMicReadDsp);
	REG_FUNC(cellMic, cellMicGetStatus);
	REG_FUNC(cellMic, cellMicStopEx); // this function shouldn't exist
	REG_FUNC(cellMic, cellMicSysShareClose);
	REG_FUNC(cellMic, cellMicGetFormat);
	REG_FUNC(cellMic, cellMicSetMultiMicNotifyEventQueue);
	REG_FUNC(cellMic, cellMicGetFormatEx);
	REG_FUNC(cellMic, cellMicSysShareStop);
	REG_FUNC(cellMic, cellMicSysShareOpen);
	REG_FUNC(cellMic, cellMicCommand);
	REG_FUNC(cellMic, cellMicSysShareStart);
	REG_FUNC(cellMic, cellMicSysShareInit);
	REG_FUNC(cellMic, cellMicSysShareEnd);
	REG_FUNC(cellMic, cellMicGetDeviceIdentifier);
});
