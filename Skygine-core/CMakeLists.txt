project(Skygine)

cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/libs/SDL2-2.0.12/include)
set(SDL2_LIBRARY ${PROJECT_SOURCE_DIR}/libs/SDL2-2.0.12/lib/x86)

set(SDL2_IMAGE_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/libs/SDL2_image-2.0.5/include)
set(SDL2_IMAGE_LIBRARIES ${PROJECT_SOURCE_DIR}/libs/SDL2_image-2.0.5/lib/x86)

find_package(SDL2 REQUIRED)

include_directories(./libs/spdlog-1.5.0/include)
include_directories(./libs/SDL2-2.0.12/include)
include_directories(./libs/SDL2_image-2.0.5/include)
include_directories(./libs/SDL2_mixer-2.0.4/include)
include_directories(./libs/SDL2_ttf-2.0.15/include)
include_directories(./libs/json-3.7.3/include)

add_executable(Skygine main.cpp)

target_link_libraries(Skygine
        ../libs/SDL2-2.0.12/lib/x86/SDL2
        ../libs/SDL2-2.0.12/lib/x86/SDL2main
        ../libs/SDL2_image-2.0.5/lib/x86/SDL2_image
        ../libs/SDL2_mixer-2.0.4/lib/x86/SDL2_mixer
        ../libs/SDL2_ttf-2.0.15/lib/x86/SDL2_ttf)

#add_library(Skygine libs/SDL2-2.0.12/lib/x86/SDL2.dll)
