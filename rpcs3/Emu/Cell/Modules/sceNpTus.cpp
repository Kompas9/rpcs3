#include "stdafx.h"
#include "Emu/Cell/PPUModule.h"

#include "sceNp.h"
#include "sceNpTus.h"

logs::channel sceNpTus("sceNpTus");

s32 sceNpTusInit()
{
	sceNpTus.warning("sceNpTusInit()");

	return CELL_OK;
}

s32 sceNpTusTerm()
{
	sceNpTus.warning("sceNpTusTerm()");

	return CELL_OK;
}

s32 sceNpTusCreateTitleCtx(vm::cptr<SceNpCommunicationId> communicationId, vm::cptr<SceNpCommunicationPassphrase> passphrase, vm::cptr<SceNpId> selfNpId)
{
	sceNpTus.todo("sceNpTusCreateTitleCtx(communicationId=*0x%x, passphrase=*0x%x, selfNpId=*0x%x)", communicationId, passphrase, selfNpId);

	if (!communicationId || !passphrase || !selfNpId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusDestroyTitleCtx(s32 titleCtxId)
{
	sceNpTus.todo("sceNpTusDestroyTitleCtx(titleCtxId=%d)", titleCtxId);
	return CELL_OK;
}

s32 sceNpTusCreateTransactionCtx(s32 titleCtxId)
{
	sceNpTus.todo("sceNpTusCreateTransactionCtx(titleCtxId=%d)", titleCtxId);
	return CELL_OK;
}

s32 sceNpTusDestroyTransactionCtx(s32 transId)
{
	sceNpTus.todo("sceNpTusDestroyTransactionCtx(transId=%d)", transId);
	return CELL_OK;
}

s32 sceNpTusSetTimeout(s32 ctxId, u32 timeout)
{
	sceNpTus.todo("sceNpTusSetTimeout(ctxId=%d, timeout=%d)", ctxId, timeout);

	if (timeout < 10000000) // 10 seconds
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusAbortTransaction(s32 transId)
{
	sceNpTus.todo("sceNpTusAbortTransaction(transId=%d)", transId);
	return CELL_OK;
}

s32 sceNpTusWaitAsync(s32 transId, vm::ptr<s32> result)
{
	sceNpTus.todo("sceNpTusWaitAsync(transId=%d, result=*0x%x)", transId, result);
	return CELL_OK;
}

s32 sceNpTusPollAsync(s32 transId, vm::ptr<s32> result)
{
	sceNpTus.todo("sceNpTusPollAsync(transId=%d, result=*0x%x)", transId, result);
	return CELL_OK;
}

auto ValidSlotIds = [](vm::cptr<SceNpTusSlotId> slotIdArray)
{
	for (int i = 0; i < slotIdArray.size(); ++i)
	{
		if (slotIdArray[i] < 0)
		{
			return false;
		}
	}
	return true;
};

s32 sceNpTusSetMultiSlotVariable(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusSetMultiSlotVariable(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, variableArray, arrayNum, option);

	if (!targetNpId || !slotIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusSetMultiSlotVariableVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusSetMultiSlotVariableVUser(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, variableArray, arrayNum, option);

	if (!targetVirtualUserId || !slotIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusSetMultiSlotVariableAsync(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusSetMultiSlotVariableAsync(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, variableArray, arrayNum, option);

	if (!targetNpId || !slotIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusSetMultiSlotVariableVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusSetMultiSlotVariableVUserAsync(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, variableArray, arrayNum, option);

	if (!targetVirtualUserId || !slotIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotVariable(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotVariable(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, variableArray, variableArraySize, arrayNum, option);

	if (!targetNpId || !slotIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotVariableVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotVariableVUser(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, variableArray, variableArraySize, arrayNum, option);

	if (!targetVirtualUserId || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotVariableAsync(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotVariableAsync(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, variableArray, variableArraySize, arrayNum, option);

	if (!targetNpId || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotVariableVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::cptr<s64> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotVariableVUserAsync(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, variableArray, variableArraySize, arrayNum, option);

	if (!targetVirtualUserId || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserVariable(s32 transId, vm::cptr<SceNpId> targetNpIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusVariable> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserVariable(transId=%d, targetNpIdArray=*0x%x, slotId=%d, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpIdArray, slotId, variableArray, variableArraySize, arrayNum, option);

	if (!targetNpIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserVariableVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusVariable> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserVariableVUser(transId=%d, targetVirtualUserIdArray=*0x%x, slotId=%d, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserIdArray, slotId, variableArray, variableArraySize, arrayNum, option);

	if (!targetVirtualUserIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserVariableAsync(s32 transId, vm::cptr<SceNpId> targetNpIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusVariable> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserVariableAsync(transId=%d, targetNpIdArray=*0x%x, slotId=%d, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpIdArray, slotId, variableArray, variableArraySize, arrayNum, option);

	if (!targetNpIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserVariableVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusVariable> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserVariableVUserAsync(transId=%d, targetVirtualUserIdArray=*0x%x, slotId=%d, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserIdArray, slotId, variableArray, variableArraySize, arrayNum, option);

	if (!targetVirtualUserIdArray || !variableArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetFriendsVariable(s32 transId, SceNpTusSlotId slotId, s32 includeSelf, s32 sortType, vm::ptr<SceNpTusVariable> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetFriendsVariable(transId=%d, slotId=%d, includeSelf=%d, sortType=%d, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, slotId, includeSelf, sortType, variableArray, variableArraySize, arrayNum, option);

	if (!variableArray)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || arrayNum <= 0 || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SELECTED_FRIENDS_NUM)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetFriendsVariableAsync(s32 transId, SceNpTusSlotId slotId, s32 includeSelf, s32 sortType, vm::ptr<SceNpTusVariable> variableArray, u64 variableArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetFriendsVariableAsync(transId=%d, slotId=%d, includeSelf=%d, sortType=%d, variableArray=*0x%x, variableArraySize=%d, arrayNum=%d, option=*0x%x)", transId, slotId, includeSelf, sortType, variableArray, variableArraySize, arrayNum, option);

	if (!variableArray)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || arrayNum <= 0 || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SELECTED_FRIENDS_NUM)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusAddAndGetVariable(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, s64 inVariable, vm::ptr<SceNpTusVariable> outVariable, u64 outVariableSize, vm::ptr<SceNpTusAddAndGetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusAddAndGetVariable(transId=%d, targetNpId=*0x%x, slotId=%d, inVariable=%d, outVariable=*0x%x, outVariableSize=%d, option=*0x%x)", transId, targetNpId, slotId, inVariable, outVariable, outVariableSize, option);

	if (!targetNpId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusAddAndGetVariableVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, s64 inVariable, vm::ptr<SceNpTusVariable> outVariable, u64 outVariableSize, vm::ptr<SceNpTusAddAndGetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusAddAndGetVariableVUser(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, inVariable=%d, outVariable=*0x%x, outVariableSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, inVariable, outVariable, outVariableSize, option);

	if (!targetVirtualUserId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusAddAndGetVariableAsync(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, s64 inVariable, vm::ptr<SceNpTusVariable> outVariable, u64 outVariableSize, vm::ptr<SceNpTusAddAndGetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusAddAndGetVariableAsync(transId=%d, targetNpId=*0x%x, slotId=%d, inVariable=%d, outVariable=*0x%x, outVariableSize=%d, option=*0x%x)", transId, targetNpId, slotId, inVariable, outVariable, outVariableSize, option);

	if (!targetNpId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusAddAndGetVariableVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, s64 inVariable, vm::ptr<SceNpTusVariable> outVariable, u64 outVariableSize, vm::ptr<SceNpTusAddAndGetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusAddAndGetVariableVUserAsync(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, inVariable=%d, outVariable=*0x%x, outVariableSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, inVariable, outVariable, outVariableSize, option);

	if (!targetVirtualUserId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusTryAndSetVariable(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, s32 opeType, s64 variable, vm::ptr<SceNpTusVariable> resultVariable, u64 resultVariableSize, vm::ptr<SceNpTusTryAndSetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusTryAndSetVariable(transId=%d, targetNpId=*0x%x, slotId=%d, opeType=%d, variable=%d, resultVariable=*0x%x, resultVariableSize=%d, option=*0x%x)", transId, targetNpId, slotId, opeType, variable, resultVariable, resultVariableSize, option);

	if (!targetNpId || !resultVariable)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusTryAndSetVariableVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, s32 opeType, s64 variable, vm::ptr<SceNpTusVariable> resultVariable, u64 resultVariableSize, vm::ptr<SceNpTusTryAndSetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusTryAndSetVariableVUser(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, opeType=%d, variable=%d, resultVariable=*0x%x, resultVariableSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, opeType, variable, resultVariable, resultVariableSize, option);

	if (!targetVirtualUserId || !resultVariable)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusTryAndSetVariableAsync(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, s32 opeType, s64 variable, vm::ptr<SceNpTusVariable> resultVariable, u64 resultVariableSize, vm::ptr<SceNpTusTryAndSetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusTryAndSetVariableAsync(transId=%d, targetNpId=*0x%x, slotId=%d, opeType=%d, variable=%d, resultVariable=*0x%x, resultVariableSize=%d, option=*0x%x)", transId, targetNpId, slotId, opeType, variable, resultVariable, resultVariableSize, option);

	if (!targetNpId || !resultVariable)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusTryAndSetVariableVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, s32 opeType, s64 variable, vm::ptr<SceNpTusVariable> resultVariable, u64 resultVariableSize, vm::ptr<SceNpTusTryAndSetVariableOptParam> option)
{
	sceNpTus.todo("sceNpTusTryAndSetVariableVUserAsync(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, opeType=%d, variable=%d, resultVariable=*0x%x, resultVariableSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, opeType, variable, resultVariable, resultVariableSize, option);

	if (!targetVirtualUserId || !resultVariable)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotVariable(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotVariable(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, arrayNum, option);

	if (!targetNpId || !slotIdArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotVariableVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotVariableVUser(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, arrayNum, option);

	if (!targetVirtualUserId || !slotIdArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotVariableAsync(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotVariableAsync(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, arrayNum, option);

	if (!targetNpId || !slotIdArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotVariableVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotVariableVUserAsync(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, arrayNum, option);

	if (!targetVirtualUserId || !slotIdArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusSetData(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, u64 totalSize, u64 sendSize, vm::cptr<void> data, vm::cptr<SceNpTusDataInfo> info, u64 infoStructSize, vm::ptr<SceNpTusSetDataOptParam> option)
{
	sceNpTus.todo("sceNpTusSetData(transId=%d, targetNpId=*0x%x, slotId=%d, totalSize=%d, sendSize=%d, data=*0x%x, info=*0x%x, infoStructSize=%d, option=*0x%x)", transId, targetNpId, slotId, totalSize, sendSize, data, info, infoStructSize, option);

	if (!targetNpId || !data || totalSize == 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusSetDataVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, u64 totalSize, u64 sendSize, vm::cptr<void> data, vm::cptr<SceNpTusDataInfo> info, u64 infoStructSize, vm::ptr<SceNpTusSetDataOptParam> option)
{
	sceNpTus.todo("sceNpTusSetDataAsync(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, totalSize=%d, sendSize=%d, data=*0x%x, info=*0x%x, infoStructSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, totalSize, sendSize, data, info, infoStructSize, option);

	if (!targetVirtualUserId || !data || totalSize == 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusSetDataAsync(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, u64 totalSize, u64 sendSize, vm::cptr<void> data, vm::cptr<SceNpTusDataInfo> info, u64 infoStructSize, vm::ptr<SceNpTusSetDataOptParam> option)
{
	sceNpTus.todo("sceNpTusSetDataAsync(transId=%d, targetNpId=*0x%x, slotId=%d, totalSize=%d, sendSize=%d, data=*0x%x, info=*0x%x, infoStructSize=%d, option=*0x%x)", transId, targetNpId, slotId, totalSize, sendSize, data, info, infoStructSize, option);

	if (!targetNpId || !data || totalSize == 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusSetDataVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, u64 totalSize, u64 sendSize, vm::cptr<void> data, vm::cptr<SceNpTusDataInfo> info, u64 infoStructSize, vm::ptr<SceNpTusSetDataOptParam> option)
{
	sceNpTus.todo("sceNpTusSetDataAsync(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, totalSize=%d, sendSize=%d, data=*0x%x, info=*0x%x, infoStructSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, totalSize, sendSize, data, info, infoStructSize, option);

	if (!targetVirtualUserId || !data || totalSize == 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusGetData(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> dataStatus, u64 dataStatusSize, vm::ptr<void> data, u64 recvSize, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetData(transId=%d, targetNpId=*0x%x, slotId=%d, dataStatus=*0x%x, dataStatusSize=%d, data=*0x%x, recvSize=%d, option=*0x%x)", transId, targetNpId, slotId, dataStatus, dataStatusSize, data, recvSize, option);

	if (!targetNpId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusGetDataVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> dataStatus, u64 dataStatusSize, vm::ptr<void> data, u64 recvSize, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetDataVUser(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, dataStatus=*0x%x, dataStatusSize=%d, data=*0x%x, recvSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, dataStatus, dataStatusSize, data, recvSize, option);

	if (!targetVirtualUserId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusGetDataAsync(s32 transId, vm::cptr<SceNpId> targetNpId, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> dataStatus, u64 dataStatusSize, vm::ptr<void> data, u64 recvSize, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetDataAsync(transId=%d, targetNpId=*0x%x, slotId=%d, dataStatus=*0x%x, dataStatusSize=%d, data=*0x%x, recvSize=%d, option=*0x%x)", transId, targetNpId, slotId, dataStatus, dataStatusSize, data, recvSize, option);

	if (!targetNpId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusGetDataVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> dataStatus, u64 dataStatusSize, vm::ptr<void> data, u64 recvSize, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetDataVUser(transId=%d, targetVirtualUserId=*0x%x, slotId=%d, dataStatus=*0x%x, dataStatusSize=%d, data=*0x%x, recvSize=%d, option=*0x%x)", transId, targetVirtualUserId, slotId, dataStatus, dataStatusSize, data, recvSize, option);

	if (!targetVirtualUserId)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotDataStatus(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotDataStatus(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, statusArray, statusArraySize, arrayNum, option);

	if (!targetNpId || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotDataStatusVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotDataStatusVUser(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, statusArray, statusArraySize, arrayNum, option);

	if (!targetVirtualUserId || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotDataStatusAsync(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotDataStatusAsync(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, statusArray, statusArraySize, arrayNum, option);

	if (!targetNpId || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiSlotDataStatusVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiSlotDataStatusVUser(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, statusArray, statusArraySize, arrayNum, option);

	if (!targetVirtualUserId || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserDataStatus(s32 transId, vm::cptr<SceNpId> targetNpIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserDataStatus(transId=%d, targetNpIdArray=*0x%x, slotId=%d, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpIdArray, slotId, statusArray, statusArraySize, arrayNum, option);

	if (!targetNpIdArray || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserDataStatusVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserDataStatusVUser(transId=%d, targetVirtualUserIdArray=*0x%x, slotId=%d, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserIdArray, slotId, statusArray, statusArraySize, arrayNum, option);

	if (!targetVirtualUserIdArray || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserDataStatusAsync(s32 transId, vm::cptr<SceNpId> targetNpIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserDataStatusAsync(transId=%d, targetNpIdArray=*0x%x, slotId=%d, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetNpIdArray, slotId, statusArray, statusArraySize, arrayNum, option);

	if (!targetNpIdArray || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetMultiUserDataStatusVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserIdArray, SceNpTusSlotId slotId, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetMultiUserDataStatusVUserAsync(transId=%d, targetVirtualUserIdArray=*0x%x, slotId=%d, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserIdArray, slotId, statusArray, statusArraySize, arrayNum, option);

	if (!targetVirtualUserIdArray || !statusArray || arrayNum <= 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_USER_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetFriendsDataStatus(s32 transId, SceNpTusSlotId slotId, s32 includeSelf, s32 sortType, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetFriendsDataStatus(transId=%d, slotId=%d, includeSelf=%d, sortType=%d, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, slotId, includeSelf, sortType, statusArray, statusArraySize, arrayNum, option);

	if (!statusArray)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || arrayNum < 0 || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SELECTED_FRIENDS_NUM)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusGetFriendsDataStatusAsync(s32 transId, SceNpTusSlotId slotId, s32 includeSelf, s32 sortType, vm::ptr<SceNpTusDataStatus> statusArray, u64 statusArraySize, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusGetFriendsDataStatusAsync(transId=%d, slotId=%d, includeSelf=%d, sortType=%d, statusArray=*0x%x, statusArraySize=%d, arrayNum=%d, option=*0x%x)", transId, slotId, includeSelf, sortType, statusArray, statusArraySize, arrayNum, option);

	if (!statusArray)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || arrayNum < 0 || slotId < 0)
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SELECTED_FRIENDS_NUM)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_NPID;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotData(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotData(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, arrayNum, option);

	if (!targetNpId || !slotIdArray || arrayNum < 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotDataVUser(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotDataVUser(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, arrayNum, option);

	if (!targetVirtualUserId || !slotIdArray || arrayNum < 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotDataAsync(s32 transId, vm::cptr<SceNpId> targetNpId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotDataAsync(transId=%d, targetNpId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetNpId, slotIdArray, arrayNum, option);

	if (!targetNpId || !slotIdArray || arrayNum < 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTusDeleteMultiSlotDataVUserAsync(s32 transId, vm::cptr<SceNpTusVirtualUserId> targetVirtualUserId, vm::cptr<SceNpTusSlotId> slotIdArray, s32 arrayNum, vm::ptr<void> option)
{
	sceNpTus.todo("sceNpTusDeleteMultiSlotDataVUserAsync(transId=%d, targetVirtualUserId=*0x%x, slotIdArray=*0x%x, arrayNum=%d, option=*0x%x)", transId, targetVirtualUserId, slotIdArray, arrayNum, option);

	if (!targetVirtualUserId || !slotIdArray || arrayNum < 0)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	if (option || !ValidSlotIds(slotIdArray))
		return SCE_NP_COMMUNITY_ERROR_INVALID_ARGUMENT;

	if (arrayNum > SCE_NP_TUS_MAX_SLOT_NUM_PER_TRANS)
		return SCE_NP_COMMUNITY_ERROR_TOO_MANY_SLOTID;

	return CELL_OK;
}

s32 sceNpTssGetData(s32 transId, SceNpTssSlotId slotId, vm::ptr<SceNpTssDataStatus> dataStatus, u64 dataStatusSize, vm::ptr<void> data, u64 recvSize, vm::ptr<SceNpTssGetDataOptParam> option)
{
	sceNpTus.todo("sceNpTssGetData(transId=%d, slotId=%d, dataStatus=*0x%x, dataStatusSize=%d, data=*0x%x, recvSize=%d, option=*0x%x)", transId, slotId, dataStatus, dataStatusSize, data, recvSize, option);

	if (!dataStatus)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTssGetDataAsync(s32 transId, SceNpTssSlotId slotId, vm::ptr<SceNpTssDataStatus> dataStatus, u64 dataStatusSize, vm::ptr<void> data, u64 recvSize, vm::ptr<SceNpTssGetDataOptParam> option)
{
	sceNpTus.todo("sceNpTssGetDataAsync(transId=%d, slotId=%d, dataStatus=*0x%x, dataStatusSize=%d, data=*0x%x, recvSize=%d, option=*0x%x)", transId, slotId, dataStatus, dataStatusSize, data, recvSize, option);

	if (!dataStatus)
		return SCE_NP_COMMUNITY_ERROR_INSUFFICIENT_ARGUMENT;

	return CELL_OK;
}

s32 sceNpTssGetDataNoLimit()
{
	UNIMPLEMENTED_FUNC(sceNpTus);
	return CELL_OK;
}

s32 sceNpTssGetDataNoLimitAsync()
{
	UNIMPLEMENTED_FUNC(sceNpTus);
	return CELL_OK;
}


DECLARE(ppu_module_manager::sceNpTus)("sceNpTus", []()
{
	REG_FUNC(sceNpTus, sceNpTusInit);
	REG_FUNC(sceNpTus, sceNpTusTerm);
	REG_FUNC(sceNpTus, sceNpTusCreateTitleCtx);
	REG_FUNC(sceNpTus, sceNpTusDestroyTitleCtx);
	REG_FUNC(sceNpTus, sceNpTusCreateTransactionCtx);
	REG_FUNC(sceNpTus, sceNpTusDestroyTransactionCtx);
	REG_FUNC(sceNpTus, sceNpTusSetTimeout);
	REG_FUNC(sceNpTus, sceNpTusAbortTransaction);
	REG_FUNC(sceNpTus, sceNpTusWaitAsync);
	REG_FUNC(sceNpTus, sceNpTusPollAsync);
	REG_FUNC(sceNpTus, sceNpTusSetMultiSlotVariable);
	REG_FUNC(sceNpTus, sceNpTusSetMultiSlotVariableVUser);
	REG_FUNC(sceNpTus, sceNpTusSetMultiSlotVariableAsync);
	REG_FUNC(sceNpTus, sceNpTusSetMultiSlotVariableVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotVariable);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotVariableVUser);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotVariableAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotVariableVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserVariable);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserVariableVUser);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserVariableAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserVariableVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusGetFriendsVariable);
	REG_FUNC(sceNpTus, sceNpTusGetFriendsVariableAsync);
	REG_FUNC(sceNpTus, sceNpTusAddAndGetVariable);
	REG_FUNC(sceNpTus, sceNpTusAddAndGetVariableVUser);
	REG_FUNC(sceNpTus, sceNpTusAddAndGetVariableAsync);
	REG_FUNC(sceNpTus, sceNpTusAddAndGetVariableVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusTryAndSetVariable);
	REG_FUNC(sceNpTus, sceNpTusTryAndSetVariableVUser);
	REG_FUNC(sceNpTus, sceNpTusTryAndSetVariableAsync);
	REG_FUNC(sceNpTus, sceNpTusTryAndSetVariableVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotVariable);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotVariableVUser);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotVariableAsync);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotVariableVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusSetData);
	REG_FUNC(sceNpTus, sceNpTusSetDataVUser);
	REG_FUNC(sceNpTus, sceNpTusSetDataAsync);
	REG_FUNC(sceNpTus, sceNpTusSetDataVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusGetData);
	REG_FUNC(sceNpTus, sceNpTusGetDataVUser);
	REG_FUNC(sceNpTus, sceNpTusGetDataAsync);
	REG_FUNC(sceNpTus, sceNpTusGetDataVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotDataStatus);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotDataStatusVUser);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotDataStatusAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiSlotDataStatusVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserDataStatus);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserDataStatusVUser);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserDataStatusAsync);
	REG_FUNC(sceNpTus, sceNpTusGetMultiUserDataStatusVUserAsync);
	REG_FUNC(sceNpTus, sceNpTusGetFriendsDataStatus);
	REG_FUNC(sceNpTus, sceNpTusGetFriendsDataStatusAsync);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotData);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotDataVUser);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotDataAsync);
	REG_FUNC(sceNpTus, sceNpTusDeleteMultiSlotDataVUserAsync);
	REG_FUNC(sceNpTus, sceNpTssGetData);
	REG_FUNC(sceNpTus, sceNpTssGetDataAsync);
	REG_FUNC(sceNpTus, sceNpTssGetDataNoLimit);
	REG_FUNC(sceNpTus, sceNpTssGetDataNoLimitAsync);
});
