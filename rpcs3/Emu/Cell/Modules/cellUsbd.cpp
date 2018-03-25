#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/Cell/PPUModule.h"
#include "cellUsbd.h"

logs::channel cellUsbd("cellUsbd");

s32 cellUsbdInit()
{
	cellUsbd.warning("cellUsbdInit()");

	return CELL_OK;
}

s32 cellUsbdEnd()
{
	cellUsbd.warning("cellUsbdEnd()");

	return CELL_OK;
}

s32 cellUsbdSetThreadPriority()
{
	UNIMPLEMENTED_FUNC(cellUsbd);
	return CELL_OK;
}

s32 cellUsbdSetThreadPriority2(s32 event_prio, s32 usbd_prio, s32 callback_prio)
{
	cellUsbd.todo("cellUsbdSetThreadPriority2(event_prio=%d, usbd_prio=%d, callback_prio=%d)", event_prio, usbd_prio, callback_prio);
	return CELL_OK;
}

s32 cellUsbdGetThreadPriority(s32 thread_type)
{
	cellUsbd.todo("cellUsbdGetThreadPriority(thread_type=%d)", thread_type);
	return CELL_OK;
}

s32 cellUsbdRegisterLdd(vm::ptr<CellUsbdLddOps> lddops)
{
	cellUsbd.todo("cellUsbdRegisterLdd(lddops=*0x%x)", lddops);
	return CELL_OK;
}

s32 cellUsbdRegisterCompositeLdd()
{
	UNIMPLEMENTED_FUNC(cellUsbd);
	return CELL_OK;
}

s32 cellUsbdRegisterExtraLdd(vm::ptr<CellUsbdLddOps> lddops, u16 id_vendor, u16 id_product)
{
	cellUsbd.todo("cellUsbdRegisterExtraLdd(lddops=*0x%x, id_vendor=%d, id_product=%d)", lddops, id_vendor, id_product);
	return CELL_OK;
}

s32 cellUsbdRegisterExtraLdd2(vm::ptr<CellUsbdLddOps> lddops, u16 id_vendor, u16 id_product_min, u16 id_product_max)
{
	cellUsbd.todo("cellUsbdRegisterExtraLdd2(lddops=*0x%x, id_vendor=%d, id_product_min=%d, id_product_max=%d)", lddops, id_vendor, id_product_min, id_product_max);
	return CELL_OK;
}

s32 cellUsbdUnregisterLdd(vm::ptr<CellUsbdLddOps> lddops)
{
	cellUsbd.todo("cellUsbdUnregisterLdd(lddops=*0x%x)", lddops);
	return CELL_OK;
}

s32 cellUsbdUnregisterCompositeLdd()
{
	UNIMPLEMENTED_FUNC(cellUsbd);
	return CELL_OK;
}

s32 cellUsbdUnregisterExtraLdd(vm::ptr<CellUsbdLddOps> lddops)
{
	cellUsbd.todo("cellUsbdUnregisterExtraLdd(lddops=*0x%x)", lddops);
	return CELL_OK;
}

s32 cellUsbdOpenPipe(s32 dev_id, vm::ptr<void/*UsbEndpointDescriptor*/> ed)
{
	cellUsbd.todo("cellUsbdOpenPipe(dev_id=%d, ed=*0x%x)", dev_id, ed);
	return CELL_OK;
}

s32 cellUsbdClosePipe(s32 pipe_id)
{
	cellUsbd.todo("cellUsbdClosePipe(pipe_id=%d)", pipe_id);
	return CELL_OK;
}

s32 cellUsbdControlTransfer(s32 pipe_id, vm::ptr<void/*UsbDeviceRequest*/> dr, vm::ptr<void> buf, vm::ptr<CellUsbdDoneCallback> done_cb, vm::ptr<void> arg)
{
	cellUsbd.todo("cellUsbdControlTransfer(pipe_id=%d, dr=*0x%x, buf=*0x%x, done_cb=*0x%x, arg=*0x%x)", pipe_id, dr, buf, done_cb, arg);
	return CELL_OK;
}

s32 cellUsbdBulkTransfer(s32 pipe_id, vm::ptr<void> buf, s32 len, vm::ptr<CellUsbdDoneCallback> done_cb, vm::ptr<void> arg)
{
	cellUsbd.todo("cellUsbdBulkTransfer(pipe_id=%d, buf=*0x%x, len=%d, done_cb=*0x%x, arg=*0x%x)", pipe_id, buf, len, done_cb, arg);
	return CELL_OK;
}

s32 cellUsbdInterruptTransfer(s32 pipe_id, vm::ptr<void> buf, s32 len, vm::ptr<CellUsbdDoneCallback> done_cb, vm::ptr<void> arg)
{
	cellUsbd.todo("cellUsbdInterruptTransfer(pipe_id=%d, buf=*0x%x, len=%d, done_cb=*0x%x, arg=*0x%x)", pipe_id, buf, len, done_cb, arg);
	return CELL_OK;
}

