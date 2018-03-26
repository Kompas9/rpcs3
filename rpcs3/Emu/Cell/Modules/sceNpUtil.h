#pragma once

enum
{
	SCE_NP_UTIL_BANDWIDTH_TEST_STATUS_NONE,
	SCE_NP_UTIL_BANDWIDTH_TEST_STATUS_RUNNING,
	SCE_NP_UTIL_BANDWIDTH_TEST_STATUS_FINISHED,
};

struct SceNpUtilBandwidthTestResult
{
	f64 upload_bps;
	f64 download_bps;
	s32 result;
};
