#pragma once



#include "cellRtc.h"

// Constants for TUS functions and structures
enum
{
	SCE_NP_TUS_DATA_INFO_MAX_SIZE = 384,
	SCE_NP_TUS_MAX_CTX_NUM = 32,
	SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS = 64,
	SCE_NP_TUS_MAX_USER_NUM_PER_TRANS = 101,
	SCE_NP_TUS_MAX_SELECTED_FRIENDS_NUM = 100,
};

enum SceNpTssStatusCodeType
{
	SCE_NP_TSS_STATUS_TYPE_OK,
	SCE_NP_TSS_STATUS_TYPE_PARTIAL,
	SCE_NP_TSS_STATUS_TYPE_NOT_MODIFIED
};

enum SceNpTssIfType
{
	SCE_NP_TSS_IFTYPE_IF_MODIFIED_SINCE,
	SCE_NP_TSS_IFTYPE_IF_RANGE
};

using SceNpTssSlotId = s32;
using SceNpTusSlotId = s32;
using SceNpTusVirtualUserId = SceNpOnlineId;

// Structure for representing a TUS variable
struct SceNpTusVariable
{
	SceNpId ownerId;
	be_t<s32> hasData;
	u8 pad[4];
	CellRtcTick lastChangedDate;
	SceNpId lastChangedAuthorId;
	be_t<s64> variable;
	be_t<s64> oldVariable;
	u8 reserved[16];
};

// Structure for representing the accessory information of a TUS data
struct SceNpTusDataInfo
{
	be_t<u32> infoSize;
	u8 pad[4];
	u8 data[SCE_NP_TUS_DATA_INFO_MAX_SIZE];
};

// Structure for respreseting the status of TUS data
struct SceNpTusDataStatus
{
	SceNpId ownerId;
	be_t<s32> hasData;
	CellRtcTick lastChangedDate;
	SceNpId lastChangedAuthorId;
	be_t<u32> data;
	be_t<u32> dataSize;
	u8 pad[4];
	SceNpTusDataInfo info;
};

struct SceNpTusAddAndGetVariableOptParam
{
	u64 size;
	vm::ptr<CellRtcTick> isLastChangedDate;
	vm::ptr<SceNpId> isLastChangedAuthorId;
};

struct SceNpTusTryAndSetVariableOptParam
{
	u64 size;
	vm::ptr<CellRtcTick> isLastChangedDate;
	vm::ptr<SceNpId> isLastChangedAuthorId;
	vm::ptr<s64> compareValue;
};

struct SceNpTusSetDataOptParam
{
	u64 size;
	vm::ptr<CellRtcTick> isLastChangedDate;
	vm::ptr<SceNpId> isLastChangedAuthorId;
};

struct SceNpTssDataStatus
{
	CellRtcTick lastModified;
	s32 statusCodeType;
	u64 contentLength;
};

struct SceNpTssIfModifiedSinceParam
{
	s32 ifType;
	u8 padding[4];
	CellRtcTick lastModified;
};

struct SceNpTssGetDataOptParam
{
	u64 size;
	vm::ptr<uint64_t> offset;
	vm::ptr<uint64_t> lastByte;
	vm::ptr<SceNpTssIfModifiedSinceParam> ifParam;
};
