# CMakeList.txt : Top-level CMake project file
cmake_minimum_required (VERSION 3.8)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

project ("pynuspell")

# Set C++ 17 Standard
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Find dependencies
find_package (Nuspell CONFIG REQUIRED)

# Include sub-projects.
add_subdirectory (extern/pybind11)
add_subdirectory (src/pynuspell)
