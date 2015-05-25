How to start a project
----------------------

bii init
========

**bii init myproject** creates a [Classic folder layout](http://docs.biicode.com/c++/advanced/project.html#classic-layout) to develop one or more blocks inside it, what is called "project". To add your .cpp and .h files, type [**bii new *your_username/name_of_your_block***](http://docs.biicode.com/c++/reference/commands/new.html), so a "block" is where your code is placed and it is what you can find at biicode.com.

	+-- myproject/
	|    +-- bii/
	|    |    +-- policies.bii
	|    |    +-- settings.bii
	|    +-- blocks/
	|    |    +-- your_username/
	|    |    |    +-- name_of_your_block/
	|    |    |    |    +-- main.cpp

bii init -L
===========

With **bii init myblock -L** command, you can start a project with [simple layout](http://docs.biicode.com/c++/advanced/project.html#simple-layout), which means that block create the block directly with the name given. Header and source files are placed at "myblock" folder. This way you can initialize an existing project to work with biicode, just enter in your normal project folder and do **bii init -L**.

	+-- myblock/
	|    +-- bii/
	|    |    +-- layout.bii
	|    |    +-- policies.bii
	|    |    +-- settings.bii
	|    |    +-- build/
	|    |    +-- cmake/
	|    |    +-- deps/
	|    +-- bin/
	|    +-- main.cpp
	|    +-- biicode.conf
	|    +-- CMakeLists.txt

Above you see a simple project layout with some folders and files inside.

Structure: own folders and biicode folders
==========================================

* **bii** : Stores configuration files for biicode to work and some other useful folders.
 * **build**: Stores configuration files from your own code. Here you'll find Visual Studio solutions or Makefiles with some other cmake files needed.
 * **cmake**: cmake files used in the configuration and link of the source code.
 * **deps**: Here you'll find dependencies retrieved at biicode database following *user_name/block_name* path.
* **bin**: Where compiled binaries are stored. Here you can find your executables and auxiliary files needed at runtime.
* **myblock**: Here yo can place your code next to *biicode.conf* and *CMakeLists.txt* with any structure folder you want. For example, I can have my own block structure with .cpp files placed at src and .h files placed at include folder:

	    +-- myblock/
	    |    +-- bii/
	    |    |    +-- layout.bii
	    |    |    +-- policies.bii
	    |    |    +-- settings.bii
	    |    |    +-- build/
	    |    |    +-- cmake/
	    |    |    +-- deps/	
	    |    +-- bin/
	    |    +-- include/
	    |    |    +-- header.h
	    |    +-- src/
	    |    |    +-- main.cpp
	    |    +-- biicode.conf
	    |    +-- CMakeLists.txt

