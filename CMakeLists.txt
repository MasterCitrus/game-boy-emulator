cmake_minimum_required(VERSION 3.20)

project("Gameboy Emulator" VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/ThirdParty.cmake)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS src/*.h src/*.hpp)

add_executable(Emulator ${SOURCES} ${HEADERS})

target_include_directories(Emulator PRIVATE src)

target_link_libraries(Emulator PRIVATE
    SDL3::SDL3
    imgui
)
