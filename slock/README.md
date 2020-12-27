slock - simple screen locker
============================
simple screen locker utility for X. 


Requirements
------------
In order to build slock you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (slock is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install slock
(if necessary as root):

    make clean install


Running slock
-------------
Simply invoke the 'slock' command. To get out of it, enter your password.

# Patches Applied

| Patch | Purpose |
| ----- | ------- |
| [Blured or pixelated screenshot](https://tools.suckless.org/slock/patches/blur-pixelated-screen/) | This patch sets the lockscreen picture to a blured or pixelated screenshot. Inspired by i3lock-fancy |
