add_library(imgui STATIC
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_sdl3.cpp
    ${CMAKE_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_sdlrenderer3.cpp
)

target_include_directories(imgui PUBLIC
    ${CMAKE_SOURCE_DIR}/third_party/imgui
    PRIVATE
    ${CMAKE_SOURCE_DIR}/third_party/sdl/include
)
