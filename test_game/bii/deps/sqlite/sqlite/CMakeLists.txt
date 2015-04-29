IF(BIICODE)
  include(${CMAKE_HOME_DIRECTORY}/biicode.cmake)
  # Initializes block variables
  INIT_BIICODE_BLOCK()

  SET(BII_CREATE_LIB True)

  # Include base block dir
  ADD_BIICODE_TARGETS()
  
  # Add some sources
  TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
  TARGET_INCLUDE_DIRECTORIES(${BII_LIB_TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/sqlite3)
 
  # Link target with dl for linux
  IF (UNIX)
   IF(NOT APPLE)
     TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC dl)
   ENDIF()
  ENDIF()  

ELSE()
  include(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists_original.txt)
ENDIF()
