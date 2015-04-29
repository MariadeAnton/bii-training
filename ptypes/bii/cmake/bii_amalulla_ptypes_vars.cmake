# Automatically generated file, do not edit
SET(BII_IS_DEP False)


# LIBRARY amalulla_ptypes ##################################
# with interface amalulla_ptypes_interface

# Source code files of the library
SET(BII_LIB_SRC  )
# STATIC by default if empty, or SHARED
SET(BII_LIB_TYPE )
# Dependencies to other libraries (user2_block2, user3_blockX)
SET(BII_LIB_DEPS amalulla_ptypes_interface )
# System included headers
SET(BII_LIB_SYSTEM_HEADERS )
# Required include paths
SET(BII_LIB_INCLUDE_PATHS )


# Executables to be created
SET(BII_BLOCK_EXES stream)

SET(BII_BLOCK_TESTS )


# EXECUTABLE stream ##################################

SET(BII_stream_SRC stream.cpp)
SET(BII_stream_DEPS amalulla_ptypes_interface melikyan_ptypes)
# System included headers
SET(BII_stream_SYSTEM_HEADERS )
# Required include paths
SET(BII_stream_INCLUDE_PATHS )
