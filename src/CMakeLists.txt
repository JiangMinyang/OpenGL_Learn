find_package(PkgConfig REQUIRED)
#find_package(GLFW3 3.3 REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

if (UNIX AND NOT APPLE)
  find_package(X11)
  set(ADDITIONAL_LIBS 
     -pthread
     -ldl
     -lXcursor
     -lXinerama
     -lXrandr
     -lXxf86vm
     -lXi
  ) 

  set(OS_SPECIFIC_LIBS 
    ${X11_LIBRARIES}
    ${ADDITIONAL_LIBS}
  )
endif()

if (APPLE)
  set(OS_SPECIFIC_LIBS 
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework CoreVideo"
    "-framework IOKit"
  )
endif()

set(LIBRARIES 
  ${GLFW_LIBRARIES}
  ${OPENGL_gl_LIBRARY}
  ${OPENGL_glu_LIBRARY}
  ${GLEW_LIBRARIES}
  ${GLFW_STATIC_LIBRARIES}
  glfw3
  ${OS_SPECIFIC_LIBS}
)

add_executable(${TARGET} 
  ${SOURCES}
)

target_link_libraries(${TARGET} 
  ${LIBRARIES}
)
