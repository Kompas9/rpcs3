#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/Cell/PPUModule.h"

#include "sceNp.h"
#include "sceNpClans.h"

logs::channel sceNpClans("sceNpClans");

s32 sceNpClansInit(vm::cptr<SceNpCommunicationId> commId, vm::cptr<SceNpCommunicationPassphrase> passphrase, vm::ptr<void> pool, u64 poolSize, u32 flags)
{
	sceNpClans.warning("sceNpClansInit(commId=*0x%x, passphrase=*0x%x, pool=*0x%x, poolSize=*0x%x, flags=0x%x)", commId, passphrase, pool, poolSize, flags);

	if (flags != 0)
	{
		return SCE_NP_CLANS_ERROR_NOT_SUPPORTED;
	}

	return CELL_OK;
}

s32 sceNpClansTerm()
{
	sceNpClans.warning("sceNpClansTerm()");

	return CELL_OK;
}

s32 sceNpClansCreateRequest(SceNpClansRequestHandle handle, u64 flags)
{
	sceNpClans.todo("sceNpClansCreateRequest(handle=*0x%x, flags=0x%llx)", handle, flags);

	if (flags != 0)
	{
		return SCE_NP_CLANS_ERROR_NOT_SUPPORTED;
	}

	return CELL_OK;
}

s32 sceNpClansDestroyRequest(SceNpClansRequestHandle handle)
{
	sceNpClans.todo("sceNpClansDestroyRequest(handle=*0x%x)", handle);
	return CELL_OK;
}

s32 sceNpClansAbortRequest(SceNpClansRequestHandle handle)
{
	sceNpClans.todo("sceNpClansAbortRequest(handle=*0x%x)", handle);
	return CELL_OK;
}

