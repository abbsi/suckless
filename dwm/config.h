// See LICENSE file for copyright and license details.
// Orginally forked from http://www.gitlab.com/dwt1/ 
// Visit http://www.youtube.com/c/DistroTube

// All scripts/programs must be in your PATH

#include <X11/XF86keysym.h>

/* Appearance */
static const unsigned int borderpx = 2;                /* border pixel of windows */
static const unsigned int snap     = 30;               /* snap pixel */
static const unsigned int gappx    = 30;               /* pixel gap between clients */
static const int showbar           = 1;                /* 0 means no bar */
static const int topbar            = 1;                /* 0 means bottom bar */
static const int horizpadbar       = 10;               /* horizontal padding for statusbar */
static const int vertpadbar        = 15;               /* vertical padding for statusbar */
static const int showclientind     = 1;                /* 1 means show client indicators on tag */

/* Alternative Bars */
static const int usealtbar         = 1;                /* 1 means use non-dwm status bar */
static const char *altbarclass     = "Polybar";        /* Alternate bar class name */
static const char *alttrayname     = "tray";           /* Polybar tray instance name */
static const char *altbarcmd       = "launch-polybar"; /* Alternate bar launch command */

/* Fonts */
static const char *fonts[]         = {
    "Anonymice Nerd Font:size=16:antialias=true:autohint=true",
    "Hack:size=10:antialias=true:autohint=true",
    "JoyPixels:size=12:antialias=true:autohint=true" };

/* Custom Colors */ 
static const char col_bg[]        = "#222222";
static const char col_bluegray[]  = "#23395B";
static const char col_blue[]      = "#23799B";
static const char col_lightblue[] = "#4399BB";
static const char col_offwhite[]  = "#d7d7d7";
static const char col_hotpink[]   = "#F7006F";
static const char col_darkgray[]  = "#222222";
static const char col_lightgray[] = "#666666";
static const char col_black[]     = "#000000";
static const char col_red[]       = "#ff2244";
static const char col_orange[]    = "#ff8800";
static const char col_yellow[]    = "#ffff00";
static const char col_white[]     = "#ffffff";
static const char col_green[]     = "#009900"; 

