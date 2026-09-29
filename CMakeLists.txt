cmake_minimum_required(VERSION 3.20)

project(Hovertank3Dsdl LANGUAGES C)

set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

# find_package(SDL2_image REQUIRED)

add_executable(hovertank3D
    HOVACTS.C
    HOVDRAW.C
    HOVLOOP.C
    HOVMAIN.C
    HOVSCALE.C
    HOVTEXT.C
    HOVTRACE.C
    IDLIBC.C
    JM_SB.C
    MEMMGR.C
    sdlport.c
)

#set_target_properties(hovertank3D PROPERTIES LINKER_LANGUAGE C)
get_target_property(hovertank_sources hovertank3D SOURCES)
set_source_files_properties(${hovertank_sources} PROPERTIES LANGUAGE C)
target_compile_options(hovertank3D PRIVATE -include "${CMAKE_CURRENT_SOURCE_DIR}/sdlport.h")

target_link_libraries(hovertank3D PRIVATE SDL2::SDL2)
add_definitions(-w)
# target_link_libraries(hovertank3D PRIVATE SDL2::SDL2_image)

target_include_directories(hovertank3D PRIVATE ${SDL2_INCLUDE_DIRS})
