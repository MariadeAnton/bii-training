# This CMakeLists.txt file helps defining your block building and compiling
# Include the main biicode macros and functions
# To learn more about the CMake use with biicode, visit http://docs.biicode.com/c++/building.html
# Or check the examples below

include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
INIT_BIICODE_BLOCK()
ADD_DEFINITIONS(-DFREEGLUT_STATIC)
ADD_BIICODE_TARGETS()
IF({BII_LIB_TARGET})
	target_compile_definitions(${BII_LIB_TARGET} PUBLIC -DGLUI_FREEGLUT -DGLUI_BUILDING_LIB)
ENDIF()
IF(APPLE)
	FIND_LIBRARY(GLUT_LIBRARY GLUT)
	FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
endif()

FOREACH(BII_TARGET ${BII_BLOCK_TARGETS})
    if(NOT APPLE)
        target_compile_definitions(${BII_TARGET} PUBLIC -DGLUI_FREEGLUT -DGLUI_NO_LIB_PRAGMA)
    else()
	target_link_libraries(${BII_TARGET} PUBLIC ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
    endif()
endforeach()



