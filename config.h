/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[] = "-*-xbmicons-medium-r-*-*-12-*-*-*-*-*-*-*" ","
                           "-*-terminus2-medium-r-*-*-12-*-*-*-*-*-*-*";
#define NUMCOLORS 6
static const char colors[NUMCOLORS][ColLast][8] = {
  // border foreground background
  { "#073642", "#657b83", "#002b36" }, // 1 = normal (grey on black)
  { "#b58900", "#eee8d5", "#002b36" }, // 2 = selected (white on black)
  { "#dc322f", "#002b36", "#b58900" }, // 3 = urgent (black on yellow)
  { "#073642", "#839496", "#073642" }, // 4 = lightgrey on brightblack
  { "#073642", "#073642", "#002b36" }, // 5 = brightblack on black
  { "#073642", "#002b36", "#073642" }, // 6 = black on brightblack
};
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 8;        /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "\uE000", "\uE001", "\uE002", "\uE003", "\uE008",
                              "\uE004", "\uE005", "\uE006","\uE007 " };

static const Rule rules[] = {
  /* class                      instance     title  tags mask isfloating  iscentred   monitor */
  { "feh",                      NULL,        NULL,  0,        True,       True,       -1 },
  { "Gcolor2",                  NULL,        NULL,  0,        True,       True,       -1 },
  { "Lxappearance",             NULL,        NULL,  0,        True,       True,       -1 },
  { "Screenkey",                NULL,        NULL,  0,        True,       True,       -1 },
  { "XFontSel",                 NULL,        NULL,  0,        True,       True,       -1 },
  { "Xfd",                      NULL,        NULL,  0,        True,       True,       -1 },
  { "Firefox",                  NULL,        NULL,  1,        False,      False,      -1 },
  { "URxvt",                    "chatmail",  NULL,  1 << 1,   False,      False,      -1 },
  { "Gvim",                     NULL,        NULL,  1 << 2,   False,      False,      -1 },
  { "Zathura",                  NULL,        NULL,  1 << 3,   False,      False,      -1 },
  { "libreoffice-calc",         NULL,        NULL,  1 << 3,   False,      False,      -1 },
  { "libreoffice-impress",      NULL,        NULL,  1 << 3,   False,      False,      -1 },
  { "libreoffice-startcenter",  NULL,        NULL,  1 << 3,   False,      False,      -1 },
  { "libreoffice-writer",       NULL,        NULL,  1 << 3,   False,      False,      -1 },
  { "mplayer2",                 NULL,        NULL,  1 << 4,   True,       False,      -1 },
  { "Blender",                  NULL,        NULL,  1 << 5,   True,       False,      -1 },
  { "Gbdfed",                   NULL,        NULL,  1 << 5,   True,       True,       -1 },
  { "Gimp",                     NULL,        NULL,  1 << 5,   True,       False,      -1 },
  { "fontforge",                NULL,        NULL,  1 << 5,   True,       True,       -1 },
  { "inkscape",                 NULL,        NULL,  1 << 5,   True,       False,      -1 },
  { "URxvt",                    "ranger",    NULL,  1 << 6,   False,      False,      -1 },
};

/* layout(s) */
static const float mfact      = 0.50;  /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

