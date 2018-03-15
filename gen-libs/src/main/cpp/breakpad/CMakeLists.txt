cmake_minimum_required(VERSION 3.4.1)
set (CMAKE_CXX_STANDARD 11)
set(SRC_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../distribution)
enable_language(ASM)
add_library(
             breakpad
             SHARED
             breakpad_jni.cpp
             ${SRC_ROOT_DIR}/client/linux/crash_generation/crash_generation_client.cc
             ${SRC_ROOT_DIR}/client/linux/dump_writer_common/thread_info.cc
             ${SRC_ROOT_DIR}/client/linux/dump_writer_common/ucontext_reader.cc
             ${SRC_ROOT_DIR}/client/linux/handler/exception_handler.cc
             ${SRC_ROOT_DIR}/client/linux/handler/minidump_descriptor.cc
             ${SRC_ROOT_DIR}/client/linux/log/log.cc
             ${SRC_ROOT_DIR}/client/linux/microdump_writer/microdump_writer.cc
             ${SRC_ROOT_DIR}/client/linux/minidump_writer/linux_dumper.cc
             ${SRC_ROOT_DIR}/client/linux/minidump_writer/linux_ptrace_dumper.cc
             ${SRC_ROOT_DIR}/client/linux/minidump_writer/minidump_writer.cc
             ${SRC_ROOT_DIR}/common/linux/linux_libc_support.cc
             ${SRC_ROOT_DIR}/common/linux/guid_creator.cc
             ${SRC_ROOT_DIR}/common/linux/memory_mapped_file.cc
             ${SRC_ROOT_DIR}/common/linux/file_id.cc
             ${SRC_ROOT_DIR}/common/linux/elfutils.cc
             ${SRC_ROOT_DIR}/common/linux/safe_readlink.cc
             ${SRC_ROOT_DIR}/client/minidump_file_writer.cc
             ${SRC_ROOT_DIR}/common/android/breakpad_getcontext.S
             ${SRC_ROOT_DIR}/common/convert_UTF.c
             ${SRC_ROOT_DIR}/common/md5.cc
             ${SRC_ROOT_DIR}/common/string_conversion.cc)

target_include_directories(breakpad PUBLIC
                           ${SRC_ROOT_DIR}/common/android/include
                           ${SRC_ROOT_DIR})

set_target_properties(breakpad
                      PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY
                      "${distribution_DIR}/breakpad/lib/${ANDROID_ABI}")
find_library(
              log-lib
              log )

target_link_libraries(
                       breakpad
                       ${log-lib} )