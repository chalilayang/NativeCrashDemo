cmake_minimum_required(VERSION 3.4.1)
set (CMAKE_CXX_STANDARD 11)
set(SRC_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../distribution)

add_library(
             breakpad
             STATIC
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
             ${SRC_ROOT_DIR}/client/minidump_file_writer.cc
             ${SRC_ROOT_DIR}/common/android/breakpad_getcontext.S
             ${SRC_ROOT_DIR}/common/convert_UTF.c
             ${SRC_ROOT_DIR}/common/md5.cc)

target_include_directories(breakpad PUBLIC
                           ${SRC_ROOT_DIR}/common/android/include
                           ${SRC_ROOT_DIR})

set_target_properties(breakpad
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY
                      "${distribution_DIR}/breakpad/lib/${ANDROID_ABI}")
find_library(
              log-lib
              log )

target_link_libraries(
                       breakpad
                       ${log-lib} )

add_library(
             breakpadjni
             SHARED
             breakpad_jni.cpp
)

set_target_properties(breakpadjni
                      PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY
                      "${distribution_DIR}/breakpad/lib/${ANDROID_ABI}")