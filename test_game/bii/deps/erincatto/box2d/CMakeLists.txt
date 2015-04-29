IF(BIICODE)
  include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
  # Initializes block variables
  INIT_BIICODE_BLOCK()
  # Include base block dir
  ADD_BIICODE_TARGETS()
  TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

  IF (UNIX AND TARGET erincatto_box2d_Testbed_Framework_Main)
		find_package(X11 REQUIRED)
		IF(APPLE)
			TARGET_LINK_LIBRARIES(erincatto_box2d_Testbed_Framework_Main PUBLIC ${X11_LIBRARY_DIR})
		ELSE()
			add_definitions( -D__unix__ -DHAVE_FCNTL_H -DHAVE_GETTIMEOFDAY )
			TARGET_LINK_LIBRARIES(erincatto_box2d_Testbed_Framework_Main PUBLIC X11)
		ENDIF()
  ENDIF(UNIX)


ELSE()
  cmake_minimum_required(VERSION 2.6)
  project(Box2D)

  if(UNIX)
    set(BOX2D_INSTALL_BY_DEFAULT ON)
  else(UNIX)
    set(BOX2D_INSTALL_BY_DEFAULT OFF)
  endif(UNIX)

  option(BOX2D_INSTALL "Install Box2D libs, includes, and CMake scripts" ${BOX2D_INSTALL_BY_DEFAULT})
  option(BOX2D_INSTALL_DOC "Install Box2D documentation" OFF)
  option(BOX2D_BUILD_SHARED "Build Box2D shared libraries" OFF)
  option(BOX2D_BUILD_STATIC "Build Box2D static libraries" ON)
  option(BOX2D_BUILD_EXAMPLES "Build Box2D examples" ON)

  set(BOX2D_VERSION 2.1.0)

  # The Box2D library.
  add_subdirectory(Box2D)

  if(BOX2D_BUILD_EXAMPLES)
    # HelloWorld console example.
    add_subdirectory(HelloWorld)

    # Testbed and dependencies.
    find_package(OpenGL REQUIRED)
    add_subdirectory(freeglut)
    add_subdirectory(glui)
    add_subdirectory(Testbed)
  endif(BOX2D_BUILD_EXAMPLES)

  if(BOX2D_INSTALL_DOC)
    install(DIRECTORY Documentation DESTINATION share/doc/Box2D PATTERN ".svn" EXCLUDE)
  endif(BOX2D_INSTALL_DOC)
ENDIF()