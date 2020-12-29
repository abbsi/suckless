# st - simple terminal
st is a simple terminal emulator for X which sucks less.

# Requirements
In order to build st you need the Xlib header files.

# Installation
Edit config.mk to match your local setup (st is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install st (if
necessary as root):

    make clean install

# Running st
If you did not install st with make clean install, you must compile
the st terminfo entry with the following command:

    tic -sx st.info

See the man page for additional details.

# Credits

Based on Aurélien APTEL <aurelien dot aptel at gmail dot com> bt source code.

# Patches Applied

## Alpha + Focus
+ https://st.suckless.org/patches/alpha_focus_highlight/
+ Allows users to change the opacity of the background and allows the user to specify two distinct opacity values / background colors; one for the focused- and one for unfocused windows' background. This enables the user to spot the focused window at a glance. The patch is based on the alpha patch; i.e. is to be applied after applying the alpha patch.

## Selection Colors 
+ https://st.suckless.org/patches/selectioncolors/
+ Adds the two color-settings selectionfg and selectionbg to config.def.h. Those define the fore- and background colors which are used when text on the screen is selected with the mouse. This removes the default behaviour which would simply reverse the colors.

## Delkey
+ https://st.suckless.org/patches/delkey/
+ Return BS on pressing backspace and DEL on pressing the delete key.

## Scrollback Pacthes (x3)
+ https://st.suckless.org/patches/scrollback/
  + Main Patch: Scroll back through terminal output using Shift+{PageUp, PageDown}
  + Mouse: allow scrolling using Shift+MouseWheel
  + Mouse Increment: allow changing how fast the mouse scrolls

## Box Draw
+ https://st.suckless.org/patches/boxdraw/
+ Custom rendering of lines/blocks/braille characters for gapless alignment

## Any Size
+ https://st.suckless.org/patches/anysize/
+ Allows st to resize to any pixel size, makes the inner border size dynamic, and centers the content of the terminal so that the left/right and top/bottom borders are balanced. With this patch, st on a tiling WM will always fill the entire space allocated to it.

## X Resources
+ https://st.suckless.org/patches/xresources/
+ Adds the ability to configure st via Xresources. At startup, st will read and apply the resources named in the resources[] array in config.h

## Blinking Cursor
+ https://st.suckless.org/patches/blinking_cursor/
+ Allows the use of a blinking cursor

## Vertical Center
+ https://st.suckless.org/patches/vertcenter/
+ Vertically center lines in the space available if you have set a larger chscale in config.h

## X Clear Win
+ https://st.suckless.org/patches/xclearwin/
+ When an OCS sequence was used to change the bg color, the borders where dirty. This simple patch just clears the window before the redraw of the terminal when the bg color has been changed. This is apparently smooth and solves the problem.

## Desktop Entry
+ https://st.suckless.org/patches/desktopentry/
+ Creates a desktop-entry for st. This enables to find st in a graphical menu and to display it with a nice icon.
