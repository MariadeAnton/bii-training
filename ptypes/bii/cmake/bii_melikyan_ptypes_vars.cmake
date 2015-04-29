# Automatically generated file, do not edit
SET(BII_IS_DEP True)


# LIBRARY melikyan_ptypes ##################################
# with interface melikyan_ptypes_interface

# Source code files of the library
SET(BII_LIB_SRC  include/pasync.h
			include/pinet.h
			include/pport.h
			include/pstreams.h
			include/ptime.h
			include/ptypes.h
			src/pasync.cxx
			src/patomic.cxx
			src/pcomponent.cxx
			src/pcset.cxx
			src/pcsetdbg.cxx
			src/pexcept.cxx
			src/pfatal.cxx
			src/pfdxstm.cxx
			src/pinfile.cxx
			src/pinfilter.cxx
			src/pinmem.cxx
			src/pinstm.cxx
			src/pintee.cxx
			src/piobase.cxx
			src/pipbase.cxx
			src/pipmsg.cxx
			src/pipmsgsv.cxx
			src/pipstm.cxx
			src/pipstmsv.cxx
			src/pipsvbase.cxx
			src/pmd5.cxx
			src/pmem.cxx
			src/pmsgq.cxx
			src/pmtxtable.cxx
			src/pnpipe.cxx
			src/pnpserver.cxx
			src/pobjlist.cxx
			src/poutfile.cxx
			src/poutfilter.cxx
			src/poutmem.cxx
			src/poutstm.cxx
			src/ppipe.cxx
			src/ppodlist.cxx
			src/pputf.cxx
			src/prwlock.cxx
			src/psemaphore.cxx
			src/pstdio.cxx
			src/pstrcase.cxx
			src/pstrconv.cxx
			src/pstring.cxx
			src/pstrlist.cxx
			src/pstrmanip.cxx
			src/pstrtoi.cxx
			src/pstrutils.cxx
			src/ptextmap.cxx
			src/pthread.cxx
			src/ptime.cxx
			src/ptimedsem.cxx
			src/ptrigger.cxx
			src/punit.cxx
			src/punknown.cxx
			src/pvariant.cxx
			src/pversion.cxx)
# STATIC by default if empty, or SHARED
SET(BII_LIB_TYPE )
# Dependencies to other libraries (user2_block2, user3_blockX)
SET(BII_LIB_DEPS melikyan_ptypes_interface )
# System included headers
SET(BII_LIB_SYSTEM_HEADERS errno.h fcntl.h limits.h process.h pthread.h semaphore.h signal.h stdarg.h stdint.h stdio.h stdlib.h string.h sys/time.h sys/types.h time.h unistd.h windows.h winsock2.h)
# Required include paths
SET(BII_LIB_INCLUDE_PATHS )


# Executables to be created
SET(BII_BLOCK_EXES )

SET(BII_BLOCK_TESTS )
