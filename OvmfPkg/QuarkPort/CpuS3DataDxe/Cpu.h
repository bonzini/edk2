/** @file

  Include file for CPU DXE Module

  Copyright (C) 2015, Red Hat, Inc.
  Copyright (c) 2013-2015 Intel Corporation.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

  * Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in
  the documentation and/or other materials provided with the
  distribution.
  * Neither the name of Intel Corporation nor the names of its
  contributors may be used to endorse or promote products derived
  from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  Module Name:  Cpu.h

**/

#ifndef _CPU_DXE_H_
#define _CPU_DXE_H_

#include "MpCommon.h"

extern EFI_PHYSICAL_ADDRESS        mStartupVector;

extern ACPI_CPU_DATA               *mAcpiCpuData;

/**
  Wakes up APs for the first time to count their number and collect BIST data.

  This function wakes up APs for the first time to count their number and
  collect BIST data.

**/
VOID
WakeupAPAndCollectBist (
  VOID
  );

/**
  Prepare ACPI NVS memory below 4G memory for use of S3 resume.
  
  This function allocates ACPI NVS memory below 4G memory for use of S3 resume,
  and saves data into the memory region.

  @param  Context   The Context save the info.
  
**/
VOID
SaveCpuS3Data (
  VOID    *Context
  );

/**
  Label of start of AP machine check handler.

  This is just a label of start of AP machine check handler.

**/
VOID
EFIAPI
ApMachineCheckHandler (
  VOID
  );

/**
  Label of end of AP machine check handler.

  This is just a label of end of AP machine check handler.

**/
VOID
EFIAPI
ApMachineCheckHandlerEnd (
  VOID
  );

#endif