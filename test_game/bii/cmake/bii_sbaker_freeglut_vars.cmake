# Automatically generated file, do not edit
SET(BII_IS_DEP True)


# LIBRARY sbaker_freeglut ##################################
# with interface sbaker_freeglut_interface

# Source code files of the library
SET(BII_LIB_SRC  GL/freeglut.h
			freeglut/freeglut/include/GL/freeglut.h
			freeglut/freeglut/include/GL/freeglut_ext.h
			freeglut/freeglut/include/GL/freeglut_std.h
			freeglut/freeglut/src/egl/fg_init_egl.h
			freeglut/freeglut/src/egl/fg_internal_egl.h
			freeglut/freeglut/src/egl/fg_state_egl.h
			freeglut/freeglut/src/egl/fg_structure_egl.h
			freeglut/freeglut/src/egl/fg_window_egl.h
			freeglut/freeglut/src/fg_callbacks.c
			freeglut/freeglut/src/fg_cursor.c
			freeglut/freeglut/src/fg_display.c
			freeglut/freeglut/src/fg_ext.c
			freeglut/freeglut/src/fg_font.c
			freeglut/freeglut/src/fg_font_data.c
			freeglut/freeglut/src/fg_gamemode.c
			freeglut/freeglut/src/fg_geometry.c
			freeglut/freeglut/src/fg_gl2.c
			freeglut/freeglut/src/fg_gl2.h
			freeglut/freeglut/src/fg_init.c
			freeglut/freeglut/src/fg_init.h
			freeglut/freeglut/src/fg_input_devices.c
			freeglut/freeglut/src/fg_internal.h
			freeglut/freeglut/src/fg_joystick.c
			freeglut/freeglut/src/fg_main.c
			freeglut/freeglut/src/fg_menu.c
			freeglut/freeglut/src/fg_misc.c
			freeglut/freeglut/src/fg_overlay.c
			freeglut/freeglut/src/fg_spaceball.c
			freeglut/freeglut/src/fg_state.c
			freeglut/freeglut/src/fg_stroke_mono_roman.c
			freeglut/freeglut/src/fg_stroke_roman.c
			freeglut/freeglut/src/fg_structure.c
			freeglut/freeglut/src/fg_teapot.c
			freeglut/freeglut/src/fg_teapot_data.h
			freeglut/freeglut/src/fg_version.h
			freeglut/freeglut/src/fg_videoresize.c
			freeglut/freeglut/src/fg_window.c
			freeglut/freeglut/src/gles_stubs.c
			freeglut/freeglut/src/mswin/fg_cursor_mswin.c
			freeglut/freeglut/src/mswin/fg_display_mswin.c
			freeglut/freeglut/src/mswin/fg_ext_mswin.c
			freeglut/freeglut/src/mswin/fg_gamemode_mswin.c
			freeglut/freeglut/src/mswin/fg_init_mswin.c
			freeglut/freeglut/src/mswin/fg_input_devices_mswin.c
			freeglut/freeglut/src/mswin/fg_internal_mswin.h
			freeglut/freeglut/src/mswin/fg_joystick_mswin.c
			freeglut/freeglut/src/mswin/fg_main_mswin.c
			freeglut/freeglut/src/mswin/fg_menu_mswin.c
			freeglut/freeglut/src/mswin/fg_spaceball_mswin.c
			freeglut/freeglut/src/mswin/fg_state_mswin.c
			freeglut/freeglut/src/mswin/fg_structure_mswin.c
			freeglut/freeglut/src/mswin/fg_window_mswin.c
			freeglut/freeglut/src/util/xparsegeometry_repl.c
			freeglut/freeglut/src/util/xparsegeometry_repl.h
			freeglut/freeglut/src/x11/fg_cursor_x11.c
			freeglut/freeglut/src/x11/fg_display_x11_glx.c
			freeglut/freeglut/src/x11/fg_ext_x11.c
			freeglut/freeglut/src/x11/fg_gamemode_x11.c
			freeglut/freeglut/src/x11/fg_glutfont_definitions_x11.c
			freeglut/freeglut/src/x11/fg_init_x11.c
			freeglut/freeglut/src/x11/fg_input_devices_x11.c
			freeglut/freeglut/src/x11/fg_internal_x11.h
			freeglut/freeglut/src/x11/fg_internal_x11_glx.h
			freeglut/freeglut/src/x11/fg_joystick_x11.c
			freeglut/freeglut/src/x11/fg_main_x11.c
			freeglut/freeglut/src/x11/fg_menu_x11.c
			freeglut/freeglut/src/x11/fg_spaceball_x11.c
			freeglut/freeglut/src/x11/fg_state_x11.c
			freeglut/freeglut/src/x11/fg_state_x11_glx.c
			freeglut/freeglut/src/x11/fg_state_x11_glx.h
			freeglut/freeglut/src/x11/fg_structure_x11.c
			freeglut/freeglut/src/x11/fg_window_x11.c
			freeglut/freeglut/src/x11/fg_window_x11_glx.c
			freeglut/freeglut/src/x11/fg_window_x11_glx.h
			freeglut/freeglut/src/x11/fg_xinput_x11.c)
# STATIC by default if empty, or SHARED
SET(BII_LIB_TYPE )
# Dependencies to other libraries (user2_block2, user3_blockX)
SET(BII_LIB_DEPS sbaker_freeglut_interface )
# System included headers
SET(BII_LIB_SYSTEM_HEADERS GL/gl.h GL/glu.h OpenGL/gl.h OpenGL/glu.h errno.h fcntl.h inttypes.h limits.h math.h mmsystem.h regstr.h stdarg.h stdbool.h stdint.h stdio.h stdlib.h string.h sys/param.h sys/time.h sys/types.h tchar.h time.h unistd.h winbase.h windows.h windowsx.h)
# Required include paths
SET(BII_LIB_INCLUDE_PATHS )


# Executables to be created
SET(BII_BLOCK_EXES )

SET(BII_BLOCK_TESTS )
