set(SDL_TEST_LIBRARY OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/third_party/sdl
    ${CMAKE_BINARY_DIR}/third_party/sdl
)
