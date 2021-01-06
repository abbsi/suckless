// See LICENSE file for copyright and license details.
// Forked from http://www.gitlab.com/dwt1/ & http://www.youtube.com/c/DistroTube

/* Default settings; can be overriden by command line. */

static int topbar = 0;       /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 1;     /* -c option; centers dmenu on screen */
static int min_width = 1500;  /* minimum width when centered */
static int fuzzy = 1;        /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
  "Source Code Pro:pixelsize=20:antialias=true:autohint=true",
  "Hack:pixelsize=20:antialias=true:autohint=true",
  "JoyPixels:pixelsize=16:antialias=true:autohint=true"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

/* Uses a pywal generated theme. If you do not use pywal, then comment out line below and uncomment the color block below it */
#include "/home/abbsi/.cache/wal/colors-wal-dmenu.h"

// static const char *colors[SchemeLast][2] = {
//                           /*   fg         bg    */
//   [SchemeNorm] =          { "#cccccc", "#23395B" },
//   [SchemeSel] =           { "#ffffff", "#04253A" },
//   [SchemeOut] =           { "#000000", "#04253A" },
//   [SchemeSelHighlight] =  { "#d7d7d7", "#04253A" },
//   [SchemeNormHighlight] = { "#d7d7d7", "#064C74" },
//   [SchemeMid] =           { "#d7d7d7", "#04334E" },
// };


/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 0;
static unsigned int lineheight = 16;  /* -h option; minimum height of a menu line */
static unsigned int columns    = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 2;  /* -bw option; to add border width */
