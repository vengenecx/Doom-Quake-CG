# CMakeList.txt : CMake project for doom_benoit_test_VS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (doom_benoit_test_VS "doom_benoit_test_VS.cpp" "doom_benoit_test_VS.h")

# TODO: Add tests and install targets if needed.
install (TARGETS doom_benoit_test_VS DESTINATION "doom_benoit_test_VS/bin")