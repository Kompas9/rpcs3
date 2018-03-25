#pragma once

struct CellPngEncAncillaryChunk
{
	//CellPngEncChunkType chunkType;
	vm::ptr<void> chunkData;
};

struct CellPngEncAttr
{
	u64 memSize;
	u8 cmdQueueDepth;
	u32 versionUpper;
	u32 versionLower;
};

struct CellPngEncExParam
{
	s32 index;
	s64 value;
};

struct CellPngEncConfig
{
	u32 maxWidth;
	u32 maxHeight;
	u32 maxBitDepth;
	b8 enableSpu;
	u32 addMemSize;
	vm::ptr<CellPngEncExParam> exParamList;
	u32 exParamNum;
};

struct CellPngEncEncodeParam
{
	b8 enableSpu;
	//CellPngEncColorSpace encodeColorSpace;
	//CellPngEncCompressionLevel compressionLevel;
	u32 filterType;
	vm::ptr<CellPngEncAncillaryChunk> ancillaryChunkList;
	u32 ancillaryChunkNum;
};

struct CellPngEncOutputParam
{
	//CellPngEncLocation location;
	vm::cptr<u8> streamName;
	vm::ptr<void> streamAddr;
	u64 limitSize;
};

struct CellPngEncPicture
{
	u32 width;
	u32 height;
	u32 pitchWidth;
	//CellPngEncColorSpace colorSpace;
	u32 bitDepth;
	b8 packedPixel;
	void *pictureAddr;
	u64 userData;
};

struct CellPngEncResource
{
	vm::ptr<void> memAddr;
	u64 memSize;
	s32 ppuThreadPriority;
	s32 spuThreadPriority;
};

struct CellPngEncResourceEx
{
	vm::ptr<void> memAddr;
	u64 memSize;
	s32 ppuThreadPriority;
	//CellSpurs *spurs;
	vm::ptr<u8[8]> priority;
};

struct CellPngEncStreamInfo
{
	s32 state;
	//CellPngEncLocation location;
	vm::cptr<u8> streamFileName;
	vm::ptr<void> streamAddr;
	u64 limitSize;
	u64 streamSize;
	u32 processedLine;
	u64 userData;
};
