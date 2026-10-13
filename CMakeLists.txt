cmake_minimum_required(VERSION 3.20)

project("Gameboy Emulator" VERSION 0.1.0 LANGUAGES CXX)

include(cmake/ThirdParty.cmake)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS src/*.h src/*.hpp)

add_executable(Emulator ${SOURCES} ${HEADERS})

target_include_directories(Emulator PRIVATE src)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Emulator PRIVATE stdc++exp)
endif()

target_link_libraries(Emulator PRIVATE
    SDL3::SDL3
    imgui
)
