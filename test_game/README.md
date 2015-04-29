
lasote/test_game [![Build Status](https://travis-ci.org/lasote/test_game.svg?branch=master)](https://travis-ci.org/lasote/test_game)
=========

Test game is an application that includes BOX2D, GLUI, GLUT, SQLITE AND GOOGLE TEST (GTEST).

Developed with biicode. See http://www.biicode.com for more info.

Its programmed to prove that runs perfectly on Linux, Mac and Windows just writing an include to these libraries.
Can be used as a base to develop a game with these libraries.

Using opening from biicode
--------------

Open the block and build it:

	bii open lasote/test_game
	bii cpp:build
	

Or create a main like this and make 'bii find' and 'bii cpp:build':


    #include "lasote/test_game/game.h"
    
    int main(int argc, char** argv){
        run_game(argc, argv);
        return 0;
    }

License
----
**Open Software, Hell Yeah!**


Github Repository
----

https://github.com/lasote/test_game/tree/master



