/*
 * Copyright (c) 2007, Michael Feathers, James Grenning and Bas Vodde
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "CppUTest/TestHarness.h"
#undef malloc
#undef free
#undef calloc
#undef realloc

#include "CppUTest/PlatformSpecificFunctions.h"

int PlatformSpecificSetJmp(void (*function) (void* data), void* data)
{
    (void) data;
    (void) function;
    /* To be implemented */
    return 0;
}

void PlatformSpecificLongJmp()
{
    /* To be implemented */
}

void PlatformSpecificRestoreJumpBuffer()
{
    /* To be implemented */
}

void GccNoStdCPlatformSpecificRunTestInASeperateProcess(UtestShell*, TestPlugin*, TestResult*)
{
    /* To be implemented */
}
void (*PlatformSpecificRunTestInASeperateProcess)(UtestShell* shell, TestPlugin* plugin, TestResult* result) =
        GccNoStdCPlatformSpecificRunTestInASeperateProcess;

long (*GetPlatformSpecificTimeInMillis)() = NULL;

TestOutput::WorkingEnvironment PlatformSpecificGetWorkingEnvironment()
{
    return TestOutput::eclipse;
}

const char* (*GetPlatformSpecificTimeString)() = NULL;

int PlatformSpecificVSNprintf(char *str, size_t size, const char* format, va_list args)
{
    /* To be implemented */
    (void) size;
    (void) args;
    (void) format;
    (void) args;
    (void) str;
    return 0;
}

PlatformSpecificFile PlatformSpecificFOpen(const char* filename, const char* flag)
{
    /* To be implemented */
    (void) filename;
    (void) flag;
    return NULL;
}


void PlatformSpecificFPuts(const char* str, PlatformSpecificFile file)
{
    /* To be implemented */
    (void) str;
    (void) file;
}

void PlatformSpecificFClose(PlatformSpecificFile file)
{
    /* To be implemented */
    (void) file;
}

void PlatformSpecificFlush()
{
    /* To be implemented */
}

int PlatformSpecificPutchar(int c)
{
    /* To be implemented */
    (void) c;
    return 0;
}

void* PlatformSpecificMalloc(size_t size)
{
    /* To be implemented */
    (void) size;
    return NULL;
}

void* PlatformSpecificRealloc (void* memory, size_t size)
{
    /* To be implemented */
    (void) memory;
    (void) size;
    return NULL;
}

void PlatformSpecificFree(void* memory)
{
    /* To be implemented */
    (void) memory;
}

void* PlatformSpecificMemCpy(void* s1, const void* s2, size_t size)
{
    /* To be implemented */
    (void) size;
    (void) s1;
    (void) s2;
    return NULL;
}

void* PlatformSpecificMemset(void* mem, int c, size_t size)
{
    /* To be implemented */
    (void) mem;
    (void) c;
    (void) size;
    return NULL;
}

double PlatformSpecificFabs(double d)
{
    /* To be implemented */
    (void) d;
    return 0.0;
}

extern "C" {

static int IsNanImplementation(double d)
{
    /* To be implemented */
    (void) d;
    return 0;
}

int (*PlatformSpecificIsNan)(double) = IsNanImplementation;

}

void* malloc(size_t)
{
    return NULL;
}

void free(void *)
{
}

static PlatformSpecificMutex DummyMutexCreate(void)
{
    FAIL("PlatformSpecificMutexCreate is not implemented");
    return 0;
}

static void DummyMutexLock(PlatformSpecificMutex mtx)
{
    (void)mtx;
    FAIL("PlatformSpecificMutexLock is not implemented");
}

static void DummyMutexUnlock(PlatformSpecificMutex mtx)
{
    (void)mtx;
    FAIL("PlatformSpecificMutexUnlock is not implemented");
}

static void DummyMutexDestroy(PlatformSpecificMutex mtx)
{
    (void)mtx;
    FAIL("PlatformSpecificMutexDestroy is not implemented");
}

PlatformSpecificMutex (*PlatformSpecificMutexCreate)(void) = DummyMutexCreate;
void (*PlatformSpecificMutexLock)(PlatformSpecificMutex) = DummyMutexLock;
void (*PlatformSpecificMutexUnlock)(PlatformSpecificMutex) = DummyMutexUnlock;
void (*PlatformSpecificMutexDestroy)(PlatformSpecificMutex) = DummyMutexDestroy;