#include "bstack.c"
#include "gaplessgrid.c"
static const Layout layouts[] = {
  /* symbol     arrange function */
  { "\uE019 \uE009 \uE019",    tile },    /* first entry is default */
  { "\uE019 \uE00A \uE019",    NULL },    /* no layout function means floating behavior */
  { "\uE019 \uE00B \uE019",    monocle },
  { "\uE019 \uE00C \uE019",    bstack },
  { "\uE019 \uE00D \uE019",    gaplessgrid },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,     	  {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]      = { "dmenu_run", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *netcmd[]        = { "dmenu_net", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[1][ColFG], "-i", NULL };
static const char *termcmd[]       = { "terminator", NULL };
static const char *browsercmd[]    = { "google-chrome-stable", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "urxvtc", "-name", scratchpadname, "-geometry", "100x25", NULL };
static const char *volupcmd[]      = { "amixer", "-q", "set", "PCM", "5%+", NULL };
static const char *voldncmd[]      = { "amixer", "-q", "set", "PCM", "5%-", NULL };
static const char *mpctog[]        = { "ncmpcpp", "toggle", NULL };
static const char *mpcprev[]       = { "ncmpcpp", "prev", NULL };
static const char *mpcnext[]       = { "ncmpcpp", "next", NULL };

#include "push.c"
static Key keys[] = {
  /* modifier               key               function        argument */
  { MODKEY,                 XK_o,             spawn,          {.v = dmenucmd } },
  { MODKEY,                 XK_n,             spawn,          {.v = netcmd } },
  { MODKEY|ShiftMask,       XK_w,             spawn,          {.v = browsercmd } },
  { MODKEY|ShiftMask,       XK_Return,        spawn,          {.v = termcmd } },
  { MODKEY,                 XK_s,             togglescratch,  {.v = scratchpadcmd} },
  { MODKEY,                 XK_apostrophe,    spawn,          {.v = volupcmd } },
  { MODKEY,                 XK_semicolon,     spawn,          {.v = voldncmd } },
  { MODKEY,                 XK_slash,         spawn,          {.v = mpctog } },
  { MODKEY,                 XK_bracketleft,   spawn,          {.v = mpcprev } },
  { MODKEY,                 XK_bracketright,  spawn,          {.v = mpcnext } },
  { MODKEY|ControlMask,     XK_b,             togglebar,      {0} },
  { MODKEY,                 XK_j,             focusstack,     {.i = +1 } },
  { MODKEY,                 XK_k,             focusstack,     {.i = -1 } },
  { MODKEY|ShiftMask,       XK_j,             pushdown,       {0} },
  { MODKEY|ShiftMask,       XK_k,             pushup,         {0} },
  { MODKEY,                 XK_i,             incnmaster,     {.i = +1 } },
  { MODKEY,                 XK_d,             incnmaster,     {.i = -1 } },
  { MODKEY,                 XK_h,             setmfact,       {.f = -0.05} },
  { MODKEY,                 XK_l,             setmfact,       {.f = +0.05} },
  { MODKEY,                 XK_Return,        zoom,           {0} },
  { MODKEY,                 XK_Tab,           view,           {0} },
  { MODKEY|ShiftMask,       XK_c,             killclient,     {0} },
  { MODKEY,                 XK_t,             setlayout,      {.v = &layouts[0]} },
  { MODKEY,                 XK_f,             setlayout,      {.v = &layouts[1]} },
  { MODKEY,                 XK_m,             setlayout,      {.v = &layouts[2]} },
  { MODKEY,                 XK_b,             setlayout,      {.v = &layouts[3]} },
  { MODKEY,                 XK_g,             setlayout,      {.v = &layouts[4]} },
  { MODKEY,                 XK_space,         setlayout,      {0} },
  { MODKEY|ShiftMask,       XK_space,         togglefloating, {0} },
  { MODKEY,                 XK_0,             view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,       XK_0,             tag,            {.ui = ~0 } },
  { MODKEY,                 XK_comma,         focusmon,       {.i = -1 } },
  { MODKEY,                 XK_period,        focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,       XK_comma,         tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,       XK_period,        tagmon,         {.i = +1 } },
  TAGKEYS(                  XK_1,                             0)
    TAGKEYS(                  XK_2,                             1)
    TAGKEYS(                  XK_3,                             2)
    TAGKEYS(                  XK_4,                             3)
    TAGKEYS(                  XK_5,                             4)
    TAGKEYS(                  XK_6,                             5)
    TAGKEYS(                  XK_7,                             6)
    TAGKEYS(                  XK_8,                             7)
    TAGKEYS(                  XK_9,                             8)
    { MODKEY|ShiftMask,       XK_q,             quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        toggleview,     {0} },
  { ClkTagBar,            0,              Button3,        view,           {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

