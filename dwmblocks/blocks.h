// Forked from http://www.gitlab.com/dwt1/ & see http://www.youtube.com/c/DistroTube
// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
  /*Icon   Command             Update Interval   Update Signal*/
  {"\x08 阮 ",  "spotify-status",  10,               1},
  {"\x09   ",  "pacupdate",       360,              9},
  {"\x0A  ",  "memory",          6,                1},
  {" ﴖ ",  "diskf",           90,               1},
  {"\x0B   ",  "volume",          2,                0},
  {"\x0C 羽 ",  "upt",             60,               2},
  {"\x0D  ",  "clock",           5,                0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