/* Bar opacity ; 0xff is no transparency. Play with the value to get desired transparency. */
static const unsigned int baralpha    = 0xdd; 
static const unsigned int borderalpha = 0xaa; 
static const char *colors[][3]        = {
  /*                    fg            bg            border   */
  [SchemeNorm]     = { col_offwhite,  col_bg,        col_darkgray },
  [SchemeSel]      = { col_orange,    col_bg,        col_offwhite },
  [SchemeStatus]   = { col_offwhite,  col_bg,        col_black }, // Statusbar Tright {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_offwhite,  col_bluegray,  col_black }, // Tagbar left selected {text,background,not used but cannot be empty}
  [SchemeTagsNorm] = { col_offwhite,  col_lightgray, col_black }, // Tagbar left unselected {text,background,not used but cannot be empty}
  [SchemeInfoSel]  = { col_offwhite,  col_bg,        col_black }, // infobar middle  selected {text,background,not used but cannot be empty}
  [SchemeInfoNorm] = { col_lightgray, col_bg,        col_black }, // infobar middle  unselected {text,background,not used but cannot be empty}
  [Scheme08]       = { col_red,       col_bg,        col_black }, // for use with DWM Blocks / slstatus ( \x08 )
  [Scheme09]       = { col_green,     col_bg,        col_black }, // for use with DWM Blocks / slstatus ( \x09 )
  [Scheme0A]       = { col_hotpink,   col_bg,        col_black }, // for use with DWM Blocks / slstatus ( \x0A )
  [Scheme0B]       = { col_lightblue, col_bg,        col_black }, // for use with DWM Blocks / slstatus ( \x0B )
  [Scheme0C]       = { col_blue,      col_bg,        col_black }, // for use with DWM Blocks / slstatus ( \x0C )
  [Scheme0D]       = { col_offwhite,  col_bg,        col_black }, // for use with DWM Blocks / slstatus ( \x0D )
};
static const unsigned int alphas[][3] = {
  /*               fg      bg        border     */
  [SchemeNorm]     = { OPAQUE, baralpha, borderalpha },
  [SchemeSel]      = { OPAQUE, baralpha, borderalpha },
  [SchemeStatus]   = { OPAQUE, baralpha, borderalpha },
  [SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
  [SchemeTagsNorm] = { OPAQUE, baralpha, borderalpha },
  [SchemeInfoSel]  = { OPAQUE, baralpha, borderalpha },
  [SchemeInfoNorm] = { OPAQUE, baralpha, borderalpha },
  [Scheme08]       = { OPAQUE, baralpha, borderalpha },
  [Scheme09]       = { OPAQUE, baralpha, borderalpha },
  [Scheme0A]       = { OPAQUE, baralpha, borderalpha },
  [Scheme0B]       = { OPAQUE, baralpha, borderalpha },
  [Scheme0C]       = { OPAQUE, baralpha, borderalpha },
  [Scheme0D]       = { OPAQUE, baralpha, borderalpha },

};

/* staticstatus */
static const int statmonval = 1; /* Choose which monitor to draw status bar (if not using alt bar) */

/* Tagging */
/* Ensure your terminal/editor is also using the target font to see characters below */
// " term"," dev"," www","聆 social","黎 mail"," file"," conf","«  »","«  »"
// "","","","聆","","","","",""
// "","","","","","","","",""
// "1","2","3","4","5","6","7","8","9"
static const char *tags[] = {"祿","祿","祿","祿","祿","祿","祿","祿","祿"};      // Tags shown when empty
static const char *alttags[] = {"綠","綠","綠","綠","綠","綠","綠","綠",""};   // Tags shown when window is spawned
static const char *tagsalt[] = { "","","","","","","","","" }; // Alternative tags to show using key bind

static const Rule rules[] = {
  /* xprop(1):
   * WM_CLASS(STRING) = instance, class
   * WM_NAME(STRING) = title
   * Left = 2
   * Main = 0
   * Right = 1
   */
  /* class                        instance                       title              tags mask    swithtotag   isfloating   monitor */
  /* Left Monitor */
  { "firefox",                    "Navigator",                  NULL,              1,           0,            0,           2   },
  { "Thunderbird",                "Mail",                       NULL,              2,           0,            0,           2   },
  { "realvnc-vncviewer",          NULL,                         NULL,              0,           0,            1,           2   },  
  
  /* Middle Monitor */
  { "Code",                       "code",                       NULL,              0,           0,            0,           0   },
  { "Sxiv",                       "sxiv",                       NULL,              0,           0,            0,           0   },
  
  /* Right Monitor */
  { "Slack",                      "slack",                      NULL,              1,           0,            0,           1   },
  { "whatsapp-nativefier-930aa1", "whatsapp-nativefier-930aa1", NULL,              1,           0,            0,           1   },  
  { "discord",                    "discord",                    NULL,              1,           0,            0,           1   },
  { "zoom",                       "zoom",                       NULL,              2,           0,            1,           1   },
  { NULL,                         NULL,                         "Spotify Premium", 0,           0,            0,           1   },
  
  /* Any Monitor */
  { "Gpick",                      "gpick",                      NULL,              0,           0,            1,           -1  },
  { "mpv",                        "gl",                         NULL,              0,           0,            1,           -1  },
  { "Nitrogen",                   "nitrogen",                   NULL,              0,           0,            1,           -1  },
  { "Galculator",                 "galculator",                 NULL,              0,           0,            1,           -1  },
  { "Pcmanfm",                    "pcmanfm",                    NULL,              0,           0,            1,           -1  },
  { "Pcmanfm",                    "pcmanfm",                    "Execute File",    0,           0,            1,           -1  },

};

/* layout(s) */
static const float mfact     = 0.66;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;     /* number of clients in master area */
static const int resizehints = 1;     /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 0;     /* 1 means respect decoration hints */

/* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */
static const int attachdirection = 3;


static const Layout layouts[] = { 
  /* symbol     arrange function */
  { "  ",      col },     /* first entry is default */
  { "舘  ",      tile },    
  { "ﳶ  ",      bstack },     
  { "  ",      dwindle },
  { "  ",      monocle },
  { "  ",      NULL },    /* no layout function means floating behavior */
//{ "  ",      grid },
//{ "  ",      spiral },
//{ "充  ",      bstackhoriz },
  { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]     = { "dmenu_run", "-g", "3", "-l", "20", "-fn", "Source Code Pro:pixelsize=20", "-p", "Run: ", NULL };

static Key keys[] = {
  { MODKEY,               XK_space,    spawn, CMD("m-drun") },
  { MODKEY,               XK_x,        spawn, CMD("m-run") },
  { MODKEY,               XK_w,        spawn, CMD("m-window") },
  { MODKEY|ShiftMask,     XK_Return,   spawn, {.v = dmenucmd } },
  { MODKEY,               XK_Return,   spawn, CMD("alacritty") },
  { Mod1Mask,             XK_Return,   spawn, CMD("tabbed-term") },
  { ControlMask,          XK_Print,    spawn, CMD("sleep 0.25s; shot") },
  { ShiftMask,            XK_Print,    spawn, CMD("sleep 0.25s; shot focused") },
  { 0,                    XK_Print,    spawn, CMD("sleep 0.25s; shot select") },
  { MODKEY,               XK_Print,    spawn, CMD("m-scrot") },
  { MODKEY,               XK_l,        spawn, CMD("slock") },
  { MODKEY,               XK_o,        spawn, CMD("m-quick-cmd") },
  { Mod1Mask|ControlMask, XK_e,        spawn, CMD("m-edit-configs") },
  { Mod1Mask|ControlMask, XK_m,        spawn, CMD("m-sysmon") },
  { Mod1Mask|ControlMask, XK_s,        spawn, CMD("m-todo2") },
  { Mod1Mask|ControlMask, XK_t,        spawn, CMD("m-todo") },
  { Mod1Mask|ControlMask, XK_n,        spawn, CMD("m-notifications") },
  { Mod1Mask|ControlMask, XK_f,        spawn, CMD("m-fm") },
  { Mod1Mask|ControlMask, XK_h,        spawn, CMD("alacritty -e bpytop") },
  { 0, XF86XK_AudioRaiseVolume,        spawn, CMD("pavolume volup --quiet") },
  { 0, XF86XK_Launch8,                 spawn, CMD("pavolume volup --quiet") },
  { 0, XF86XK_AudioLowerVolume,        spawn, CMD("pavolume voldown --quiet") },
  { 0, XF86XK_Launch7,                 spawn, CMD("pavolume voldown --quiet") },
  { 0, XF86XK_AudioMute,               spawn, CMD("pavolume mutetoggle --quiet") },
  { 0, XF86XK_AudioPlay,               spawn, CMD("playerctl play-pause" )},
  { 0, XF86XK_AudioStop,               spawn, CMD("playerctl stop" )},
  { 0, XF86XK_AudioPrev,               spawn, CMD("playerctl previous" )},
  { 0, XF86XK_AudioNext,               spawn, CMD("playerctl next" )},

  /* Custom Key Maps */
  { MODKEY|ShiftMask,  XK_Up,           rotatestack,    {.i = -1 } },
  { MODKEY|ShiftMask,  XK_Down,         rotatestack,    {.i = +1 } },
  { MODKEY|ShiftMask,  XK_Left,         rotatestack,    {.i = -1 } },
  { MODKEY|ShiftMask,  XK_Right,        rotatestack,    {.i = +1 } },
  { MODKEY,            XK_Up,           focusstack,     {.i = -1 } }, 
  { MODKEY,            XK_Down,         focusstack,     {.i = +1 } }, 
  { Mod1Mask,          XK_Tab,          focusstack,     {.i = +1 } }, 
  { MODKEY,            XK_Left,         setmfact,       {.f = -0.01} }, 
  { MODKEY,            XK_Right,        setmfact,       {.f = +0.01} },
  { MODKEY,            XK_Prior,        focusmon,       {.i = -1 } },
  { MODKEY,            XK_Next,         focusmon,       {.i = +1 } },
  { MODKEY,            XK_Tab,          focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,  XK_Prior,        tagmon,         {.i = -1 } }, //delete
  { MODKEY|ShiftMask,  XK_Next,         tagmon,         {.i = +1 } }, //delete
  { MODKEY|ControlMask,XK_Left,         tagmon,         {.i = -1 } },
  { MODKEY|ControlMask,XK_Right,        tagmon,         {.i = +1 } },
  { MODKEY,            XK_bracketright, cyclelayout,    {.i = -1 } },
  { MODKEY,            XK_bracketleft,  cyclelayout,    {.i = +1 } },
  { MODKEY,            XK_0,            view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,  XK_0,            tag,            {.ui = ~0 } },
  { MODKEY,            XK_comma,        incnmaster,     {.i = -1 } },
  { MODKEY,            XK_period,       incnmaster,     {.i = +1 } },
  { MODKEY,            XK_c,            setlayout,      {.v = &layouts[0]} }, 
  { MODKEY,            XK_t,            setlayout,      {.v = &layouts[1]} },
  { MODKEY,            XK_h,            setlayout,      {.v = &layouts[2]} },
  { MODKEY,            XK_d,            setlayout,      {.v = &layouts[3]} },
  { MODKEY,            XK_m,            setlayout,      {.v = &layouts[4]} },
  { MODKEY,            XK_f,            setlayout,      {.v = &layouts[5]} },
  { MODKEY,            XK_a,            setlayout,      {0} },
  { MODKEY,            XK_Home,         zoom,           {0} }, //delete
  { MODKEY,            XK_BackSpace,    zoom,           {0} },
  { MODKEY,            XK_b,            togglebar,      {0} },
  { MODKEY,            XK_q,            killclient,     {0} },
  { MODKEY|ShiftMask,  XK_space,        togglefloating, {0} },
  { MODKEY,            XK_n,            togglealttag,   {0} },
  { MODKEY,            XK_u,            focusurgent,    {0} },
  { MODKEY,            XK_r,            reorganizetags, {0} },
  //{ MODKEY,            XK_g,            setlayout,      {.v = &layouts[6]} },
  //{ MODKEY,            XK_s,            setlayout,      {.v = &layouts[7]} },
  //{ MODKEY,            XK_u,            setlayout,      {.v = &layouts[8]} }, 
  
  TAGKEYS(                  XK_1,          0)
  TAGKEYS(                  XK_2,          1)
  TAGKEYS(                  XK_3,          2)
  TAGKEYS(                  XK_4,          3)
  TAGKEYS(                  XK_5,          4)
  TAGKEYS(                  XK_6,          5)
  TAGKEYS(                  XK_7,          6)
  TAGKEYS(                  XK_8,          7)
  TAGKEYS(                  XK_9,          8)
  { MODKEY|ShiftMask,       XK_q,          quit,      {0} },
  { MODKEY|ShiftMask,       XK_r,          quit,      {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click           event mask   button          function        argument */
  { ClkLtSymbol,     0,           Button1,        setlayout,      {0} },
  { ClkLtSymbol,     0,           Button2,        setlayout,      {.v = &layouts[2]} },
  { ClkLtSymbol,     0,           Button3,        setlayout,      {.v = &layouts[0]} },
  { ClkWinTitle,     0,           Button2,        zoom,           {0} },
  { ClkClientWin,    MODKEY,      Button1,        movemouse,      {0} },
  { ClkClientWin,    MODKEY,      Button2,        togglefloating, {0} },
  { ClkClientWin,    MODKEY,      Button3,        resizemouse,    {0} },
  { ClkTagBar,       0,           Button1,        view,           {0} },
  { ClkTagBar,       0,           Button3,        toggleview,     {0} },
  { ClkTagBar,       MODKEY,      Button1,        tag,            {0} },
  { ClkTagBar,       MODKEY,      Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};