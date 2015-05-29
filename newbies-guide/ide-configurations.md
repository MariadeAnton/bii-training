IDE configurations
------------------
bii configure
=============
**bii configure -G** command is used to configure your project with cmake to use different compilers.

* You can configure your project to use MinGW compiler:
	
		$ bii configure -G "MinGW Makefiles"

* Or Visual Studio, for example:
		
		$ bii configure -G "Visual Studio 12"
 
Type in your terminal ``cmake --help`` to see available compilers.

Working with no IDE
===================
Default compilers used by biicode are **MinGW** for Windows and **UNIX Makefiles** for both Linux and MacOS. These compilers come with no IDE, so this means there aren't friendly-to-use features like autocompletion.

To develop just fire up your favourite text editor and write code directly.

Working with Visual Studio IDE
==============================
To use VIsual Studio in your project, configure your project for so:

	$ bii configure -G "Visual Studio 12"

Make sure you configure the same version of Visual Studio of the one you have installed in your machine.
You can type ``cmake --help`` in your terminal to see versions:

	$ cmake --help
	  ...
	The following generators are available on this platform:
	  Visual Studio 6             = Generates Visual Studio 6 project files.
	  Visual Studio 7             = Generates Visual Studio .NET 2002 project
	                                files.
	  Visual Studio 10 2010       = Generates Visual Studio 10 (VS 2010) project
	                                files.
	  Visual Studio 11 2012       = Generates Visual Studio 11 (VS 2012) project
	                                files.
	  Visual Studio 12 2013       = Generates Visual Studio 12 (VS 2013) project
	                                files.
	  Visual Studio 7 .NET 2003   = Generates Visual Studio .NET 2003 project
	                                files.
	  Visual Studio 8 2005        = Generates Visual Studio 8 2005 project files.
	  Visual Studio 9 2008        = Generates Visual Studio 9 2008 project files.

Visual Studio solution (.sln) is generated at *build* folder. Open that file with your Visual Studio and you`ll see all projects. Select your project click with right button and select "Set as StartUp project".

Working with other IDEs: Clion & Eclipse
========================================

Clion
-----

Cion is a C++ IDE based on CMake an its CMakelists.txt files, so it is fully compatible with biicode just out-of-the-box.

A different **layout** is needed, yo instead of **bii init -L**, you should use **bii init -l=clion**.

Now, open Clion and go to File->Open and select project's folder.

Your code needs to be placed at *your_project/blocks/your_user/block_name*!

This is how the clion layout looks:

	+-- myproject/
	|    +-- bii/
	|    +-- bin/
	|    +-- bin/
	|    +-- blocks/
	|    |    +-- owner1/
	|    |    |    +-- blockA/
    |    |    |    |    +-- biicode.conf
    |    |    |    |    +-- CMakeLists.txt
    |    +-- deps/
	|    +-- biicode.cmake
	|    +-- CMakeLists.txt

Eclipse
-------

To create an Eclipse CDT project, run:

* Linus/MacOS users:

	$ bii configure -G "Eclipse CDT4 - Unix Makefiles"

* Windows users:

	$ bii configure -G "Eclipse CDT4 - MinGW Makefiles"


1.- From the main Eclipse menu choose: *File > import...*

2.- Now, select *general > Existing Projects into Workspace*, and click **Next**.

3.- Select the root directory as the root folder of your project.

4.- You should see a project already selected in the projects box. Click **Finish**.

If you want to add new files to your block, just *right-click on the folder of your block* and create a **new file**.

You can build your application in **Project > Build project**.