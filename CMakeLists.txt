cmake_minimum_required(VERSION 3.10)
project(MyTagLibProject)

find_package(PkgConfig)

# Macro used for pkg-config
pkg_check_modules(TAGLIB REQUIRED IMPORTED_TARGET taglib)


# Add your executable or library
add_executable(main main.cpp)

# Link TagLib to your executable
target_link_libraries(main PkgConfig::TAGLIB stdc++fs)


