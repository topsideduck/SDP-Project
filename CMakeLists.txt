cmake_minimum_required(VERSION 3.29)

# Set the project name
project(Game)

# Define the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -MMD -MP -Os -DOBJC_OLD_DISPATCH_PROTOTYPES -g -w")
include_directories(.)

# Platform-specific linker flags
if (WIN32)
    set(LDFLAGS "-lopengl32 -lgdi32")
    set(EXECUTABLE game)
elseif (APPLE)
    set(LDFLAGS "-framework OpenGL -framework Cocoa")
    set(EXECUTABLE game)
else ()
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(OPENGL REQUIRED glx opengl x11)
    set(LDFLAGS ${OPENGL_LDFLAGS})
    set(EXECUTABLE game)
endif ()

# Library sources
set(LIBRARY_SRCS
        src/lib/FEHLCD.cpp
        src/lib/FEHRandom.cpp
        src/lib/FEHSD.cpp
        src/lib/tigr.c
        src/lib/FEHUtility.cpp
        src/lib/FEHImages.cpp
)

# Get all student source files recursively from the parent directory
file(GLOB_RECURSE STUDENT_SRCS
        "src/*.cpp"
)

# Exclude simulator library files
list(FILTER STUDENT_SRCS EXCLUDE REGEX "src/lib/.*")

# Compile the library object files
add_library(LibraryObjects OBJECT ${LIBRARY_SRCS})

# Compile the student files
add_library(StudentObjects OBJECT ${STUDENT_SRCS}
        # Menu
        src/menu/main_menu.cpp
        src/menu/main_menu.h

        src/menu/play_game_menu.cpp
        src/menu/play_game_menu.h

        src/menu/instructions_menu.cpp
        src/menu/instructions_menu.h

        src/menu/controls_menu.cpp
        src/menu/controls_menu.h

        src/menu/statistics_menu.cpp
        src/menu/statistics_menu.h

        src/menu/credits_menu.cpp
        src/menu/credits_menu.h

        src/menu/quit_menu.cpp
        src/menu/quit_menu.h

        # Utilities
        src/util/constants.h

        src/util/input.cpp
        src/util/input.h

        src/util/play_video.cpp
        src/util/play_video.h
)

# Link the final executable
add_executable(${EXECUTABLE} $<TARGET_OBJECTS:LibraryObjects> $<TARGET_OBJECTS:StudentObjects>)
target_link_libraries(${EXECUTABLE} ${LDFLAGS})

# Clean target
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${EXECUTABLE}")
