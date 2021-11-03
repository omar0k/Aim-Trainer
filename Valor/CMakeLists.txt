set(SOURCE_FILES ValorApp.cpp GameWindow.cpp GLFWImpl/GLFWimplementation.cpp)

set(HEADER_FILES Valor.h ValorApp.h ValorUtils.h WindowImplementation.h GameWindow.h GLFWImpl/GLFWimplementation.h)

add_library(valor_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(valor_lib PRIVATE pch.h)

add_definitions(-DVALOR_LIB)

target_link_libraries(valor_lib glfw)

include_directories(../glfw/include)
include_directories(../Valor)