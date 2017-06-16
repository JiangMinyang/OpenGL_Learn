find_package(PkgConfig REQUIRED)
find_package(GLFW3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

#Bring headers to the project
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${TARGET} ${SOURCES})

target_link_libraries(${TARGET} ${GLFW_LIBRARIES})
target_link_libraries(${TARGET} ${OPENGL_gl_LIBRARY})
target_link_libraries(${TARGET} ${OPENGL_glu_LIBRARY})
target_link_libraries(${TARGET} glfw3) 
target_link_libraries(${TARGET} ${GLEW_LIBRARIES})

if (APPLE)
  target_link_libraries(${TARGET} "-framework OpenGL")
  target_link_libraries(${TARGET} "-framework Cocoa")
  target_link_libraries(${TARGET} "-framework CoreVideo")
  target_link_libraries(${TARGET} "-framework IOKit")
endif()