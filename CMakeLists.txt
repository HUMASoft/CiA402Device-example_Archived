cmake_minimum_required(VERSION 2.8)

project(CiA402Device-example)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/CiA402Device/)

INCLUDE_DIRECTORIES(${SUBDIR_INCLUDE_DIRECTORIES})


add_executable(${PROJECT_NAME} "main.cpp")


#link with libs
target_link_libraries( ${PROJECT_NAME} CiA402Device)
