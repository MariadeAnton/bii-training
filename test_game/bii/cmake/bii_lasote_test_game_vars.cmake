# Automatically generated file, do not edit
SET(BII_IS_DEP False)


# LIBRARY lasote_test_game ##################################
# with interface lasote_test_game_interface

# Source code files of the library
SET(BII_LIB_SRC  game.cpp
			game.h
			save.cpp
			save.h)
# STATIC by default if empty, or SHARED
SET(BII_LIB_TYPE )
# Dependencies to other libraries (user2_block2, user3_blockX)
SET(BII_LIB_DEPS lasote_test_game_interface erincatto_box2d glui_glui sqlite_sqlite)
# System included headers
SET(BII_LIB_SYSTEM_HEADERS iostream stdio.h stdlib.h string)
# Required include paths
SET(BII_LIB_INCLUDE_PATHS )


# Executables to be created
SET(BII_BLOCK_EXES main
			test)

SET(BII_BLOCK_TESTS )


# EXECUTABLE main ##################################

SET(BII_main_SRC main.cpp)
SET(BII_main_DEPS lasote_test_game_interface lasote_test_game)
# System included headers
SET(BII_main_SYSTEM_HEADERS )
# Required include paths
SET(BII_main_INCLUDE_PATHS )


# EXECUTABLE test ##################################

SET(BII_test_SRC test.cpp)
SET(BII_test_DEPS lasote_test_game_interface google_gtest lasote_test_game)
# System included headers
SET(BII_test_SYSTEM_HEADERS stdio.h)
# Required include paths
SET(BII_test_INCLUDE_PATHS )
