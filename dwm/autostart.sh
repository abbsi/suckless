#!/bin/bash 

# Place this script in $HOME/.dwm/
picom &
nitrogen --restore &
# slstatus &
# dwmblocks &
numlockx &
dunstify -u low "Completed DWM autostart.sh" &