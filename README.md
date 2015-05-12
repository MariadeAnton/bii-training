#Getting started @ ETSIDI

## Welcome to biicode

Biicode manages your project's dependencies so you can use the libs you need (Curl, Catch, Fann, OpenSSL, OpenCV, Poco, Boost, Libuv, GTest ...) as you wish within your project. Biicode uses CMake to configure and build your projects and it is compatible with many IDEs and version control systems.

This guide will help you get your first biicode block off the ground. Let's run a block with a unit test using the ptypes block in biicode. There's no need to install OpenSSL, biicode downloads and configures it for you, OpenSSL is already in biicode!

## Basics

Make sure biicode is installed. Open the terminal and execute bii setup:cpp to ensure you've got all tools required.

## Create your first project

bii init -L a folder to create a new project. The command below creates and inits unit_test/ folder as a biicode project containing a block.

	~$ bii init hola -L
	~$ cd hola
	~/hola$ #create a main.cpp
	~/hola$ echo "//main.cpp code goes here" >> main.cpp

Create a main.cpp into hola/ folder.
Place this code into the main.cpp file:

	#include "lasote/openssl/include/openssl/md5.h"
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


The #include is composed as #include <biicode_user>/<block_name>/path/to/file. In this case, it #includes the openssl/md5.h header from OpenSSL block and user lasote.

In the web, you see its latest version is 3 tagged DEV and 2 STABLE:

![](https://github.com/MariadeAnton/bii-training/blob/master/_img/openssl_md5.png)

Retrieve the dependency:

	~$ bii find
	...

	INFO: Analyzing compatibility for found dependencies...
	INFO: All dependencies resolved
	Find resolved new dependencies:
	  lasote/openssl: 2
	INFO: Saving files from: lasote/openssl

	bii find creates a biicode.conf file and downloads GoogleTest block into your bii/deps folder:

	unit_test/
	      ├── bii/
	      │   ├── deps/
	      │   │   └── lasote/
	      │   │       └── openssl/
	      ├── biicode.conf
	      └── main.cpp

[optional] Keeping #includes short

Keep reading to see how to keep your #includes as usual. You can also :ref:`skip this section.<cpp_run>`

Instead of using long #includes, you can write the specs to retrieve this dependency in your biicode.conf.

Split the long #include "lasote/openssl/include/openssl/md5.h" in two halfs:

	[requirements]
	     lasote/openssl: 2
	
	[includes]
	    openssl/md5.h: lasote/openssl/include
	
You can also use patterns:
	
	[includes]
	    openssl/*.h: lasote/openssl/include

Build and run it

Build and run your Unit Test, check it works:

	~/hola$ bii build
	...
	~/hola$ bin/user_hola_main

	md5 digest: b5f9c8ffcccde4e7e17e0059840a6b43

Linux/Mac users might run as:

	~/hola$ ./bin/user_hola_main

That's it, that output means OpenSSL was downloaded, configured and built in your project!

Congrats! You have just used OpenSSL within your project. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feedback.
Using an IDE

biicode configures your default settings to no IDE and MinGW (Windows) or UNIX Makefiles (MacOS and Linux). You can change these values executing bii configure before bii build:

	~/unit_test$ bii configure -G "Visual Studio 10"
	~/unit_test$ bii build

# Publishing

Publish to make your libs available in biicode.

        Execute $ bii user your_username.

	~/unit_test$ bii publish
	
	INFO: *****************************
	INFO: ***** Publishing public ****
	INFO: *****************************
	INFO: Successfully published your_username/hola: 0

Go to your profile at www.biicode.com/your_username to check what you've just uploaded.

    - Log in to edit the block's web description.
    - Make sure you've got an account to publish. It's free.

Take a look into your block's biicode.conf file (~/hola/biicode.conf). [parent] section tells you "who is your parent version", the latest published version of your block and looks like this:

	[parent]
	   your_username/hola: 0

Celebrate! You've just published your first block in biicode. You know that we are available at biicode forum for any issues. You can also write us at support@biicode.com for suggestions and feedback.
