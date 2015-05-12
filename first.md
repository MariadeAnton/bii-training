# Using biicode in your projects

Turn your project into a bii-project: 

2 things needed: 

** A specific CMakeLists.txt or biicode.cmake 
* A biicode.conf file

## Write your biicode.conf file: 

``cd`` in your project and ``bii init -L ``
run ``bii deps``
check what's missing -> 
    -> local headers? write [paths] 
    -> external libraries? look for them in biicode and write your dependencies vía [requirements] and [includes] Are you using boost?* 

## Write your build config:

### Without an existing CMakeLists.txt :
    Create a CMakeLists.txt and write in it: 

        ADD_BII_TARGETS()

### With an existing CMakeLists.txt :
   +  Create a biicode.cmake and write in it:

        ADD_BII_TARGETS()

   +  Write in your CMakeLists.txt : 
 
      IF(BIICODE)
          INCLUDE("biicode.cmake")
          RETURN()
      ENDIF()

## Does it build now?

    bii build 

## Build options 

## Handling dependencies

## Publishing

## bii 'n git

* explain how to depend on boost here 
    + easy explanation with header and non header files
    + switching between boost versions
