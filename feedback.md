# Feedback

- What do biicode builds refer to? the source code repo for the lib? 
- How to express a header only project or header only files (see catch and fit)
- How to build with the desired toolchain ->
    setting the CXX environment variable when run "bii configure".
- Building OSS biicode -> troubles with pygraph
- CLions example doesn't work cause they use the other layout and don't specify where to place the code.
    + It's in blocks/username/blockname <- there
 http://blog.jetbrains.com/clion/2015/03/when-clion-met-biicode/ 

- info about bii init -L and bii init (the differences)
- What is a biicode block? What does it contain?
- How do I use a biicode block? Both with an existing CMakeLists.txt or without an existing CMakeLists.txt.
- How do I convert a project into biicode compatible? This is already covered but I somehow feel it is not easily understandable/readable.
- How do I add missing dependency?
- How do I remove unnecessary/platform specific dependency?
- How do I exclude file/directory?
- Using boost 
- Publishing usable biicode blocks -> steps to go after creating bii config file
- bii saves boost and opencv at -biicode -> regular dependencies are downloaded into your project's deps folder, but once you've used a specific version, biicode caches it so you don't need internet the next time
- bii overrides modifications at deps folder whenever you run a new command: bii downloads original file from internet automatically. Ways to proceed:
    + make a block track and override the dependency
    + use the multiple project's layout, this way when you open a block, you can code in it as if it was yours and changes will be reflected in your code at build time. 
        A small example:
        ```
        bii init myproject
        cd myproject
        mkdir blocks/username/block_name
        cd blocks/username/block_name 
        # place your code there and then:
        bii open owner/block  #your dependency block
        ```
- Can we host our private biicode repo?
- transforming existing projects into the biicode format
- accents in folder paths
- Making my own biicode build 
- options available to install - add chocolatey explanations to docs
- does bii replace a git repository? does this replace build system like cmake?
    + No, to both - but it's confusing -> explain the differences!
- how to migrate things to biicode
- biicode + github -> .gitignore file :) 