/**
 * @file PlatformDetection.hpp
 * @author LeenDenVan ()
 * @brief 
 * @version 0.1
 * @date 2022-03-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GT_PLATFORM_DETECTION_HPP_
#define GT_PLATFORM_DETECTION_HPP_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   //define something for Windows (32-bit and 64-bit, this part is common)
   #define GT_WIN_
   #ifdef _WIN64
      #define GT_WIN64_
   #else
      #define GT_WIN32_
   #endif
#elif __APPLE__
    #include <TargetConditionals.h>
    #define GT_APPLE_
    #if TARGET_IPHONE_SIMULATOR
         #define GT_APPLE_SIM_
    #elif TARGET_OS_MACCATALYST
         // Mac's Catalyst (ports iOS API into Mac, like UIKit).
    #elif TARGET_OS_IPHONE
        // iOS, tvOS, or watchOS device
        #define GT_APPLE_IPHONE_
    #elif TARGET_OS_MAC
        #define GT_APPLE_MAC_
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __linux__
    // linux
    #define GT_LINUX_
#elif __unix__ // all unices not caught above
    // Unix
    #define GT_UNIX_
#elif defined(__ANDROID__)
    // POSIX
    #define GT_ANDROID_
#else
#   error "Unknown compiler"
#endif

#endif