// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This file defines the interface provided by the driver to the user. 
// It will be included both in the application (user) and the driver (kernel). 
// This file typically defines the RBusLogicalChannel derived class that will 
// inturn provide the driver API to the user application. 
// ifndef __EXPIO_H__ will resolve the multiple inclusion of this header 
// file in different source files. If the file is already included, then the 
// following switch will not re-include the file.
// 
//

#ifndef __EXPIO_H__
#define __EXPIO_H__

// include files
// 
// e32ver.h (for KE32BuildVersionNumber), e32cmn.h and e32std.h are already
// included in d32comm.h and hence not repeating here.
//
#include <d32comm.h> 

// Literal string descriptor constants for driver name. These descriptors 
// are used by the driver to associate a name for registering to the 
// Symbian OS. LDD will have a name to associate with.
//
_LIT(KDriverName, "d_expio");

/**
 User interface for tutorial driver
 
 RExDriverChannel class is derived from the RBusLogicalChannel and provides 
 the interface for user. User application accesses the driver functionality
 using only these API.
 */
class RExDriverChannel:public RBusLogicalChannel
	{
public:	
	// TVer is an enumeration for the version related information. Driver will 
	// need to set and validate version related information while installing.
	// Version numbers are validated to check if this version of driver as 
	// expected by the client/user application
	//
	enum TVer
		{
		EUartMajorVersionNumber=1,						// Major number for driver
		EUartMinorVersionNumber=0,						// Minor number for device
		EUartBuildVersionNumber=KE32BuildVersionNumber	// Build version number for driver
		};
	// TControl is the enumeration for control and synchronous messages 
	// supported by the driver. User application can request for any of
	// the following control messages to the driver through DoContro() 
	// API provided by the RBusLogicalChannel class.
	//
	enum TControl							// Synchronous control messages used with DoContro()					
		{
		EControlCaps,						// Get the channel capabilities on uart
		EControlSetConfig,					// Configure the device (uart)
		EControlTransmitData,				// Transmit data over the device (uart)	
		EControlReceiveData,				// Receive the data from the device (uart)
		ENumRequests,						// Number of synchronous control requests
        EAllRequests = (1<<ENumRequests)-1	// Total number of control synchronous requests
		};
public:
	// VersionRequired() will provide the version of the driver. This is made inline
	// function to initialize the TVersion object with driver's Major,Minor and Build
	// version numbers. This is later used to validate the driver version.
	//
	inline static TVersion VersionRequired();		
	
	// This header file is included both in user application and driver (in kernel mode).
	// The following API are provided only in user space and are not required in kernel mode.
	// Therefore, they are defined under __KERNEL_MODE__ conditional compilation switch.
	// These functions are wrappers to the RBusLogicalChannel API and are inline.
	//
	inline TInt Open();								// Open the channel to the driver
	inline TInt Caps(TDes8& aCaps);					// Get the channel capabilities
	inline TInt SetConfig(const TDesC8& aConfig);	// Configure device (UART)	
	inline TInt TransmitData(const TDesC8& aData);	// Send data on device (UART)	
	inline TInt ReceiveData(TDes8& aData);			// Receive data on device (UART)	
	};

// All inline functions implementation is provided in a seperate inline file. This file
// is included here to add the inline implementations. Note:these inline functions 
// implementaion is also available only in user space.
// 
#include "expio.inl"

#endif  // __EXPIO_H__

//
// End of expio.h
