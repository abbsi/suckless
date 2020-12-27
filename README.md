# TODO
+ Re-expand `config.def.h` to the full setup without the application rules

# DWM Build

This is a heavily patched DWM 6.2 that suits how I like to work with it. Working with Arch Linux and package dependencies may vary. To help improve this setup, please post any issues mentioning any dependency failures.

Few quirks to keep note off:
* Make sure your text editor is using a nerd font to see the tag labels
+ If you customize the layout labels (which use nerd font icon), then you may need to edit the icons in `dwm.c` in some of the layout functions where the nmaster value is printed
  + Example: changing this `{ "  ", monocle },` in `config.h` will need you to change this line in `dwm.c` around line 1500: `snprintf(m->ltsymbol, sizeof m->ltsymbol, " %d", n);`
  + You can also just delete that delete and the preceding if statement
  + Will look into dynamically pulling the current icon and adding nmaster value to it
+ Uses a good number of scripts that depend on rofi. So before building and running make sure you have it installed, along dmenu as a backup
+ Tile layout gaps is a little broken in edge cases
+ Other layouts don't have consistent gaps, will fix at some point
+ Status bars deal with padding in different ways. You will need to adjust script outputs by adding/removing trailing spaces either in the config.h files (slstatus or dwmblocks) or in the script outputs
+ You can enable/disable layouts by commenting them out. However, in the key bindings section, reorder the lines and define the correct index.

## Screen Shots

### DWM with no Status Bar
![Default DWM](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-default.jpg)

### DWM with Polybar
![DWM with Polybar](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-with-polybar.jpg)

### DWM with DWM Blocks
![DWM with DWM Blocks](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-with-blocks.jpg)

### DWM with slstatus
![DWM with slstatus](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-with-slstatus.jpg)

## Quick Guide

