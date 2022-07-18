cmake_minimum_required(VERSION 3.16.3)


# "none" => No logs
# "errors" => Just the errors
# "warnings" => Errors and warnings
# "events" => Errors, warnings and events
# "verbose" => Errors, warning, logs plus extra events.
set(LOG_SETTINGS "verbose" CACHE STRING "LOG_SETTINGS chosen by the user at CMake configure time")
set_property(CACHE LOG_SETTINGS PROPERTY STRINGS verbose errors warnings events none)
set(SET_LOG TRUE CACHE BOOL "set print statements")


# configure a header file to pass some of the CMake settings
# to the source code
configure_file(log_settings.h.in log_settings.h)

add_library(Logger INTERFACE)

# add the binary tree to the search path for include files
# so that we will find log_sttings.h.in
target_include_directories(Logger INTERFACE "${PROJECT_BINARY_DIR}/Logger")