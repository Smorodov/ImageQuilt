# ----------------------------------------------------------------------------
# минимальна€ верси€ CMake, способна€ переварить этот файл
# ----------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)

set (PROJ_NAME ImageQuilt)

project(${PROJ_NAME})
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# ---------------------------------------------------------------------------- 
# ѕредполагаем, что FindOpenCV.cmake расположен по адресу CMAKE_MODULE_PATH.
# ----------------------------------------------------------------------------
  FIND_PACKAGE(OpenCV)
# ----------------------------------------------------------------------------  
# ищем все .cpp и .h файлы и добавл€ем их в наш проект 
# ----------------------------------------------------------------------------
  set(folder_source ImageQuilt/main.cpp
  					ImageQuilt/custom_types.cpp
  					ImageQuilt/ImageQuilt.cpp )

  set(folder_header extlibs/include/stb_image.h
  					extlibs/include/stb_image_write.h
  					ImageQuilt/custom_types.h
  					ImageQuilt/ImageQuilt.h )


  SOURCE_GROUP("Source Files" FILES ${folder_source})
  SOURCE_GROUP("Header Files" FILES ${folder_header})

  include_directories(extlibs/include)
  include_directories(ImageQuilt)
# ----------------------------------------------------------------------------  
# создаем проект
# ----------------------------------------------------------------------------
  ADD_EXECUTABLE(${PROJ_NAME} ${folder_source} ${folder_header})
# ----------------------------------------------------------------------------
# добавл€ем Lib-ы opencv 
# ---------------------------------------------------------------------------- 
  TARGET_LINK_LIBRARIES(${PROJ_NAME} ${OpenCV_LIBS})