### Dependencies
#### config.def.h Dependencies (to be verified on a clean install)
+ dmenu
+ libxft-bgra
+ For IPC Patch: yajl, jsoncpp
+ Nerd Fonts Complete and Source Code Pro font
+ tabbed (not using, seems like when used with alacritty and fish shell, a memory leak occurs with fish eating up all RAM)
+ slock
+ [Alacritty Terminal](https://github.com/alacritty/alacritty)
+ [dmenu](https://tools.suckless.org/dmenu/)
+ [Polybar DWM Module](https://github.com/mihirlad55/polybar-dwm-module)
  + This replaces polybar which includes a dwm module
+ In `autostart.sh`
  + nitrogen
  + picom
  + numlockx
  + dunst
  + dwmblocks (optional)
  + slstatus (optional)

##### Additional config.h Dependencies
+ [rofi](https://github.com/davatorium/rofi) (see dot files for scripts)
+ [pavolume](https://github.com/sseemayer/pavolume)
+ scrot
+ playerctl

### Build & Run

1. Decide if you want to use my `config.h` or start from scratch using `config.def.h`
   + Delete `config.h` If you want to start from `config.def.h`
   + Try to leave `config.def.h` intact unless you further patch DWM. If a patch modifies `config.h` then apply the change to `config.def.h`
2. Choose if you want to use polybar or a DWM Bar
   + Change `static const int usealtbar = 0;`. 1 to use polybar and 0 to use DWM's Bar
   + If not using polybar, you will need to select a status bar in `autostart.sh`
   + I suggest you start with slstatus. Get that working then move on Polybar if needed. Polybar setup and configuration are in my dotfiles repository
3. Compile and Install
   ```
   make clean
   make
   sudo make install
   ```
4. Copy scripts into a directory in your PATH. Scripts can be found under 'bin' in my [dotfiles repository](https://github.com/abbsi/dotfiles/tree/main/bin)
5. Check dwm.desktop went to the right place for you display manager to pick it up as an available sessions. e.g. `/usr/share/xsessions`
6. Run DWM 

### Troubleshooting
+ When you first run dwm, you may see artifacts in the background as you open and close applications. Make sure you have picom installed and running through the `autostart.sh` or run it yourself from a terminal
+ Use feh or nitrogen to setup a background
  + `feh --bg-scale /path/to/wallpaper.png`
+ ModKey+Shift+Q to quit DWM
+ You can edit the config.h, recompile and restart DWM without quiting through ModKey+Shift+R

### File Location and Quicktips

+ Place `autostart.sh` in `~/.dwm/` 
+ Place scripts from my dotfiles `bin` into a directory with your path
+ Check `/usr/share/xsessions` and verify that `dwm.desktop` is there

# Patches Applied

## General

| Patch | Purpose |
| ----- | ------- |
| [Auto Start](https://dwm.suckless.org/patches/autostart/) | makes dwm run `~/.dwm/autostart_blocking.sh` and `~/.dwm/autostart.sh &` on startup |
| [Static Status](https://dwm.suckless.org/patches/staticstatus/)  | allows the status text to be fixed to the bar on a specific monitor rather than being drawn on the focused monitor. Update `staticmonval` to select monitor |
| [Restart Signal](https://dwm.suckless.org/patches/restartsig/) | adds a keyboard shortcut to restart dwm or alternatively by using `kill -HUP dwmpid` and additionally dwm can quit cleanly by using `kill -TERM dwmpid` |

## Appearance

+ Useless gap patch was modified to keep gaps and borders around tags with single clients
+ Applied tilegap patch and modified to match column layout spacing. Layouts are exactly the same until you increment the `nmaster` value.
  + TODO: When `nmaster` is 0, add `gappx` to x postion and remove from width
  + TODO: When `nmaster` > number of clients, add `gappx` to width

| Patch | Purpose |
| ----- | ------- |
| [Alpha](https://dwm.suckless.org/patches/alpha) | adds transparency for the status bar and borders |
| [Color Bar](https://dwm.suckless.org/patches/colorbar/) | lets you change the foreground and background color of every statusbar element |
| [Status Padding](https://dwm.suckless.org/patches/statuspadding/) | adds configuration options for horizontal and vertical padding in the status bar |
| [Status Colors](https://dwm.suckless.org/patches/statuscolors/) | enables colored text in the status bar allowing multiple color combinations for use in the status script |
| [Useless Gap*](https://dwm.suckless.org/patches/uselessgap/) | adds "useless gaps" around windows |
| [Tile Gap*](https://dwm.suckless.org/patches/tilegap/) | The same size gap between master and stack, window and window, and window and screen edge ... modified heavily, and probably incorrectly |
| [Decor Hints](https://dwm.suckless.org/patches/decoration_hints/) | Make dwm respect _MOTIF_WM_HINTS property, and not draw borders around windows requesting for it. Some applications use this property to notify window managers to not draw window decorations. |
| [Reorganize Tags](https://dwm.suckless.org/patches/reorganizetags/) | Shifts all clients per tag to leftmost unoccupied tags. |


## Tag Management
+ Client indicator patch has modified dimensions for visibility and added `showclientind` to config.def.h/config.h to turn on/off Client indicators patch

| Patch | Purpose |
| ----- | ------- |
| [Alternative Tags](https://dwm.suckless.org/patches/alternativetags/) | adds alternative tags which can be toggled on the fly for the sole purpose of providing visual aid |
| [Alternative Tags Decoration](https://dwm.suckless.org/patches/alttagsdecoration/) | provides the ability to use alternative text for tags which contain at least one window |
| [Client Indicators*](https://dwm.suckless.org/patches/clientindicators/) | draws a dot indicator overlayed on each tag icon for each client, the selected client is drawn as a larger horizontal line<br> With client indicators: ![](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-client-ind.png) <br> Without client indicators: ![](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-no-client-ind.png) |
| [Pertag](https://dwm.suckless.org/patches/pertag/) | adds nmaster, mfact, layouts and more per tag rather than per monitor |
| [Switch to Tag](https://dwm.suckless.org/patches/switchtotag/)  | TODO: Fix for Multi monitor setup and cancel switching back (or some other patch is conflicting). Works well in a single monitor setup |
| [Focus Urgent](https://dwm.suckless.org/patches/focusurgent/)  | TODO: find monitor with urgent client and focus there first |
| [TODO: Switch to Urgent] | Look into finding/creating path to switch to urgent

## Layouts
+ TODO: Fix fibonacci layouts spacing
+ TODO: Fix bstack stack client X and Width

| Patch | Purpose |
| ----- | ------- |
| [Bottom Stack (bstack and bstackhoriz)](https://dwm.suckless.org/patches/bottomstack/) | Bottom Stack layout and Bottom Stack Horizontal |
| [Columns](https://dwm.suckless.org/patches/columns/) | same as the default tile layout except clients in the master area are arranged in columns (i.e. left to right) |
| [Fibonacci (Spiral and Dwindle)](https://dwm.suckless.org/patches/fibonacci/) | fibonacci (dwindle and spiral) layouts |
| [Grid](https://dwm.suckless.org/patches/gridmode/) | gridmode (grid) layout |
| [Save Floats](https://dwm.suckless.org/patches/save_floats/) | Saves size and position of every floating window before it is forced into tiled mode. If the window is made floating again, the old dimensions will be restored. |

## Layout Management

| Patch | Purpose |
| ----- | ------- |
| [Cycle Layouts](https://dwm.suckless.org/patches/cyclelayouts/) | lets you cycle through all your layouts |
| [Attach Direction](https://dwm.suckless.org/patches/attachdirection/) | Single patch allowing attaching above, aside, below, bottom and top. To switch between the behaviors change the value of `attachdirection` in config. For default behavior leave it at 0 |
| [Always Center](https://dwm.suckless.org/patches/alwayscenter/) | All floating windows are centered, like the center patch, but without a rule. Some applications were spawning floating dialogs outside the monitor.   |
| [Rotate Stack](https://dwm.suckless.org/patches/rotatestack/) | let's you rotate through the stack using keyboard shortcuts |

## Polybar Integration and IPC

+ [1.5.7](https://github.com/mihirlad55/dwm-ipc/releases/tag/v1.5.7) Applied
+ See Also https://dwm.suckless.org/patches/ipc/

| Patch | Purpose |
| ----- | ------- |
| [Any Bar & Polybar tray fix](https://dwm.suckless.org/patches/anybar/) | enables dwm to manage external status bars such as lemonbar and polybar | 
| [DWM IPC (1.5.7)](https://github.com/mihirlad55/dwm-ipc) | implements inter-process communication through a UNIX socket for dwm | 

## Additional Customizations to Patches Above
+ Some layouts add the value of `nmaster` to the layut tag (Similar to monocle Count)
+ Extra color schemes for use with slstatus