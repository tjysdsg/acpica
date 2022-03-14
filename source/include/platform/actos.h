#ifndef __ACTOS_H__
#define __ACTOS_H__

#include "acgcc.h"
#include "acgccex.h"
#include <string.h>
#include <kernel.h>
#include <ctype.h>
#include <stdio.h>
#include <sched.h>
#include <atomic.h>
#include <spinlock_types.h>

#define ACPI_USE_DO_WHILE_0
#define ACPI_USE_STANDARD_HEADERS
#define ACPI_USE_SYSTEM_CLIBRARY

#define ACPI_DEBUG_OUTPUT
#define CONFIG_ACPI_DEBUG

/* Kernel specific ACPICA configuration */

#ifdef CONFIG_ACPI_REDUCED_HARDWARE_ONLY
#define ACPI_REDUCED_HARDWARE 1
#endif

#ifdef CONFIG_ACPI_DEBUGGER
#define ACPI_DEBUGGER
#endif

#ifdef CONFIG_ACPI_DEBUG
#define ACPI_MUTEX_DEBUG
#endif

#define ACPI_INIT_FUNCTION

#ifndef CONFIG_ACPI

/* Generating stubs for configurable ACPICA functions */

#undef ACPI_DEBUG_OUTPUT

#endif /* CONFIG_ACPI */

/* Host-dependent types and defines for in-kernel ACPICA */

#define ACPI_FLUSH_CPU_CACHE()
#define ACPI_CAST_PTHREAD_T(Pthread) ((ACPI_THREAD_ID) (Pthread))

#if defined(__ia64__)    || defined(__x86_64__) ||\
    defined(__aarch64__) || defined(__PPC64__) ||\
    defined(__s390x__)
#define ACPI_MACHINE_WIDTH          64
#define COMPILER_DEPENDENT_INT64    long
#define COMPILER_DEPENDENT_UINT64   unsigned long
#else
#define ACPI_MACHINE_WIDTH          32
#define COMPILER_DEPENDENT_INT64    long long
#define COMPILER_DEPENDENT_UINT64   unsigned long long
#define ACPI_USE_NATIVE_DIVIDE
#define ACPI_USE_NATIVE_MATH64
#endif

#ifndef __cdecl
#define __cdecl
#endif

#define ACPI_CACHE_T                ACPI_MEMORY_LIST
#define ACPI_USE_LOCAL_CACHE        1

#define ACPI_USE_NATIVE_MATH64
#define ACPI_EXPORT_SYMBOL(symbol)  EXPORT_SYMBOL(symbol);
#define strtoul                     simple_strtoul

#define ACPI_SPINLOCK               spinlock_t *
#define ACPI_CPU_FLAGS              unsigned long

#define ACPI_MSG_ERROR          "ACPI Error: "
#define ACPI_MSG_EXCEPTION      "ACPI Exception: "
#define ACPI_MSG_WARNING        "ACPI Warning: "
#define ACPI_MSG_INFO           "ACPI: "

#define ACPI_MSG_BIOS_ERROR     "ACPI BIOS Error (bug): "
#define ACPI_MSG_BIOS_WARNING   "ACPI BIOS Warning (bug): "

#endif /* __ACTOS_H__ */
