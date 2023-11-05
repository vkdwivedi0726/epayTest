# CMakeList.txt : CMake project for PrintDirectoryTree, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (PrintDirectoryTree "PrintDirectoryTree.cc" "PrintDirectoryTree.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
  set_property(TARGET PrintDirectoryTree PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
