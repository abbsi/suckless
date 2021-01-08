
> Important:
> + The current `config.h` is applicable to my setup and my key bindings. It is how I am used to it and combined with scripts from my dot files which need to be in your path
> + `config.def.h` is a somewhat 'vanilla' config but with all patches applied and less dependencies.
>   + I suggest you delete/move my config.h out of the directory and use it as a reference if you wish.
>   + After you delete/move `config.h` out and  running `make` will copy `config.def.h` to a new `config.h` which you can start to customize

# Screen Shots

## DWM with no Status Bar
![Default DWM](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-default.jpg)

## DWM with Polybar
![DWM with Polybar](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-with-polybar.jpg)

## DWM with DWM Blocks
![DWM with DWM Blocks](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-with-blocks.jpg)

## DWM with slstatus
![DWM with slstatus](https://raw.githubusercontent.com/abbsi/suckless/main/screenshots/dwm-with-slstatus.jpg)

# Guide

> + Based on Arch
> + This will overwrite dwm if installed through pacman. I have added an option in `config.mk` to customize the binary name. See below

1. Install dependencies 
    
        $ sudo pacman -Syu yajl picom nitrogen numlockx dunst
        $ yay -S libxft-bgra
    
2. Clone this repository
    
        $ git clone https://github.com/abbsi/suckless.git
        
3. In the `dwm` directory
   + Decide if you want to use the existing `config.h` or start from the default `config.def.h`
     + If from default then  `$ mv config.h config.h.abbsi`
   + Edit and customize `config.def.h`
     + Set `static const int usealtbar = 0;` to `0`
     + Check that `static const int statmonval = 0;` is set to 0. Non zero value with a single monitor setup will crash DWM
     + Choose your preferred attached method `static const int attachdirection = 0;`
     + Enable/disable layouts, and ensure that the Key Maps have the right index numbers
   + Edit `config.mk` to match your environment
     + You can also add a custom name after `CUSTOMNAME` to setup multiple installations with different configurations
   + Ensure that all key mapped commands link to binaries or scripts in your path or replace commands with your own
        ```
        sudo make clean install
        mkdir ~/.dwm
        cp autostart.sh ~/.dwm/ 
        ```
4. Check dwm.desktop went to the right place for your display manager to pick it up as an available session. e.g. `/usr/share/xsessions`
5. In the `dmenu` directory
    
        sudo make clean install 

## Tips
+ When you first run dwm, you may see artifacts in the background as you open and close applications. Make sure you have *picom* installed and running through the `autostart.sh` or run it yourself from a terminal.
+ Try to use a nerd-font without mono space. Monospaced font will make the icons much smaller.
+ Use *feh* or *nitrogen* to setup a background. e.g. `feh --bg-scale /path/to/wallpaper.png`
+ *ModKey+Shift+Q* to quit DWM
+ *ModKey+Shift+Control+Q* to restart DWM (leaves all your current windows open)
+ You can edit the `config.h`, recompile and restart DWM without quiting

# Additional Notes

This is a heavily patched DWM 6.2 that suits how I like to work with it. Tried it on two Arch Linux setups and working well. Your package dependencies may vary. To help improve this setup, please post any issues mentioning any dependency failures.

Some note, issues to keep in mind:
* Make sure your text editor is using a nerd font to see the tag labels
+ If you customize the layout labels (which use nerd font icons), then you may need to edit the icons in `dwm.c` in some of the layout functions where the nmaster value is printed
  + Example: changing this `{ "  ", monocle },` in `config.h` will need you to change this line in `dwm.c` around line 1500: `snprintf(m->ltsymbol, sizeof m->ltsymbol, " %d", n);`
  + You can also delete that line the preceding if statement
+ My `config.h` uses scripts that depend on rofi. So before building and running make sure you have it installed, along dmenu as a backup
+ Tile layout gaps is a little broken in edge cases. In typical use, column and tile look the same until you change nmaster
+ Other layouts don't have consistent gaps, will fix later
+ Status bars deal with padding in different ways. You will need to adjust script outputs by adding/removing trailing spaces either in the config.h files (slstatus or dwmblocks) or in the script outputs
+ You can enable/disable layouts by commenting them out. However, in the key bindings section, reorder the lines and define the correct index.
+ Not sure if it's this DWM setup, or my system, using Ark to extract archives causes DWM to reset.

# Dependencies
## `config.def.h` dependencies
+ libxft-bgra
+ For IPC Patch: yajl, jsoncpp
+ [st](https://st.suckless.org/)
+ [dmenu](https://tools.suckless.org/dmenu/)
+ In `autostart.sh`
  + nitrogen
  + picom
  + numlockx
  + dunst
  + dwmblocks (optional)
  + slstatus (optional)

## `config.h` Dependencies
+ [Alacritty Terminal](https://github.com/alacritty/alacritty)
+ [Polybar DWM Module](https://github.com/mihirlad55/polybar-dwm-module)
  + This replaces polybar which includes a dwm module
+ tabbed (seems like when used with alacritty and fish shell, a memory leak occurs with fish)
+ slock
+ Nerd Fonts Complete
+ Source Code Pro font
+ [rofi](https://github.com/davatorium/rofi) (see dot files for scripts)
+ [pavolume](https://github.com/sseemayer/pavolume)
+ scrot
+ playerctl
+ scripts from my [dotfiles repository](https://github.com/abbsi/dotfiles/tree/main/bin)
  + See my current [autostart.sh](https://github.com/abbsi/dotfiles/blob/main/.dwm/autostart.sh)
  + Uses [xidlehook](https://github.com/jD91mZM2/xidlehook) to dim the screen after 5 minutes and then use `slock` to pixilate lock the screen 

# Patches Applied

+ [Suckless DWM full patch list](https://dwm.suckless.org/patches/)
+ [Map of Patches Possible](https://coggle.it/diagram/X9IiSSM6PTWOM9Wz/t/dwm-patches/d3448968e2509321527c3864cd4eee651e5f55e525582fdbf33be764972d9aef)

## General

| Patch | Purpose |
| ----- | ------- |
| [Auto Start](https://dwm.suckless.org/patches/autostart/) | makes dwm run `~/.dwm/autostart_blocking.sh` and `~/.dwm/autostart.sh &` on startup |
| [Static Status](https://dwm.suckless.org/patches/staticstatus/)  | allows the status text to be fixed to the bar on a specific monitor rather than being drawn on the focused monitor. Update `staticmonval` to select monitor |
| [Restart Signal](https://dwm.suckless.org/patches/restartsig/) | adds a keyboard shortcut to restart dwm or alternatively by using `kill -HUP dwmpid` and additionally dwm can quit cleanly by using `kill -TERM dwmpid` |
| [EWMH Tags](https://dwm.suckless.org/patches/ewmhtags/) | adds EWMH support for _NET_NUMBER_OF_DESKTOPS, _NET_CURRENT_DESKTOP, _NET_DESKTOP_NAMES, and _NET_DESKTOP_VIEWPORT, which allows for compatibility with other bars and programs that request workspace information. for example, polybar's xworkspaces module |
| [Focus on Active](https://dwm.suckless.org/patches/focusonnetactive/) | By default, dwm response to client requests to _NET_ACTIVE_WINDOW client messages by setting the urgency bit on the named window. This patch activates the window instead. |

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
| [Named Scratch Pads](https://dwm.suckless.org/patches/namedscratchpads/) |  Allows for the creation of multiple scratchpad windows, each assigned to different keybinds. On pressing the keybind the window will either spawn based on the given command (if it's not already running) or toggle visibility of the window |
| [TODO: Switch to Urgent] | Look into finding/creating patch to switch to urgent |

## Layouts
+ TODO: Fix fibonacci layouts spacing
+ TODO: Fix bstack stack client X postion and Width

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

# Acknowledgement

The initial patched versions of `dwm`, `dmenu`, `dwmblocks` were taken from Derek Taylor (DistroTube):
+ GitLab:  [https://gitlab.com/dwt1]
+ Website: [https://distrotube.com/]
  