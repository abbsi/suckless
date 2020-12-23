// See LICENSE file for copyright and license details.
// Orginally forked from http://www.gitlab.com/dwt1/ 
// Visit http://www.youtube.com/c/DistroTube

// All scripts/programs must be in your PATH

#include <X11/XF86keysym.h>

/* Appearance */
static const unsigned int borderpx = 3;              /* border pixel of windows */
static const unsigned int snap     = 30;             /* snap pixel */
static const unsigned int gappx    = 12;             /* pixel gap between clients */
static const int showbar           = 1;              /* 0 means no bar */
static const int topbar            = 1;              /* 0 means bottom bar */
static const int horizpadbar       = 10;             /* horizontal padding for statusbar */
static const int vertpadbar        = 15;             /* vertical padding for statusbar */
static const int showclientcount   = 1;              /* 1 means show client indicators on tag */

/* Alternative Bars */
static const int usealtbar         = 0;              /* 1 means use non-dwm status bar */
static const char *altbarclass     = "Polybar";      /* Alternate bar class name */
static const char *alttrayname     = "tray";         /* Polybar tray instance name */
static const char *altbarcmd       = "polybar-open"; /* Alternate bar launch command */

/* Fonts */
static const char *fonts[]         = {
    "Anonymice Nerd Font:size=16:antialias=true:autohint=true",
    "Hack:size=16:antialias=true:autohint=true",
    "JoyPixels:size=14:antialias=true:autohint=true" };


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
static const unsigned int borderalpha = 0xaa; // OPAQUE;
static const char *colors[][3]        = {
  /*                    fg            bg            border   */
  [SchemeNorm]     = { col_offwhite,  col_bg,        col_darkgray },
  [SchemeSel]      = { col_orange,    col_bg,        col_offwhite },
  [SchemeStatus]   = { col_offwhite,  col_bg,        col_black }, // Statusbar Tright {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_offwhite,  col_bluegray,  col_black }, // Tagbar left selected {text,background,not used but cannot be empty}
  [SchemeTagsNorm] = { col_offwhite,  col_lightgray, col_black }, // Tagbar left unselected {text,background,not used but cannot be empty}
  [SchemeInfoSel]  = { col_offwhite,  col_bg,        col_black }, // infobar middle  selected {text,background,not used but cannot be empty}
  [SchemeInfoNorm] = { col_lightgray, col_bg,        col_black }, // infobar middle  unselected {text,background,not used but cannot be empty}
  [Scheme08]       = { col_red,       col_bg,        col_black }, 
  [Scheme09]       = { col_green,     col_bg,        col_black }, 
  [Scheme0A]       = { col_hotpink,   col_bg,        col_black }, 
  [Scheme0B]       = { col_lightblue, col_bg,        col_black }, 
  [Scheme0C]       = { col_blue,      col_bg,        col_black }, 
  [Scheme0D]       = { col_offwhite,  col_bg,        col_black },
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
static const int statmonval = 0;

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
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class          instance       title       tags mask   switchtotag    isfloating   monitor */
  { "firefox",     "Navigator",   NULL,              0,        0,          0,           0  },
};

/* layout(s) */
static const float mfact     = 0.60;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;     /* number of clients in master area */
static const int resizehints = 1;     /* 1 means respect size hints in tiled resizals */

/* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */
static const int attachdirection = 3;

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "  ",      col },     /* first entry is default */
  { "ﳶ  ",      bstack },     
  { "  ",      monocle },
  { "  ",      dwindle },
  { "  ",      NULL },    /* no layout function means floating behavior */
  { "舘  ",      tile },    
  { "  ",      grid },
  { "  ",      spiral },
  { "充  ",      bstackhoriz },
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
  { MODKEY|ShiftMask,     XK_Return,   spawn, {.v = dmenucmd } },
  { MODKEY,               XK_Return,   spawn, CMD("alacritty") },
  { Mod1Mask,             XK_Return,   spawn, CMD("tabbed-term") },

  /* Custom Key Maps */
  { MODKEY|ShiftMask,  XK_Up,           rotatestack,    {.i = -1 } },
  { MODKEY|ShiftMask,  XK_Down,         rotatestack,    {.i = +1 } },
  { MODKEY,            XK_Up,           focusstack,     {.i = -1 } }, 
  { MODKEY,            XK_Down,         focusstack,     {.i = +1 } }, 
  { Mod1Mask,          XK_Tab,          focusstack,     {.i = +1 } }, 
  { MODKEY,            XK_Left,         setmfact,       {.f = -0.01} }, 
  { MODKEY,            XK_Right,        setmfact,       {.f = +0.01} },
  { MODKEY,            XK_Prior,        focusmon,       {.i = -1 } },
  { MODKEY,            XK_Next,         focusmon,       {.i = +1 } },
  { MODKEY,            XK_Tab,          focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,  XK_Prior,        tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,  XK_Next,         tagmon,         {.i = +1 } },
  { MODKEY,            XK_bracketright, cyclelayout,    {.i = -1 } },
  { MODKEY,            XK_bracketleft,  cyclelayout,    {.i = +1 } },
  { MODKEY,            XK_0,            view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,  XK_0,            tag,            {.ui = ~0 } },
  { MODKEY,            XK_comma,        incnmaster,     {.i = -1 } },
  { MODKEY,            XK_period,       incnmaster,     {.i = +1 } },
  { MODKEY,            XK_c,            setlayout,      {.v = &layouts[0]} },
  { MODKEY,            XK_h,            setlayout,      {.v = &layouts[1]} },
  { MODKEY,            XK_m,            setlayout,      {.v = &layouts[2]} },
  { MODKEY,            XK_d,            setlayout,      {.v = &layouts[3]} },
  { MODKEY,            XK_f,            setlayout,      {.v = &layouts[4]} },
  { MODKEY,            XK_t,            setlayout,      {.v = &layouts[5]} },
  { MODKEY,            XK_g,            setlayout,      {.v = &layouts[6]} },
  { MODKEY,            XK_s,            setlayout,      {.v = &layouts[7]} },
  { MODKEY,            XK_u,            setlayout,      {.v = &layouts[8]} }, 
  { MODKEY,            XK_a,            setlayout,      {0} },
  { MODKEY,            XK_Home,         zoom,           {0} },
  { MODKEY,            XK_b,            togglebar,      {0} },
  { MODKEY,            XK_q,            killclient,     {0} },
  { MODKEY|ShiftMask,  XK_space,        togglefloating, {0} },
  { MODKEY,            XK_n,            togglealttag,   {0} },
  
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

/* DWM IPC Patch for Alternative Bars */
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
