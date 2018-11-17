# x11_game_engine

Wrap X11 C level calls, to look like a normal 2d game engine, with C++14.

## Status V0.1

It is not currently at a compiling / running state, apologies for it being in master.
I am still heavily in a refactoring stage.

## Install, Compile, and Run

1. Install
   * Simply clone this repository, and ensure the system you are running it on has Xorg / Xlib, preferably X11
   * `git clone https://github.com/sheltongabe/x11_game_engine.git`
2. Compile
   * Make a directory within the repository called build, this will host all of the build files
   * Then from within the build/ directory run cmake .. && make
   * `cd x11_game_engine && mkdir build/`
   * `cd build && cmake .. && make`
3. Run
   * By default the CMakeLists.txt in the root of the project will generate tests,
     you can disable this by commenting out those lines
   * But because of this you have an executable that you can run to demonstrate the game engine works,
     and to test various parts.
   * The source code for this executable is in test/src and test/include, and the executable is in the bin/ folder
   * The static library is in the lib/ folder
   * But you can test the test executable that is linked to the game engine library by going into the bin/ folder
   * `cd bin/ && ./x11_game_engine_test`
   * And you can also run valgrind against it of course, right now I have been struggling to free colors so, it
     always leaks 180 bytes due to that.