s32 sceNpClansCreateClan(SceNpClansRequestHandle handle, vm::cptr<char> name, vm::cptr<char> tag, vm::ptr<SceNpClanId> clanId)
{
	sceNpClans.todo("sceNpClansCreateClan(handle=*0x%x, name=%s, tag=%s, clanId=*0x%x)", handle, name, tag, clanId);

	if (!name || !tag || !clanId)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (name.size() > SCE_NP_CLANS_CLAN_NAME_MAX_LENGTH || tag.size() > SCE_NP_CLANS_CLAN_TAG_MAX_LENGTH)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansDisbandClan(SceNpClansRequestHandle handle, SceNpClanId clanId)
{
	sceNpClans.todo("sceNpClansDisbandClan(handle=*0x%x, clanId=%d)", handle, clanId);
	return CELL_OK;
}

s32 sceNpClansGetClanList(SceNpClansRequestHandle handle, vm::cptr<SceNpClansPagingRequest> paging, vm::ptr<SceNpClansEntry> clanList, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansGetClanList(handle=*0x%x, paging=*0x%x, clanList=*0x%x, pageResult=*0x%x)", handle, paging, clanList, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansGetClanListByNpId(SceNpClansRequestHandle handle, vm::cptr<SceNpClansPagingRequest> paging, vm::cptr<SceNpId> npid, vm::ptr<SceNpClansEntry> clanList, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansGetClanListByNpId(handle=*0x%x, paging=*0x%x, npid=*0x%x, clanList=*0x%x, pageResult=*0x%x)", handle, paging, npid, clanList, pageResult);

	if (!npid || !pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansSearchByProfile(SceNpClansRequestHandle handle, vm::cptr<SceNpClansPagingRequest> paging, vm::cptr<SceNpClansSearchableProfile> search, vm::ptr<SceNpClansClanBasicInfo> results, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansGetClanListByNpId(handle=*0x%x, paging=*0x%x, search=*0x%x, results=*0x%x, pageResult=*0x%x)", handle, paging, search, results, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansSearchByName(SceNpClansRequestHandle handle, vm::cptr<SceNpClansPagingRequest> paging, vm::cptr<SceNpClansSearchableName> search, vm::ptr<SceNpClansClanBasicInfo> results, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansSearchByName(handle=*0x%x, paging=*0x%x, search=*0x%x, results=*0x%x, pageResult=*0x%x)", handle, paging, search, results, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansGetClanInfo(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::ptr<SceNpClansClanInfo> info)
{
	sceNpClans.todo("sceNpClansGetClanInfo(handle=*0x%x, clanId=%d, info=*0x%x)", handle, clanId, info);

	if (!info)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansUpdateClanInfo(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansUpdatableClanInfo> info)
{
	sceNpClans.todo("sceNpClansUpdateClanInfo(handle=*0x%x, clanId=%d, info=*0x%x)", handle, clanId, info);

	if (!info)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansGetMemberList(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansPagingRequest> paging, SceNpClansMemberStatus status, vm::ptr<SceNpClansMemberEntry> memList, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansGetMemberList(handle=*0x%x, clanId=%d, paging=*0x%x, status=%d, memList=*0x%x, pageResult=*0x%x)", handle, clanId, paging, status, memList, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansGetMemberInfo(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpId> npid, vm::ptr<SceNpClansMemberEntry> memInfo)
{
	sceNpClans.todo("sceNpClansGetMemberInfo(handle=*0x%x, clanId=%d, npid=*0x%x, memInfo=*0x%x)", handle, clanId, npid, memInfo);

	if (!npid || !memInfo)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansUpdateMemberInfo(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansUpdatableMemberInfo> info)
{
	sceNpClans.todo("sceNpClansUpdateMemberInfo(handle=*0x%x, clanId=%d, info=*0x%x)", handle, clanId, info);

	if (!info)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansChangeMemberRole(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpId> npid, SceNpClansRole role)
{
	sceNpClans.todo("sceNpClansChangeMemberRole(handle=*0x%x, clanId=%d, npid=*0x%x, role=%d)", handle, clanId, npid, role);

	if (!npid)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansGetAutoAcceptStatus(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::ptr<b8> enable)
{
	sceNpClans.todo("sceNpClansGetAutoAcceptStatus(handle=*0x%x, clanId=%d, enable=*0x%x)", handle, clanId, enable);

	if (!enable)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansUpdateAutoAcceptStatus(SceNpClansRequestHandle handle, SceNpClanId clanId, b8 enable)
{
	sceNpClans.todo("sceNpClansUpdateAutoAcceptStatus(handle=*0x%x, clanId=%d, enable=%d)", handle, clanId, enable);
	return CELL_OK;
}

s32 sceNpClansJoinClan(SceNpClansRequestHandle handle, SceNpClanId clanId)
{
	sceNpClans.todo("sceNpClansJoinClan(handle=*0x%x, clanId=%d)", handle, clanId);
	return CELL_OK;
}

s32 sceNpClansLeaveClan(SceNpClansRequestHandle handle, SceNpClanId clanId)
{
	sceNpClans.todo("sceNpClansLeaveClan(handle=*0x%x, clanId=%d)", handle, clanId);
	return CELL_OK;
}

s32 sceNpClansKickMember(vm::ptr<SceNpClansRequestHandle> handle, SceNpClanId clanId, vm::cptr<SceNpId> npid, vm::cptr<SceNpClansMessage> message)
{
	sceNpClans.todo("sceNpClansKickMember(handle=*0x%x, clanId=%d, npid=*0x%x, message=*0x%x)", handle, clanId, npid, message);

	if (!npid)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansSendInvitation(vm::ptr<SceNpClansRequestHandle> handle, SceNpClanId clanId, vm::cptr<SceNpId> npid, vm::cptr<SceNpClansMessage> message)
{
	sceNpClans.todo("sceNpClansSendInvitation(handle=*0x%x, clanId=%d, npid=*0x%x, message=*0x%x)", handle, clanId, npid, message);

	if (!npid)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansCancelInvitation(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpId> npid)
{
	sceNpClans.todo("sceNpClansCancelInvitation(handle=*0x%x, clanId=%d, npid=*0x%x)", handle, clanId, npid);

	if (!npid)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansSendInvitationResponse(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansMessage> message, b8 accept)
{
	sceNpClans.todo("sceNpClansSendInvitationResponse(handle=*0x%x, clanId=%d, message=*0x%x, accept=%d)", handle, clanId, message, accept);
	return CELL_OK;
}

s32 sceNpClansSendMembershipRequest(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansMessage> message)
{
	sceNpClans.todo("sceNpClansSendMembershipRequest(handle=*0x%x, clanId=%d, message=*0x%x)", handle, clanId, message);
	return CELL_OK;
}

s32 sceNpClansCancelMembershipRequest(SceNpClansRequestHandle handle, SceNpClanId clanId)
{
	sceNpClans.todo("sceNpClansCancelMembershipRequest(handle=*0x%x, clanId=%d)", handle, clanId);
	return CELL_OK;
}

s32 sceNpClansSendMembershipResponse(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpId> npid, vm::cptr<SceNpClansMessage> message, b8 allow)
{
	sceNpClans.todo("sceNpClansSendMembershipResponse(handle=*0x%x, clanId=%d, npid=*0x%x, message=*0x%x, allow=%d)", handle, clanId, npid, message, allow);

	if (!npid)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansGetBlacklist(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansPagingRequest> paging, vm::ptr<SceNpClansBlacklistEntry> bl, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansGetBlacklist(handle=*0x%x, clanId=%d, paging=*0x%x, bl=*0x%x, pageResult=*0x%x)", handle, clanId, paging, bl, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansAddBlacklistEntry(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpId> npid)
{
	sceNpClans.todo("sceNpClansAddBlacklistEntry(handle=*0x%x, clanId=%d, npid=*0x%x)", handle, clanId, npid);

	if (!npid)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansRemoveBlacklistEntry(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpId> npid)
{
	sceNpClans.todo("sceNpClansRemoveBlacklistEntry(handle=*0x%x, clanId=%d, npid=*0x%x)", handle, clanId, npid);

	if (!npid)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansRetrieveAnnouncements(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansPagingRequest> paging, vm::ptr<SceNpClansMessageEntry> mList, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansRetrieveAnnouncements(handle=*0x%x, clanId=%d, paging=*0x%x, mList=*0x%x, pageResult=*0x%x)", handle, clanId, paging, mList, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansPostAnnouncement(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansMessage> message, vm::cptr<SceNpClansMessageData> data, u32 duration, vm::ptr<SceNpClansMessageId> mId)
{
	sceNpClans.todo("sceNpClansPostAnnouncement(handle=*0x%x, clanId=%d, message=*0x%x, data=*0x%x, duration=%d, mId=*0x%x)", handle, clanId, message, data, duration, mId);

	if (!message || !mId || duration == 0)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansRemoveAnnouncement(SceNpClansRequestHandle handle, SceNpClanId clanId, SceNpClansMessageId mId)
{
	sceNpClans.todo("sceNpClansRemoveAnnouncement(handle=*0x%x, clanId=%d, mId=%d)", handle, clanId, mId);
	return CELL_OK;
}

s32 sceNpClansPostChallenge(vm::ptr<SceNpClansRequestHandle> handle, SceNpClanId clanId, SceNpClanId targetClan, vm::cptr<SceNpClansMessage> message, vm::cptr<SceNpClansMessageData> data, u32 duration, vm::ptr<SceNpClansMessageId> mId)
{
	sceNpClans.todo("sceNpClansPostChallenge(handle=*0x%x, clanId=%d, targetClan=%d, message=*0x%x, data=*0x%x, duration=%d, mId=*0x%x)", handle, clanId, targetClan, message, data, duration, mId);

	if (!message || !mId || duration == 0)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	return CELL_OK;
}

s32 sceNpClansRetrievePostedChallenges(SceNpClansRequestHandle handle, SceNpClanId clanId, SceNpClanId targetClan, vm::cptr<SceNpClansPagingRequest> paging, vm::ptr<SceNpClansMessageEntry> mList, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansRetrievePostedChallenges(handle=*0x%x, clanId=%d, targetClan=%d, paging=*0x%x, mList=*0x%x, pageResult=*0x%x)", handle, clanId, targetClan, paging, mList, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansRemovePostedChallenge(SceNpClansRequestHandle handle, SceNpClanId clanId, SceNpClanId targetClan, SceNpClansMessageId mId)
{
	sceNpClans.todo("sceNpClansRemovePostedChallenge(handle=*0x%x, clanId=%d, targetClan=%d, mId=%d)", handle, clanId, targetClan, mId);
	return CELL_OK;
}

s32 sceNpClansRetrieveChallenges(SceNpClansRequestHandle handle, SceNpClanId clanId, vm::cptr<SceNpClansPagingRequest> paging, vm::ptr<SceNpClansMessageEntry> mList, vm::ptr<SceNpClansPagingResult> pageResult)
{
	sceNpClans.todo("sceNpClansRetrieveChallenges(handle=*0x%x, clanId=%d, paging=*0x%x, mList=*0x%x, pageResult=*0x%x)", handle, clanId, paging, mList, pageResult);

	if (!pageResult)
		return SCE_NP_CLANS_ERROR_INVALID_ARGUMENT;

	if (paging->startPos > SCE_NP_CLANS_PAGING_REQUEST_START_POSITION_MAX || paging->max > SCE_NP_CLANS_PAGING_REQUEST_PAGE_MAX)
		return SCE_NP_CLANS_ERROR_EXCEEDS_MAX;

	return CELL_OK;
}

s32 sceNpClansRemoveChallenge(SceNpClansRequestHandle handle, SceNpClanId clanId, SceNpClansMessageId mId)
{
	sceNpClans.todo("sceNpClansRemoveChallenge(handle=*0x%x, clanId=%d, mId=%d)", handle, clanId, mId);
	return CELL_OK;
}

DECLARE(ppu_module_manager::sceNpClans)("sceNpClans", []()
{
	REG_FUNC(sceNpClans, sceNpClansInit);
	REG_FUNC(sceNpClans, sceNpClansTerm);
	REG_FUNC(sceNpClans, sceNpClansCreateRequest);
	REG_FUNC(sceNpClans, sceNpClansDestroyRequest);
	REG_FUNC(sceNpClans, sceNpClansAbortRequest);
	REG_FUNC(sceNpClans, sceNpClansCreateClan);
	REG_FUNC(sceNpClans, sceNpClansDisbandClan);
	REG_FUNC(sceNpClans, sceNpClansGetClanList);
	REG_FUNC(sceNpClans, sceNpClansGetClanListByNpId);
	REG_FUNC(sceNpClans, sceNpClansSearchByProfile);
	REG_FUNC(sceNpClans, sceNpClansSearchByName);
	REG_FUNC(sceNpClans, sceNpClansGetClanInfo);
	REG_FUNC(sceNpClans, sceNpClansUpdateClanInfo);
	REG_FUNC(sceNpClans, sceNpClansGetMemberList);
	REG_FUNC(sceNpClans, sceNpClansGetMemberInfo);
	REG_FUNC(sceNpClans, sceNpClansUpdateMemberInfo);
	REG_FUNC(sceNpClans, sceNpClansChangeMemberRole);
	REG_FUNC(sceNpClans, sceNpClansGetAutoAcceptStatus);
	REG_FUNC(sceNpClans, sceNpClansUpdateAutoAcceptStatus);
	REG_FUNC(sceNpClans, sceNpClansJoinClan);
	REG_FUNC(sceNpClans, sceNpClansLeaveClan);
	REG_FUNC(sceNpClans, sceNpClansKickMember);
	REG_FUNC(sceNpClans, sceNpClansSendInvitation);
	REG_FUNC(sceNpClans, sceNpClansCancelInvitation);
	REG_FUNC(sceNpClans, sceNpClansSendInvitationResponse);
	REG_FUNC(sceNpClans, sceNpClansSendMembershipRequest);
	REG_FUNC(sceNpClans, sceNpClansCancelMembershipRequest);
	REG_FUNC(sceNpClans, sceNpClansSendMembershipResponse);
	REG_FUNC(sceNpClans, sceNpClansGetBlacklist);
	REG_FUNC(sceNpClans, sceNpClansAddBlacklistEntry);
	REG_FUNC(sceNpClans, sceNpClansRemoveBlacklistEntry);
	REG_FUNC(sceNpClans, sceNpClansRetrieveAnnouncements);
	REG_FUNC(sceNpClans, sceNpClansPostAnnouncement);
	REG_FUNC(sceNpClans, sceNpClansRemoveAnnouncement);
	REG_FUNC(sceNpClans, sceNpClansPostChallenge);
	REG_FUNC(sceNpClans, sceNpClansRetrievePostedChallenges);
	REG_FUNC(sceNpClans, sceNpClansRemovePostedChallenge);
	REG_FUNC(sceNpClans, sceNpClansRetrieveChallenges);
	REG_FUNC(sceNpClans, sceNpClansRemoveChallenge);
});
