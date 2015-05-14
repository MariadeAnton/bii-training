# Using biicode in your projects

Turn your project into a bii-project → 3 things needed: 

- ``cd`` in your project and ``bii init -L ``
- A specific CMakeLists.txt or biicode.cmake  
- A biicode.conf file

## biicode.conf and misssing dependencies

Run ``bii deps`` and check what's missing -> 
  
 - local headers? write [paths] 
 - external libraries? look for them in biicode and write your dependencies vía [requirements] and [includes] 
 - Are you using boost? →As boost is huge writing it's dependency 
Use this call better:

bii_find_boost(COMPONENTS thread REQUIRED)

(Thread isn't header only)

Here's the full list with the non header only ones: https://blog.feabhas.com/2015/05/bitesize-modern-c/

## build config

### Without an existing CMakeLists.txt :
  Create a CMakeLists.txt and write in it: 

        ADD_BII_TARGETS()
        

#### Using boost



### With an existing CMakeLists.txt :
   +  Create a biicode.cmake and write in it:

        ADD_BII_TARGETS()

   +  Write in your CMakeLists.txt : 
 
      IF(BIICODE)
          INCLUDE("biicode.cmake")
          RETURN()
      ENDIF()

  + and write your biicode .conf
   
## Does it build now?

    bii build 

## Build options 

## Handling dependencies

## Publishing

## bii 'n git

* explain how to depend on boost here 
    + easy explanation with header and non header files
    + switching between boost versions