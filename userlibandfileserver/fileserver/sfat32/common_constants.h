// Copyright (c) 1996-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// f32\sfat\common_constants.h
// Declarations of the constants etc. commom for FAT16/32 Fsy.
// 
//

/**
 @file
 @internalTechnology
*/

#ifndef COMMON_CONSTANTS_H
#define COMMON_CONSTANTS_H



#include <f32fsys.h>
#include <f32dbg.h>


IMPORT_C TUint32 DebugRegister();


//-- define this for having logs disregarding DebugRegister() settings
//#define FORCE_LOGS


#if defined(_DEBUG) || defined(_DEBUG_RELEASE)

#ifndef FORCE_LOGS
    #define __PRINT(t)          		{if (DebugRegister()&KFSYS) RDebug::Print(t);}
    #define __PRINT1(t,a)       		{if (DebugRegister()&KFSYS) RDebug::Print(t,a);}
    #define __PRINT2(t,a,b)     		{if (DebugRegister()&KFSYS) RDebug::Print(t,a,b);}
    #define __PRINT3(t,a,b,c)   		{if (DebugRegister()&KFSYS) RDebug::Print(t,a,b,c);}
    #define __PRINT4(t,a,b,c,d) 		{if (DebugRegister()&KFSYS) RDebug::Print(t,a,b,c,d);}
    #define __PRINT5(t,a,b,c,d,e) 		{if (DebugRegister()&KFSYS) RDebug::Print(t,a,b,c,d,e);}
    #define __PRINT6(t,a,b,c,d,e,f) 	{if (DebugRegister()&KFSYS) RDebug::Print(t,a,b,c,d,e,f);}
    #define __PRINT7(t,a,b,c,d,e,f,g)	{if (DebugRegister()&KFSYS) RDebug::Print(t,a,b,c,d,e,f,g);}
    #define __PRINT8BIT1(t,a)           {if (DebugRegister()&KFSYS){TFileName temp;temp.Copy(a);RDebug::Print(t,&temp);}}
    #define __PRINT1TEMP(t,a)           {if (DebugRegister()&KFSERV) {TBuf<KMaxFileName>temp(a);RDebug::Print(t,&temp);}}
#else //FORCE_LOGS
    #define __PRINT(t)          		{RDebug::Print(t);}
    #define __PRINT1(t,a)       		{RDebug::Print(t,a);}
    #define __PRINT2(t,a,b)     		{RDebug::Print(t,a,b);}
    #define __PRINT3(t,a,b,c)   		{RDebug::Print(t,a,b,c);}
    #define __PRINT4(t,a,b,c,d) 		{RDebug::Print(t,a,b,c,d);}
    #define __PRINT5(t,a,b,c,d,e) 		{RDebug::Print(t,a,b,c,d,e);}
    #define __PRINT6(t,a,b,c,d,e,f) 	{RDebug::Print(t,a,b,c,d,e,f);}
    #define __PRINT7(t,a,b,c,d,e,f,g)	{RDebug::Print(t,a,b,c,d,e,f,g);}
    #define __PRINT8BIT1(t,a)           {{TFileName temp;temp.Copy(a);RDebug::Print(t,&temp);}}
    #define __PRINT1TEMP(t,a)           {{TBuf<KMaxFileName>temp(a);RDebug::Print(t,&temp);}}
#endif//FORCE_LOGS

#define DBG_STATEMENT(text) text

#else

#define __PRINT(t)
#define __PRINT1(t,a)
#define __PRINT2(t,a,b)
#define __PRINT3(t,a,b,c)
#define __PRINT4(t,a,b,c,d)
#define __PRINT5(t,a,b,c,d,e)
#define __PRINT6(t,a,b,c,d,e,f)
#define __PRINT7(t,a,b,c,d,e,f,g)
#define __PRINT8BIT1(t,a)
#define __PRINT1TEMP(t,a)

#define DBG_STATEMENT(text)

#endif

//-----------------------------------------------------------------------------

//-- define this macro in order to enable the DEMAND PAGING DIRECTORY CACHE.
#define USE_DP_DIR_CACHE

//-----------------------------------------------------------------------------

typedef TUint32 TLinAddr;
typedef TUint32 TFat32Entry;
typedef TUint16 TFat16Entry;

const TUint16 K1KiloByteLog2 = 10;
const TUint32 K1KiloByte = 1<<10; 
const TUint32 K1MegaByte = 1<<20; 

const TUint32 K1uSec = 1;               ///< 1 misrosecond in TTimeIntervalMicroSeconds32
const TUint32 K1mSec = 1000;            ///< 1 millisecond in TTimeIntervalMicroSeconds32
const TUint32 K1Sec  = 1000*K1mSec;     ///< 1 second in TTimeIntervalMicroSeconds32

_LIT8(KLit8ReplacementForUnconvertibleUnicodeCharacters, "_");
_LIT8(KFileSystemName12,"FAT12   ");    ///< Name in BPB given to a Fat12 volume
_LIT8(KFileSystemName16,"FAT16   ");    ///< Name in BPB given to a Fat16 volume
_LIT8(KFileSystemName32,"FAT32   ");    ///< Name in BPB given to a Fat32 volume
_LIT8(KDefaultVendorID, "EPOC");        ///< Vendor Name for BPB for any volume formated using a Symbian OS device

