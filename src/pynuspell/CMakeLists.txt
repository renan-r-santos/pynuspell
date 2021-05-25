# CMakeList.txt : CMake project for pynuspell
cmake_minimum_required (VERSION 3.8)

# Add source to this project's module.
pybind11_add_module (pynuspell "pynuspell.cpp")

# Link libraries
target_link_libraries (pynuspell PRIVATE Nuspell::nuspell)
