ReadMe still WIP and rough.

# Patches Applied

## General
| Patch | Purpose |
| ----- | ------- |
| [Auto Start](https://dwm.suckless.org/patches/autostart/) | Purpose |
| [Static Status](https://dwm.suckless.org/patches/staticstatus/)  | Check config var missing |
| [Restart Signal](https://dwm.suckless.org/patches/restartsig/) | Purpose |

## Apearance
| Patch | Purpose |
| ----- | ------- |
| [Alpha](https://dwm.suckless.org/patches/alpha) | Purpose |
| [Color Bar](https://dwm.suckless.org/patches/colorbar/) | Purpose |
| [Status Padding](https://dwm.suckless.org/patches/statuspadding/dwm-statuspadding-20150524-c8e9479.diff) | Purpose |
| [Status Colors](https://dwm.suckless.org/patches/statuscolors/) | Purpose |
| [Useless Gap](https://dwm.suckless.org/patches/uselessgap/) | Purpose |

## Tag Management
| Patch | Purpose |
| ----- | ------- |
| [Aletternative Tags](https://dwm.suckless.org/patches/alternativetags/) | Purpose |
| [Alternative Tags Decoration](https://dwm.suckless.org/patches/alttagsdecoration/) | Purpose |
| [Client Indicators](https://dwm.suckless.org/patches/clientindicators/dwm-clientindicators-6.2.diff) | Purpose |
| [Pertag](https://dwm.suckless.org/patches/pertag/) | Purpose |
| [Switch to Tag](https://dwm.suckless.org/patches/switchtotag/)  | To be removed, irregular behavior with per tags and multimonitor |

## Layouts
| Patch | Purpose |
| ----- | ------- |
| [Bottom Stack (bstack and bstackhoriz)](https://dwm.suckless.org/patches/bottomstack/) | Purpose |
| [Columns](https://dwm.suckless.org/patches/columns/) | Purpose |
| [Fibonacci (Spiral and Dwindle)](https://dwm.suckless.org/patches/fibonacci/) | Purpose |
| [Grid](https://dwm.suckless.org/patches/gridmode/) | Purpose |

## Layout Management
| Patch | Purpose |
| ----- | ------- |
| [Cycle Layouts](https://dwm.suckless.org/patches/cyclelayouts/) | Purpose |
| [Attatch Direction](https://dwm.suckless.org/patches/attachdirection/) | Purpose |
| [Always Center](https://dwm.suckless.org/patches/alwayscenter/) | Purpose |
| [Rotate Stack](https://dwm.suckless.org/patches/rotatestack/) | Purpose |

## Polybar Integration and IPC
| Patch | Purpose |
| ----- | ------- |
| [Any Bar & Polybar tray fix](https://dwm.suckless.org/patches/anybar/) | Purpose | 
| [DWM IPC](https://github.com/mihirlad55/dwm-ipc) | [1.5.7](https://github.com/mihirlad55/dwm-ipc/releases/tag/v1.5.7) Applied | 

See Also https://dwm.suckless.org/patches/ipc/

## Customizations to Patches Above
+ Client indicator patch has modified dimensions for visibility
+ Added `showclientcount` to turn on/off Client indicators patch
+ Some layouts add the value of `nmaster` to the layut tag (Similar to Monacle Count)
+ Extra color schemes for use with slstatus

# Dependencies
## Config.def.h Depedndencies
+ libxft-bgra
+ For IPC Patch: yajl, jsoncpp
+ Nerd Fonts Complete
+ Source Code Pro font
+ Alacritty Terminal
+ [dmenu](https://tools.suckless.org/dmenu/)
+ [Polybar DWM Module](https://github.com/mihirlad55/polybar-dwm-module)

## Config.h Dependencies
+ scrot
+ rofi (see dot files for scripts)
+ pavolume
+ playerctl

## Additonal tools
+ slock
+ tabbed

# Status Bars Working with this configuration
Change the autostart script.

+ DWM Blocks
+ slstatus
+ Polybar