const TInt KMaxFatFileNameExt=3;		///< Maximum Fat file system file/directory name extension length
const TInt KNumberOfFatsInternal=1;     ///< Number of FATs for an internal drive
const TInt KNumberOfFatsExternal=2;     ///< Number of FATs for an internal drive
const TInt KMaxFatFileName=12;          ///< Maximum Fat file system file/directory name length
const TInt KMaxFatFileNameWithoutExt=8; ///< Maximum Fat file system file/directory name length without extension
const TInt KMaxDuplicateShortName=0xFFFF;
const TInt KMaxVFatEntryName=13;        ///< Maximum entries in a VFat name
const TInt KMaxFAT16Entries=0xFFF0;	    ///< Maximum number of clusters in a Fat16 Fat table, 65520
const TInt KMaxFAT12Entries=0xFF0;	    ///< Maximum number of clusters in a Fat12 Fat table, 4080
const TUint8 KBootSectorMediaDescriptor=0xF8;   ///< Media descriptor for a Fat volume, Generic disk
const TUint8 KEntryErasedMarker=0xE5;           ///< Erased entry marker for a directory entry

const TUint KDefSectorSzLog2=9;                         ///< Log2 of the default sector size for FAT
const TUint KDefaultSectorSize = 1 << KDefSectorSzLog2; ///< Default sector size for FAT, 512 bytes


const TInt EOF_32Bit =0x0fffffff;   ///< End of cluster chain value for Fat32
const TInt EOF_16Bit =0xffff;       ///< End of cluster chain value for Fat16
const TInt EOF_12Bit =0xfff;        ///< End of cluster chain value for Fat12
const TInt KBad_32Bit=0x0ffffff7;   ///< Bad cluster value for Fat32
const TInt KBad_16Bit=0xfff7;       ///< Bad cluster value for Fat16
const TInt KBad_12Bit=0xff7;        ///< bad cluster value for Fat12

const TUint   KSpareCluster = 0;          ///< FAT entry value for the spare cluster
const TUint32 KFatFirstSearchCluster = 2; ///< FAT usable clusters start from 2; FAT[0] and FAT[1] are reserved

const TUint   KFat16EntrySzLog2 = 1;      ///< Log2(sizeof(TFat16Entry)); FAT16 entry is 2 bytes
const TUint   KFat32EntrySzLog2 = 2;      ///< Log2(sizeof(TFat32Entry)); FAT32 entry is 4 bytes



//-----------------------------------------------------------------------------

/**
Internal fault codes for FAT fsy
*/
enum TFault
	{
	EVFatNoLongName,                // 0
	EFatBadParameter,               // 1
	EFatBadLocalDrive,              // 2
	EFatBadBootSectorParameter,     // 3
	EFatBadDirEntryParameter,       // 4
	EFatBadStdFormatName,           // 5
	EFatBadDosFormatName,           // 6
	EFatCorrupt,                    // 7
	EFatChkDskIllegalClusterNumber, // 8
	EFatChkDskClusterAlreadyInUse,  // 9
	EFatChkDskBadCluster,           // 10
	EFatChkDskInvalidEntrySize,     // 11
	EFatFilePosBeyondEnd,			// 12
	EFatFileSeekIndexTooSmall,      // 13
	EFatFileSeekIndexTooSmall2,     // 14
	ELruCacheBadGranularity,        // 15
	EFatRawReadTooBig,              // 16
	EFatReadUidFailed,              // 17
	ELruCacheFlushNotSupported,     // 18
	EReadFileSectionFailed,         // 19
	EBadReplacementForUnconvertibleUnicodeCharacters, // 20

    EFatRAMDriveSizeInvalid,        // 21
	EFatRAMDriveFreeInvalid,        // 22
    ECheckFatIndexZero,             // 23

    EFatCache_BadGranularity,       // 24
    EFatCache_DiscardingDirtyData,  // 25
    EFatCache_NotImplemented,       // 26
    EFatCache_BadFatType,           // 27

    EFatTable_InvalidIndex,         // 28

	};

//-----------------------------------------------------------------------------


#if defined(_DEBUG)

/** debug IO control functions */
enum TControlIO
{
    ECriticalWriteFailOn,   ///< 0
    ECriticalWriteFailOff,  ///< 1
    ERuggedFSysOn,          ///< 2
    ERuggedFSysOff,         ///< 3
    EIsRuggedFSys,          ///< 4
    ENCNotifierHang,        ///< 5
    ENCNotifierClear,       ///< 6
    ECNotifier,             ///< 7
    ECNotifierCancel,       ///< 8
	ENCNotifierRepeat,      ///< 9

	ELocalTimeForRemovableMediaOn,  ///< 10
	ELocalTimeForRemovableMediaOff, ///< 11
	ELocalTimeUsedOnRemovableMedia, ///< 12
	ECreationTime,                  ///< 13

	EDisableFATDirCache,			///<14
	EDumpFATDirCache,				///<15
	EFATDirCacheInfo,				///<16
	
    EExtCustom=KMaxTInt/2
    };


const TUid KSID_Test1={0x10210EB3}; ///< SID of the test that will define and set test property to control volume mounting

//-- bit flags passed by test property value. Used to control some volume mounting features.
const TUint32 KMntDisable_FsInfo       = 0x00000001; //-- mask for disabling/enabling FSInfo information
const TUint32 KMntDisable_FatBkGndScan = 0x00000002; //-- mask for disabling/enabling FAT background scanner

#endif //#if defined(_DEBUG)




#endif //COMMON_CONSTANTS_H


















