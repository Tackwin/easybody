cmake_minimum_required(VERSION 3.16)
project(easybody)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLEW)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

include_directories(${SDL2_INCLUDE_DIRS})
add_executable(easybody
	${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/gl3w.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Graphics.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/glew.c
	${CMAKE_CURRENT_SOURCE_DIR}/src/imgui.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_demo.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_draw.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_widgets.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_impl_sdl.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_impl_opengl2.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/imgui_impl_opengl3.cpp
)

set_source_files_properties(
	${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c PROPERTIES LANGUAGE C
)
set_source_files_properties(
	${CMAKE_CURRENT_SOURCE_DIR}/src/gl3w.c PROPERTIES LANGUAGE C
)
set_source_files_properties(
	${CMAKE_CURRENT_SOURCE_DIR}/src/glew.c PROPERTIES LANGUAGE C
)
target_link_libraries(easybody ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_link_libraries(easybody ${OPENGL_LIBRARIES})
target_link_libraries(easybody ${CMAKE_DL_LIBS})
target_link_libraries(easybody ${SDL2_LIBRARIES})
