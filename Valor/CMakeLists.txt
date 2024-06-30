set(SOURCE_FILES 
ValorApp.cpp 
GameWindow.cpp 
GLFWImpl/GLFWimplementation.cpp
Shader.cpp
Renderer.cpp
Sprite.cpp
Events.cpp
OpenGLimpl/OpenGLRenderer.cpp
OpenGLimpl/OpenGLShader.cpp
OpenGLimpl/OpenGLSprite.cpp

)

set(HEADER_FILES 
Valor.h 
ValorApp.h 
ValorUtils.h 
WindowImplementation.h 
GameWindow.h 
GLFWImpl/GLFWimplementation.h
Renderer.h
RendererImplementation.h
Shader.h
ShaderImplementation.h
Sprite.h
SpriteImplementation.h
Events.h
KeyCodes.h
OpenGLimpl/OpenGLRenderer.h
OpenGLimpl/OpenGLShader.h
OpenGLimpl/OpenGLSprite.h

)

add_library(valor_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(valor_lib PRIVATE pch.h)

add_definitions(-DVALOR_LIB)

target_link_libraries(valor_lib glfw glad stbi)

include_directories(../glfw/include)
include_directories(../Valor)
include_directories(../Glad/include)
include_directories(../stbi)
include_directories(../glm)
include_directories(../FreeType/include)

