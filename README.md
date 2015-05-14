# Alternative - Getting started

## Welcome to biicode

Biicode manages your project's dependencies so you can use the libs you need (Curl, Catch, Fann, OpenSSL, OpenCV, Poco, Boost, Libuv, GTest ...) as you wish within your project. Biicode uses CMake to configure and build your projects and it is compatible with many IDEs and version control systems.

This guide will help you get your first biicode block off the ground.

## Basics

Make sure biicode is installed. 

Run ``bii setup:cpp`` to ensure you've got all tools required. 

Note: don't install MinGW if you already got other compiler (Clang, Visual Studio...)

## Create your first project

### Create a sample project

Create a project with this sample code in it:

    mkdir hola
    cd hola
    echo "//main.cpp code goes here" >> main.cpp

Place your code into the main.cpp file -> I'm using this OpenSSL example code:

	#include "openssl/md5.h"
	#include <stdio.h>
	#include <string.h>
	 
	int main()
	{
	    unsigned char digest[MD5_DIGEST_LENGTH];
	    char string[] = "happy";
	    
	    MD5((unsigned char*)&string, strlen(string), (unsigned char*)&digest);    
	 
	    char mdString[33];
	 
	    for(int i = 0; i < 16; i++)
		 sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	 
	    printf("md5 digest: %s\n", mdString);
	 
	    return 0;
	}

### biicodize your project

Run ``bii init -L`` in your project, this turns your project into a biicode block. It creates two auxiliary folders *bii* and *bin* which you can ignore if you're using git or any other version control system.

Create a *biicode.conf* file → bii's dependencies info (but boost's*) will go here!

Search OpenSSL in the web, you can see there's a lasote/openssl block whose latest version is 3 tagged DEV:

![](https://github.com/MariadeAnton/bii-training/blob/master/_img/openssl_md5.png)

Copy the include you see in the image ``#include "lasote/openssl/include/openssl/md5.h"`` and split it in two halfs to write in your *biicode.conf* which openssl block you want to use.

	[requirements]
	     lasote/openssl: 2
	
	[includes]
	    openssl/md5.h: lasote/openssl/include
	

You can also use patterns:
	
	[includes]
	    openssl/*.h: lasote/openssl/include

## Build and run it

Build your project:

	bii build

Using an IDE? 
biicode configures your default settings to no IDE and MinGW (Windows) or UNIX Makefiles (MacOS and Linux). Change this settings, run bii configure before bii build:

	bii configure -G "Visual Studio 10"
	bii build

**Note that CLion and Eclipse need a special kind of project to be compatible. Read it here (link soon)

Run it:

	bin/user_hola_main

Linux/Mac users might run as:

	./bin/user_hola_main

Expected output - similar to this one:

	md5 digest: b5f9c8ffcccde4e7e17e0059840a6b43


# Publishing

Publish to make your libs available in biicode.

Run $ bii user your_username.

	bii publish
	Please enter a password for "your_username" account: XXXXXXXXX
	INFO: *****************************
	INFO: ***** Publishing public ****
	INFO: *****************************
	INFO: Successfully published your_username/hola: 0

Go to your profile at www.biicode.com/your_username and check your new block!

You can also:
    - Log in to edit the block's web description. 
    - Make it private with a premium account! 

Take a look into your block's biicode.conf file (~/hola/biicode.conf). [parent] section tells you "who is your parent version", the latest published version of your block and looks like this:

	[parent]
	   your_username/hola: 0

Celebrate! You've just published your first block. 

Here are some [examples depending on some popular libraries available](http://docs.biicode.com/c++/examples.html). 

You know that we are available at biicode forum for any issues. You can also write us at support@biicode.com for suggestions and feedback.
