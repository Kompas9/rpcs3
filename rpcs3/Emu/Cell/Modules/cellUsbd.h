#pragma once



// Return Codes
enum
{
	CELL_USBD_ERROR_NOT_INITIALIZED        = 0x80110001,
	CELL_USBD_ERROR_ALREADY_INITIALIZED    = 0x80110002,
	CELL_USBD_ERROR_NO_MEMORY              = 0x80110003,
	CELL_USBD_ERROR_INVALID_PARAM          = 0x80110004,
	CELL_USBD_ERROR_INVALID_TRANSFER_TYPE  = 0x80110005,
	CELL_USBD_ERROR_LDD_ALREADY_REGISTERED = 0x80110006,
	CELL_USBD_ERROR_LDD_NOT_ALLOCATED      = 0x80110007,
	CELL_USBD_ERROR_LDD_NOT_RELEASED       = 0x80110008,
	CELL_USBD_ERROR_LDD_NOT_FOUND          = 0x80110009,
	CELL_USBD_ERROR_DEVICE_NOT_FOUND       = 0x8011000a,
	CELL_USBD_ERROR_PIPE_NOT_ALLOCATED     = 0x8011000b,
	CELL_USBD_ERROR_PIPE_NOT_RELEASED      = 0x8011000c,
	CELL_USBD_ERROR_PIPE_NOT_FOUND         = 0x8011000d,
	CELL_USBD_ERROR_IOREQ_NOT_ALLOCATED    = 0x8011000e,
	CELL_USBD_ERROR_IOREQ_NOT_RELEASED     = 0x8011000f,
	CELL_USBD_ERROR_IOREQ_NOT_FOUND        = 0x80110010,
	CELL_USBD_ERROR_CANNOT_GET_DESCRIPTOR  = 0x80110011,
	CELL_USBD_ERROR_FATAL                  = 0x801100ff,
};

// TCC (Transfer Completion Codes)
enum
{
	HC_CC_NOERR     = 0x0,
	EHCI_CC_MISSMF  = 0x10,
	EHCI_CC_XACT    = 0x20,
	EHCI_CC_BABBLE  = 0x30,
	EHCI_CC_DATABUF = 0x40,
	EHCI_CC_HALTED  = 0x50,

	USBD_HC_CC_NOERR   = 0x0,
	USBD_HC_CC_MISSMF  = 0x1,
	USBD_HC_CC_XACT    = 0x2,
	USBD_HC_CC_BABBLE  = 0x4,
	USBD_HC_CC_DATABUF = 0x8,
};

enum
{
	CELL_USBD_MAX_ISOCH_PACKETS = 8, // ?
};

struct CellUsbdIsochPswLen
{
	u16 len:11;
	u16 reserved:1;
	u16 PSW:4;
};

struct CellUsbdIsochRequest
{
	vm::ptr<void> buffer_base;
	s32 relative_start_frame;
	s32 num_packets;
	vm::ptr<CellUsbdIsochPswLen[CELL_USBD_MAX_ISOCH_PACKETS]> Packets;
};

struct CellUsbdLddOps
{
	vm::cptr<u8> name;
	using probe = s32(s32 dev_id);
	using attach = s32(s32 dev_id);
	using detach = s32(s32 dev_id);
};

using CellUsbdDoneCallback = void(s32 result, s32 count, vm::ptr<void> arg);
using CellUsbdIsochDoneCallback = void(s32 result, vm::ptr<CellUsbdIsochRequest> req, vm::ptr<void> arg);
