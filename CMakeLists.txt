cmake_minimum_required(VERSION 2.8)

project(CiA402Device-example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib/CiA402Device/)

INCLUDE_DIRECTORIES(${SUBDIR_INCLUDE_DIRECTORIES})


aux_source_directory(main SRC_LIST)

#add_subdirectory(lib)

#add all executables in foreach
#SUBDIR_LINK_NAMES got from:
#set(SUBDIR_LINK_NAMES ${SUBDIR_LINK_NAMES} ${PROJECT_NAME} PARENT_SCOPE)
#in subprojects
foreach( sourcefile ${SRC_LIST} )
    #Used a simple string replace, to cut off .cpp.
    string( REGEX REPLACE "[A-z]+[/]" "" name ${sourcefile} )
    string( REPLACE ".cpp" "" name ${name} )
    #add executable
    add_executable( ${name} ${sourcefile} )
    message ("Including executable: " ${name})
    #link with libs
    target_link_libraries( ${name} ${SUBDIR_LINK_NAMES} )
endforeach( sourcefile ${SRC_LIST} )

