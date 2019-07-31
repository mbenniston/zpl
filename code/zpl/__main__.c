/*

  ZPL - Global module
  
Usage:
  #define ZPL_IMPLEMENTATION exactly in ONE source file right BEFORE including the library, like:
  
  #define ZPL_IMPLEMENTATION
  #include "zpl.h"
  
  To make use of platform layer, define ZPL_PLATFORM, like:
  
  #define ZPL_PLATFORM
  #include "zpl.h"
  
Options:

  ZPL_PREFIX_TYPES - to make sure all ZPL defined types have a prefix to avoid cluttering the global namespace.
  ZPL_DEFINE_NULL_MACRO - to let ZPL define what NULL stands for in case it is undefined.
  
  
Credits:
  Read AUTHORS.md
  
GitHub:
  https://github.com/zpl-c/zpl
  
Version History: 
  9.5.0 - Added base64 encode/decode methods
  9.4.10- Small enum style changes
  9.4.9 - Remove #undef for cast and hard_cast (sorry)
  9.4.8 - Fix quote-less JSON node name resolution
  9.4.7 - Additional change to the code
  9.4.6 - Fix issue where zpl_json_find would have false match on substrings
  9.4.5 - Mistakes were made, fixed compilation errors
  9.4.3 - Fix old API shenanigans
  9.4.2 - Fix small API typos
  9.4.1 - Reordered JSON5 constants to integrate better with conditions
  9.4.0 - JSON5 API changes made to zpl_json_find
  9.3.0 - Change how zpl uses basic types internally
  9.2.0 - Directory listing was added. Check dirlist_api.c test for more info
  9.1.1 - Fix WIN32_LEAN_AND_MEAN redefinition properly
  9.1.0 - get_env rework and fixes
  9.0.3 - Small fixes and removals
  9.0.0 - New documentation format, removed deprecated code, changed styles

  8.14.1 - Fix string library
  8.14.0 - Added zpl_re_match_all
  8.13.0 - Update system command API
  8.12.6 - Fix warning in CLI options parser
  8.12.5 - Support parametric options preceding positionals
  8.12.4 - Fixed opts positionals ordering
  8.12.3 - Fixed incorrect handling of flags preceding positionals
  8.12.2 - JSON parsing remark added
  8.12.1 - Fixed a lot of important stuff
  8.12.0 - Added helper constructors for containers
  8.11.2 - Fix bug in opts module
  8.11.1 - Small code improvements
  8.11.0 - Ported regex processor from https://github.com/gingerBill/gb/ and applied fixes on top of it 
  8.10.2 - Fix zpl_strtok
  8.10.1 - Replace zpl_strchr by zpl_char_last_occurence
  8.10.0 - Added zpl_strchr
  8.9.0  - API improvements for JSON5 parser
  8.8.4  - Add support for SJSON formatting http://bitsquid.blogspot.com/2009/10/simplified-json-notation.html
  
  6.8.3  - JSON5 exp fix
  6.8.2  - Bugfixes applied from gb
  6.8.1  - Performance improvements for JSON5 parser
  6.8.0  - zpl.h is now generated by build.py
  6.7.0  - Several fixes and added switches
  6.6.0  - Several significant changes made to the repository
  6.5.0  - Ported platform layer from https://github.com/gingerBill/gb/
  6.4.1  - Use zpl_strlen in zpl_strdup
  6.4.0  - Deprecated zpl_buffer_free and added zpl_array_end, zpl_buffer_end
  6.3.0  - Added zpl_strdup
  6.2.1  - Remove math redundancies
  6.2.0  - Integrated zpl_math.h into zpl.h
  6.1.1  - Added direct.h include for win c++ dir methods
  6.1.0  - Added zpl_path_mkdir, zpl_path_rmdir, and few new zplFileErrors
  6.0.4  - More MSVC(++) satisfaction by fixing warnings
  6.0.3  - Satisfy MSVC by fixing a warning
  6.0.2  - Fixed warnings for json5 i64 printfs
  6.0.1  - Fixed warnings for particual win compiler in dirlist method
  6.0.0  - New build, include/ was renamed to code/
  
  5.8.3  - Naming fixes
  5.8.2  - Job system now supports prioritized tasks
  5.8.1  - Renames zpl_pad to zpl_ring
  5.8.0  - Added instantiated scratch pad (circular buffer)
  5.7.2  - Added Windows support for zpl_path_dirlist
  5.7.1  - Fixed few things in job system + macOS support for zpl_path_dirlist
  5.7.0  - Added a job system (zpl_thread_pool)
  5.6.5  - Fixes extra error cases for zpl_opts when input is:
         - missing a value for an option,
         - having an extra value for a flag (e.g. --enable-log shouldn't get a value.)
  5.6.4  - Several tweaks to the zpl_opts API
  5.6.3  - Added support for flags without values
  5.6.2  - Improve error handling for zpl_opts
  5.6.1  - Added support for strings with spaces in zpl_opts
  5.6.0  - Added zpl_opts for CLI argument parsing
  5.5.1  - Fixed time method for win
  5.5.0  - Integrate JSON5 writer into the core
  5.4.0  - Improved storage support for numbers in JSON5 parser
  5.3.0  - Integrated zpl_json into ZPL
  5.2.0  - Added zpl_string_sprintf
  5.1.1  - Added zpl_system_command_nores for output-less execution
  5.1.0  - Added event handler
  5.0.4  - Fix alias for zpl_list
  5.0.3  - Finalizing syntax changes
  5.0.2  - Fix segfault when using zpl_stack_memory
  5.0.1  - Small code improvements
  5.0.0  - Project structure changes
  
  4.7.2  - Got rid of size arg for zpl_str_split_lines
  4.7.1  - Added an example
  4.7.0  - Added zpl_path_dirlist
  4.6.1  - zpl_memcopy x86 patch from upstream
  4.6.0  - Added few string-related functions
  4.5.9  - Error fixes
  4.5.8  - Warning fixes
  4.5.7  - Fixed timer loops. zpl_time* related functions work with seconds now
  4.5.6  - Fixed zpl_time_now() for Windows and Linux
  4.5.5  - Small cosmetic changes
  4.5.4  - Fixed issue when zpl_list_add would break the links
         - when adding a new item between nodes
  4.5.3  - Fixed malformed enum values
  4.5.1  - Fixed some warnings
  4.5.0  - Added zpl_array_append_at
  4.4.0  - Added zpl_array_back, zpl_array_front
  4.3.0  - Added zpl_list
  4.2.0  - Added zpl_system_command_str
  4.1.2  - GG, fixed small compilation error
  4.1.1  - Fixed possible security issue in zpl_system_command
  4.1.0  - Added zpl_string_make_reserve and small fixes
  4.0.2  - Warning fix for _LARGEFILE64_SOURCE
  4.0.1  - include stdlib.h for getenv (temp)
  4.0.0  - ARM support, coding style changes and various improvements
  
  3.4.1  - zpl_memcopy now uses memcpy for ARM arch-family
  3.4.0  - Removed obsolete code
  3.3.4  - Added Travis CI config
  3.3.3  - Small macro formatting changes + ZPL_SYSTEM_IOS
  3.3.2  - Fixes for android arm
  3.3.1  - Fixed some type cast warnings
  3.3.0  - Added Android support
  3.1.5  - Renamed userptr to user_data in timer
  3.1.4  - Fix for zpl_buffer not allocating correctly
  3.1.2  - Small fix in zpl_memcompare
  3.1.1  - Added char* conversion for data field in zpl_array_header
  3.1.0  - Added data field to zpl_array_header
  3.0.7  - Added timer userptr as argument to callback
  3.0.6  - Small changes
  3.0.5  - Fixed compilation for emscripten
  3.0.4  - Small fixes for tiny cpp warnings
  3.0.3  - Small fixes for various cpp warnings and errors
  3.0.2  - Fixed linux part, and removed trailing spaces
  3.0.1  - Small bugfix in zpl_file_open
  3.0.0  - Added several fixes and features
  
  2.4.0  - Added remove to hash table
  2.3.3  - Removed redundant code
  2.3.2  - Eliminated extra warnings
  2.3.1  - Warning hunt
  2.3.0  - Added the ability to copy array/buffer and fixed bug in hash table.
  2.2.1  - Used tmpfile() for Windows
  2.2.0  - Added zpl_file_temp
  2.1.1  - Very small fix (forgive me)
  2.1.0  - Added the ability to resize bitstream
  2.0.8  - Small adjustments
  2.0.7  - MinGW related fixes
  2.0.0  - New NPM based version
  
  1.2.2  - Small fix
  1.2.1  - Macro fixes
  1.2.0  - Added zpl_async macro
  1.1.0  - Added timer feature
  1.0.0  - Initial version
  
  This Software is dual licensed under the following licenses:
  
  Unlicense
  This is free and unencumbered software released into the public domain.
  
  Anyone is free to copy, modify, publish, use, compile, sell, or
  distribute this software, either in source code form or as a compiled
  binary, for any purpose, commercial or non-commercial, and by any
  means.
  
  In jurisdictions that recognize copyright laws, the author or authors
  of this software dedicate any and all copyright interest in the
  software to the public domain. We make this dedication for the benefit
  of the public at large and to the detriment of our heirs and
  successors. We intend this dedication to be an overt act of
  relinquishment in perpetuity of all present and future rights to this
  software under copyright law.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.
  
  For more information, please refer to <http://unlicense.org/>
  
  Apache 2.0
  Copyright 2017-2019 Dominik Madarász <zaklaus@outlook.com>
  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at
  
      http://www.apache.org/licenses/LICENSE-2.0
      
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License. 
  
*/

