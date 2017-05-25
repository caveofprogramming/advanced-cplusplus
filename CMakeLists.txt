cmake_minimum_required(VERSION 3.0)

macro(subdirlist result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child} AND NOT ${child} STREQUAL ".git" AND NOT ${child} STREQUAL "src")
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

project(advanced-cplusplus)

subdirlist(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach(subdir ${SUBDIRS})
  add_subdirectory(${subdir})
endforeach()

# add the local sourec to the this main project

file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

add_executable(${PROJECT_NAME} ${project_sources} ${project_headers})