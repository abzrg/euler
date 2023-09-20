// CHRONO
// ------
//
// A tool for timing code
//
// Usage:
//
//      chrono
//      {
//          your code here...
//      }
//

#ifndef UTILS_CHRONO_CHRONO_H
#define UTILS_CHRONO_CHRONO_H

#include <stdint.h>

#include "./defer.h"

#if defined(__linux__)
#include "chrono_linux.h"
#elif defined(__APPLE__)
#include "chrono_macos.h"
#elif defined(_WIN32) || defined(_WIN64)
#include "chrono_windows.h"
#elif defined(__OpenBSD__)
#include "chrono_openbsd.h"
#else
#error "Unsupported platform"
#endif

#define chrono defer(chrono_start(), chrono_stop())

#endif /* UTILS_CHRONO_CHRONO_H */
