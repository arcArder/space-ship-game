cmake_minimum_required(VERSION 3.14)
project(SpaceShipGame LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотека raylib скачивается автоматически при настройке проекта
include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW ON
)
FetchContent_MakeAvailable(raylib)

# Все .cpp файлы из папки src/ подхватываются автоматически,
# поэтому при добавлении новых файлов этот файл менять не нужно.
file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(game ${GAME_SOURCES})
target_link_libraries(game PRIVATE raylib)
target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Копируем папку assets (если она есть) рядом с exe-файлом
if(EXISTS ${CMAKE_SOURCE_DIR}/assets)
    add_custom_command(TARGET game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:game>/assets)
endif()