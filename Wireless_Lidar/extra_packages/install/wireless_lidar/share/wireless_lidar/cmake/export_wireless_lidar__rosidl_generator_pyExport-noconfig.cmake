#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "wireless_lidar::wireless_lidar__rosidl_generator_py" for configuration ""
set_property(TARGET wireless_lidar::wireless_lidar__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(wireless_lidar::wireless_lidar__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libwireless_lidar__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libwireless_lidar__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS wireless_lidar::wireless_lidar__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_wireless_lidar::wireless_lidar__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libwireless_lidar__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
