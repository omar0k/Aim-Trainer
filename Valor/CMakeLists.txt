set(SOURCE_FILES ValorApp.cpp)

set(HEADER_FILES Valor.h ValorApp.h ValorUtils.h)

add_library(valor_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(valor_lib PRIVATE pch.h)

add_definitions(-DVALOR_LIB)

target_link_libraries(valor_lib glfw)

include_directories(../glfw/include)