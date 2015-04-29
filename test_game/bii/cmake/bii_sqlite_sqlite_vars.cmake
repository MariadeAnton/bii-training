# Automatically generated file, do not edit
SET(BII_IS_DEP True)


# LIBRARY sqlite_sqlite ##################################
# with interface sqlite_sqlite_interface

# Source code files of the library
SET(BII_LIB_SRC  sqlite3/sqlite3.c
			sqlite3/sqlite3.h)
# STATIC by default if empty, or SHARED
SET(BII_LIB_TYPE )
# Dependencies to other libraries (user2_block2, user3_blockX)
SET(BII_LIB_DEPS sqlite_sqlite_interface )
# System included headers
SET(BII_LIB_SYSTEM_HEADERS assert.h ctype.h errno.h fcntl.h inttypes.h limits.h malloc.h math.h pthread.h semaphore.h stdarg.h stddef.h stdint.h stdio.h stdlib.h string.h sys/file.h sys/param.h sys/stat.h sys/time.h sys/types.h time.h unistd.h utime.h windows.h)
# Required include paths
SET(BII_LIB_INCLUDE_PATHS )


# Executables to be created
SET(BII_BLOCK_EXES )

SET(BII_BLOCK_TESTS )
