# Deeper into biicode 

When you're dealing with a heavy library - what to do!

This might be kinda tricky so you may wanna spend some time understanding:

 - [CMake basics](http://docs.biicode.com/c++/building.html)
 - [Where is biicode's magic?](http://docs.biicode.com/c++/building/biicode_building.html)
 - [Adapt your library full guides](http://docs.biicode.com/c++/adapt_library_guide.html)

Tests - there's a section in the biicode.conf file to cover the tests, just write the tests files or paths:

      [tests]
        projects/SelfTest/*
        tests/unit_ test.cpp

Run ``bii test`` to run them! 

Note: ``bii build`` does not compile the tests included in [tests] section.

# Using custom toolchains

Name your custom toolchain: *name-toolchain.cmake* (none, rpi and arduino are already taken!)

Place the toolchain into bii/ folder. 

``bii configure -t name``  to use it, and then ``bii build``.

Run ``bii configure -t`` to get back to the native environment.

There are also a couple custom toolchains available for:

- Arduino:
      
      bii arduino:settings
      bii configure -t arduino

- Raspberri PI:
    
      bii rip: settings
      bii configure -t rpi

# Overriding dependencies

# Overriding build config