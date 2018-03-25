#include "stdafx.h"
#include "Emu/Cell/PPUModule.h"

#include "cellPngEnc.h"

logs::channel cellPngEnc("cellPngEnc");

// Error Codes
enum
{
	CELL_PNGENC_ERROR_ARG   = 0x80611291,
	CELL_PNGENC_ERROR_SEQ   = 0x80611292,
	CELL_PNGENC_ERROR_BUSY  = 0x80611293,
	CELL_PNGENC_ERROR_EMPTY = 0x80611294,
	CELL_PNGENC_ERROR_RESET = 0x80611295,
	CELL_PNGENC_ERROR_FATAL = 0x80611296,
};

s32 cellPngEncQueryAttr(vm::cptr<CellPngEncConfig> config, vm::ptr<CellPngEncAttr> attr)
{
	cellPngEnc.todo("cellPngEncQueryAttr(config=*0x%x, attr=*0x%x)", config, attr);
	return CELL_OK;
}

s32 cellPngEncOpen(vm::cptr<CellPngEncConfig> config, vm::cptr<CellPngEncResource> resource, vm::pptr<void> handle)
{
	cellPngEnc.todo("cellPngEncOpen(config=*0x%x, resource=*0x%x, handle=*0x%x)", config, resource, handle);
	return CELL_OK;
}

s32 cellPngEncOpenEx(vm::cptr<CellPngEncConfig> config, vm::cptr<CellPngEncResourceEx> resourceEx, vm::pptr<void> handle)
{
	cellPngEnc.todo("cellPngEncOpenEx(config=*0x%x, resourceEx=*0x%x, handle=*0x%x)", config, resourceEx, handle);
	return CELL_OK;
}

s32 cellPngEncClose(vm::ptr<void> handle)
{
	cellPngEnc.todo("cellPngEncClose(handle=*0x%x)", handle);
	return CELL_OK;
}

s32 cellPngEncWaitForInput(vm::ptr<void> handle, b8 block)
{
	cellPngEnc.todo("cellPngEncWaitForInput(handle=*0x%x, block=%d)", handle, block);
	return CELL_OK;
}

s32 cellPngEncEncodePicture(vm::ptr<void> handle, vm::cptr<CellPngEncPicture> picture, vm::cptr<CellPngEncEncodeParam> encodeParam, vm::cptr<CellPngEncOutputParam> outputParam)
{
	cellPngEnc.todo("cellPngEncEncodePicture(handle=*0x%x, picture=*0x%x, encodeParam=*0x%x, outputParam=*0x%x)", handle, picture, encodeParam, outputParam);
	return CELL_OK;
}

s32 cellPngEncWaitForOutput(vm::ptr<void> handle, vm::ptr<u32> streamInfoNum, b8 block)
{
	cellPngEnc.todo("cellPngEncWaitForOutput(handle=*0x%x, streamInfoNum=*0x%x, block=%d)", handle, streamInfoNum, block);
	return CELL_OK;
}

s32 cellPngEncGetStreamInfo(vm::ptr<void> handle, vm::ptr<CellPngEncStreamInfo> streamInfo)
{
	cellPngEnc.todo("cellPngEncGetStreamInfo(handle=*0x%x, streamInfo=*0x%x)", handle, streamInfo);
	return CELL_OK;
}

s32 cellPngEncReset(vm::ptr<void> handle)
{
	cellPngEnc.todo("cellPngEncReset(handle=*0x%x)", handle);
	return CELL_OK;
}

DECLARE(ppu_module_manager::cellPngEnc)("cellPngEnc", []()
{
	REG_FUNC(cellPngEnc, cellPngEncQueryAttr);
	REG_FUNC(cellPngEnc, cellPngEncOpen);
	REG_FUNC(cellPngEnc, cellPngEncOpenEx);
	REG_FUNC(cellPngEnc, cellPngEncClose);
	REG_FUNC(cellPngEnc, cellPngEncWaitForInput);
	REG_FUNC(cellPngEnc, cellPngEncEncodePicture);
	REG_FUNC(cellPngEnc, cellPngEncWaitForOutput);
	REG_FUNC(cellPngEnc, cellPngEncGetStreamInfo);
	REG_FUNC(cellPngEnc, cellPngEncReset);
});
