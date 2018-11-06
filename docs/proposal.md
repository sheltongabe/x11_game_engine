# Goals

Wrap X11 C level calls, to look like a normal 2d game engine, with C++14.

## Initial Setup

First things first, start basic a Hello World that calls into the game engine

## Create a XWindow wrapper

It will hide the details of the XWindow system, and allow you to interact without seeing
the low level details of XWindow.

## Create the Screen wrapper as a Scene

A Scene is a wrapper for the X11 Screen that is displayed on the window. Eventually sprites will
be drawn to it and this is the surface that the game code will interact with.

## The Game Abstract class (connects Scene and XWindow)

* Creates the inital window for an implementer (only meant to be implemented once), and connects a default Scene
  or a pointer to a Scene if it is passed.
* Contains the main game loop that executes at the intended framerate

## Timeline

 Deadline  |      Task       | Complete(Y/N)
-----------|-----------------|--------------
2018-11-02 | Initial Setup   |      Y
2018-11-05 | XWindow wrapper |      Y