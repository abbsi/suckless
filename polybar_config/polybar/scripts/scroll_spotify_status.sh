#!/bin/bash

# see man zscroll for documentation of the following parameters
zscroll -l 30 \
        --delay 2 \
        --match-command "playerctl --player=playerctld status" \
        --match-text "Playing" "--scroll 1" \
        --match-text "Paused" "--scroll 0" \
        --update-check true '/home/nabil/.config/polybar/scripts/get_spotify_status.sh' &

wait