//
// TOP
//

//
// This file was generated by build.py script. Do not modify it!
// Instead, visit a specific module and edit it, then execute build.py to generate this file.
//

#ifndef ZPL_INCLUDE_ZPL_H
#define ZPL_INCLUDE_ZPL_H

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#endif

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4201)
#pragma warning(disable : 4127) // Conditional expression is constant
#endif


#if defined(__cplusplus)
extern "C" {
#endif
    
    //<#head>
    
#if defined(__cplusplus)
}
#endif

#if defined(ZPL_COMPILER_MSVC)
#pragma warning(pop)
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

#if defined(ZPL_IMPLEMENTATION) && !defined(ZPL_IMPLEMENTATION_DONE)
#define ZPL_IMPLEMENTATION_DONE

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
#pragma GCC diagnostic ignored "-Wunused-value"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wmissing-braces"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4201)
#pragma warning(disable : 4127) // Conditional expression is constant
#endif

#if defined(__cplusplus)
extern "C" {
#endif
    
    //<#source>
    
#if defined(__cplusplus)
}
#endif

#if defined(ZPL_COMPILER_MSVC)
#pragma warning(pop)
#endif

#if defined(__GCC__) || defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

#endif // ZPL_IMPLEMENTATION

//<<header.c>>
//<<mem.c>>
//<<threads.c>>
//<<sort.c>>
//<<string.c>>
//<<regex.c>>
//<<containers.c>>
//<<hashing.c>>
//<<hashtable.c>>
//<<file.c>>
//<<print.c>>
//<<dll.c>>
//<<time.c>>
//<<event.c>>
//<<misc.c>>
//<<json.c>>
//<<opts.c>>
//<<threadpool.c>>
//<<math.c>>
//<<platform.c>>

#if !defined(ZPL_PREFIX_TYPES)
typedef zpl_u8 u8;
typedef zpl_i8 i8;
typedef zpl_u16 u16;
typedef zpl_i16 i16;
typedef zpl_u32 u32;
typedef zpl_i32 i32;
typedef zpl_u64 u64;
typedef zpl_i64 i64;
typedef zpl_b8 b8;
typedef zpl_b16 b16;
typedef zpl_b32 b32;
typedef zpl_f32 f32;
typedef zpl_f64 f64;
typedef zpl_rune rune;
typedef zpl_usize usize;
typedef zpl_isize isize;
typedef zpl_uintptr uintptr;
typedef zpl_intptr intptr;
#endif // ZPL_PREFIX_TYPES

#endif // ZPL_INCLUDE_ZPL_H

///////////////////////////////////////////////////////////////
//
// Code Snippets
//

/*


#ifndef FOO_H
#define FOO_H

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#if defined(FOO_IMPLEMENTATION) && !defined(FOO_IMPLEMENTATION_DONE)
#define FOO_IMPLEMENTATION_DONE

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif // FOO_IMPLEMENTATION
#endif // FOO_H


 */