s32 cellUsbdIsochronousTransfer(s32 pipe_id, vm::ptr<CellUsbdIsochRequest> req, vm::ptr<CellUsbdIsochDoneCallback> done_cb, vm::ptr<void> arg)
{
	cellUsbd.todo("cellUsbdIsochronousTransfer(pipe_id=%d, req=*0x%x, done_cb=*0x%x, arg=*0x%x)", pipe_id, req, done_cb, arg);
	return CELL_OK;
}

s32 cellUsbdHSIsochronousTransfer(s32 pipe_id, vm::ptr<CellUsbdIsochRequest> req, vm::ptr<CellUsbdIsochDoneCallback> done_cb, vm::ptr<void> arg)
{
	cellUsbd.todo("cellUsbdHSIsochronousTransfer(pipe_id=%d, req=*0x%x, done_cb=*0x%x, arg=*0x%x)", pipe_id, req, done_cb, arg);
	return CELL_OK;
}

vm::ptr<void> cellUsbdScanStaticDescriptor(s32 dev_id, vm::ptr<void> ptr, u8 type)
{
	cellUsbd.todo("cellUsbdScanStaticDescriptor(dev_id=%d, ptr=*0x%x, type=%d)", dev_id, ptr, type);
	return vm::null;
}

s32 cellUsbdGetDeviceSpeed(s32 dev_id, vm::ptr<u8> speed)
{
	cellUsbd.todo("cellUsbdGetDeviceSpeed(dev_id=%d, speed=*0x%x)", dev_id, speed);
	return CELL_OK;
}

s32 cellUsbdGetDeviceLocation(s32 dev_id, vm::ptr<u8> location)
{
	cellUsbd.todo("cellUsbdGetDeviceLocation(dev_id=%d, location=*0x%x)", dev_id, location);
	return CELL_OK;
}

s32 cellUsbdSetPrivateData(s32 dev_id, vm::ptr<void> priv)
{
	cellUsbd.todo("cellUsbdSetPrivateData(dev_id=%d, priv=*0x%x)", dev_id, priv);
	return CELL_OK;
}

vm::ptr<void> cellUsbdGetPrivateData(s32 dev_id)
{
	cellUsbd.todo("cellUsbdGetPrivateData(dev_id=%d)", dev_id);
	return vm::null;
}

s32 cellUsbdAllocateMemory(vm::pptr<void> ptr, u64 size)
{
	cellUsbd.todo("cellUsbdAllocateMemory(ptr=*0x%x, size=%d)", ptr, size);
	return CELL_OK;
}

s32 cellUsbdFreeMemory(vm::ptr<void> ptr)
{
	cellUsbd.todo("cellUsbdFreeMemory(ptr=*0x%x)", ptr);
	return CELL_OK;
}

s32 cellUsbdResetDevice()
{
	UNIMPLEMENTED_FUNC(cellUsbd);
	return CELL_OK;
}


DECLARE(ppu_module_manager::cellUsbd)("cellUsbd", []()
{
	REG_FUNC(cellUsbd, cellUsbdInit);
	REG_FUNC(cellUsbd, cellUsbdEnd);

	REG_FUNC(cellUsbd, cellUsbdSetThreadPriority);
	REG_FUNC(cellUsbd, cellUsbdSetThreadPriority2);
	REG_FUNC(cellUsbd, cellUsbdGetThreadPriority);

	REG_FUNC(cellUsbd, cellUsbdRegisterLdd);
	REG_FUNC(cellUsbd, cellUsbdRegisterCompositeLdd);
	REG_FUNC(cellUsbd, cellUsbdRegisterExtraLdd);
	REG_FUNC(cellUsbd, cellUsbdRegisterExtraLdd2);
	REG_FUNC(cellUsbd, cellUsbdUnregisterLdd);
	REG_FUNC(cellUsbd, cellUsbdUnregisterCompositeLdd);
	REG_FUNC(cellUsbd, cellUsbdUnregisterExtraLdd);

	REG_FUNC(cellUsbd, cellUsbdOpenPipe);
	REG_FUNC(cellUsbd, cellUsbdClosePipe);

	REG_FUNC(cellUsbd, cellUsbdControlTransfer);
	REG_FUNC(cellUsbd, cellUsbdBulkTransfer);
	REG_FUNC(cellUsbd, cellUsbdInterruptTransfer);
	REG_FUNC(cellUsbd, cellUsbdIsochronousTransfer);
	REG_FUNC(cellUsbd, cellUsbdHSIsochronousTransfer);

	REG_FUNC(cellUsbd, cellUsbdScanStaticDescriptor);
	REG_FUNC(cellUsbd, cellUsbdGetDeviceSpeed);
	REG_FUNC(cellUsbd, cellUsbdGetDeviceLocation);

	REG_FUNC(cellUsbd, cellUsbdSetPrivateData);
	REG_FUNC(cellUsbd, cellUsbdGetPrivateData);

	REG_FUNC(cellUsbd, cellUsbdAllocateMemory);
	REG_FUNC(cellUsbd, cellUsbdFreeMemory);

	REG_FUNC(cellUsbd, cellUsbdResetDevice);
});
