# Goals

Wrap X11 C level calls, to look like a normal 2d game engine, with C++14.

## Initial Setup

First things first, start basic a Hello World that calls into the game engine

## Create a XWindow wrapper

It will hide the details of the XWindow system, and allow you to interact without seeing
the low level details of XWindow.

## Inclusion of a UML at this point, I am now in need of organization, beyond simple programs I have written

Within the current directory.

## The Sprite (Core of a game display)

It will contain a Pixmap that represents how it is displayed, and a series of methods to draw on it.

## The Actor (Uses a sprite and may even share them between other Actors)

* Holds a sprite that represents how it displays itself.
* In an update method it will adjust its position and state according to
  {(x, y), (dx, dy), (ddx, ddy)}, obeys bound action as required.

## The Game Abstract class (connects Scene and XWindow)

* Creates the inital window for an implementer (only meant to be implemented once), and connects a default Scene
  or a pointer to a Scene if it is passed.
* Contains the main game loop that executes at the intended framerate

## Create the Screen wrapper as a Scene

A Scene is a wrapper for the X11 Screen that is displayed on the window. Eventually sprites will
be drawn to it and this is the surface that the game code will interact with.

## Timeline

 Deadline  |      Task       | Complete(Y/N)
-----------|-----------------|--------------
2018-11-02 | Initial Setup   |      Y
2018-11-05 | XWindow wrapper |      Y