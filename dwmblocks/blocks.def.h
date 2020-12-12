// Forked from http://www.gitlab.com/dwt1/ & see http://www.youtube.com/c/DistroTube
// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
  /*Icon   Command             Update Interval   Update Signal*/
  {" 阮 ",  "spotify-status",  10,               1},
  {"  ",  "pacupdate",       360,              9},
  {"  ",  "memory",          6,                1},
  {" ﴖ ",  "diskf",           90,               1},
  {"   ",  "volume",          2,                0},
  {" 羽 ",  "upt",             60,               2},
  {"  ",  "clock",           5,                0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = '|';
