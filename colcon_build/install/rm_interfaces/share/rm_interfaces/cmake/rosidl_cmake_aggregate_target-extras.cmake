# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target rm_interfaces::rm_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${rm_interfaces_TARGETS}.
if(rm_interfaces_TARGETS AND NOT TARGET rm_interfaces::rm_interfaces)
  add_library(rm_interfaces::rm_interfaces INTERFACE IMPORTED)
  set_target_properties(rm_interfaces::rm_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${rm_interfaces_TARGETS}")
endif()
