ReadMe still WIP and rough.

# DWM Build

TODO: Add details
TODO: config.def.h deviates heavily from the typical and standard key bindings. Those should stay as standard in config.def.h while personal config.h can keep those. Reset config.h to align closer to the original DWM 6.2 config.def.h

# Patches Applied

## General

| Patch | Purpose |
| ----- | ------- |
| [Auto Start](https://dwm.suckless.org/patches/autostart/) | makes dwm run `~/.dwm/autostart_blocking.sh` and `~/.dwm/autostart.sh &` on startup |
| [Static Status](https://dwm.suckless.org/patches/staticstatus/)  | allows the status text to be fixed to the bar on a specific monitor rather than being drawn on the focused monitor |
| [Restart Signal](https://dwm.suckless.org/patches/restartsig/) | adds a keyboard shortcut to restart dwm or alternatively by using kill -HUP dwmpid and additionally dwm can quit cleanly by using kill -TERM dwmpid |

## Appearance

+ Useless gap patch was modified to keep gaps and borders around tags with single clients
+ Applied tilegap patch and modified to match column layout spacing. Layouts are exactly the same until you increment the `nmaster` value.
  + TODO: When nmaster is 0, add gappx to x and remove from width
  + TODO: When nmaster > number of clients, add gappx to width

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
+ Client indicator patch has modified dimensions for visibility and added `showclientcount` to config.def.h to turn on/off Client indicators patch

| Patch | Purpose |
| ----- | ------- |
| [Alternative Tags](https://dwm.suckless.org/patches/alternativetags/) | adds alternative tags which can be toggled on the fly for the sole purpose of providing visual aid |
| [Alternative Tags Decoration](https://dwm.suckless.org/patches/alttagsdecoration/) | provides the ability to use alternative text for tags which contain at least one window |
| [Client Indicators*](https://dwm.suckless.org/patches/clientindicators/) | draws a dot indicator overlayed on each tag icon for each client, the selected client is drawn as a larger horizontal line |
| [Pertag](https://dwm.suckless.org/patches/pertag/) | adds nmaster, mfact, layouts and more per tag rather than per monitor |
| [Switch to Tag](https://dwm.suckless.org/patches/switchtotag/)  | To be removed, irregular behavior with per tags and multimonitor, or don't use |
| [Focus Urgent](https://dwm.suckless.org/patches/focusurgent/)  | TODO: find monitor with urgent client and focus there first |

## Layouts
+ TODO: Fix fibonacci layouts spacing
+ TODO: Fix bstack stack client X and Width

| Patch | Purpose |
| ----- | ------- |
| [Bottom Stack (bstack and bstackhoriz)](https://dwm.suckless.org/patches/bottomstack/) | Bottom Stack layout and Bottom Stack Horizontal |
| [Columns](https://dwm.suckless.org/patches/columns/) | same as the default tile layout except clients in the master area are arranged in columns (i.e. left to right) |
| [Fibonacci (Spiral and Dwindle)](https://dwm.suckless.org/patches/fibonacci/) | fibonacci (dwindle and spiral) layouts |
| [Grid](https://dwm.suckless.org/patches/gridmode/) | gridmode (grid) layout |

## Layout Management

| Patch | Purpose |
| ----- | ------- |
| [Cycle Layouts](https://dwm.suckless.org/patches/cyclelayouts/) | lets you cycle through all your layouts |
| [Attach Direction](https://dwm.suckless.org/patches/attachdirection/) | Single patch allowing attaching above, aside, below, bottom and top. To switch between the behaviors change the value of attachdirection in config. For default behavior leave it at 0 |
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
+ Some layouts add the value of `nmaster` to the layut tag (Similar to Monacle Count)
+ Extra color schemes for use with slstatus

# Dependencies
## Config.def.h Depedndencies (to be verified on a clean install)
+ libxft-bgra
+ For IPC Patch: yajl, jsoncpp
+ Nerd Fonts Complete
+ Source Code Pro font
+ [Alacritty Terminal](https://github.com/alacritty/alacritty)
+ [dmenu](https://tools.suckless.org/dmenu/)
+ [Polybar DWM Module](https://github.com/mihirlad55/polybar-dwm-module)

## Config.h Dependencies
+ [rofi](https://github.com/davatorium/rofi) (see dot files for scripts)
+ [pavolume](https://github.com/sseemayer/pavolume)
+ scrot
+ playerctl

## Additonal tools
+ slock
+ tabbed

# Status Bars Working with this build
TODO: add guide to building and selecting status bars

Change the autostart script.

+ DWM Blocks
+ slstatus
+ Polybar