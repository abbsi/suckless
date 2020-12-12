Orginally forked from http://www.gitlab.com/dwt1/ 
Visit http://www.youtube.com/c/DistroTube

# dwmblocks
Modular status bar for dwm written in c.

# Modifying dwmblocks
Blocks are added and removed by editing the blocks.h header file. See Scripts folder for sample scripts

# To get my dwmblocks to work for you...
See `scripts` folder and point the blocks.h file to them or add them to a location in your $PATH.

To add .local/bin to $PATH, just add this line to your .bashrc:

	PATH="$HOME/.local/bin${PATH:+:${PATH}}"