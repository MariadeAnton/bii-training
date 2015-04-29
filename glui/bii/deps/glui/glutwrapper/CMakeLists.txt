#############BIICODE MACROS###################
include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
INIT_BIICODE_BLOCK()

ADD_DEFINITIONS(-DFREEGLUT_STATIC)
###############BIICODE MACROS################
ADD_BIICODE_TARGETS()


#############################################
if(APPLE)
	if(TARGET ${BII_LIB_TARGET})
	    FIND_LIBRARY(GLUT_LIBRARY GLUT)
	    FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
	    target_link_libraries(${BII_LIB_TARGET} PUBLIC ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
	endif()
endif()
