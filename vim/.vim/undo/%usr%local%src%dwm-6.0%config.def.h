Vim�UnDo� l���Y�:/�	�����e
�=w3����   s   Estatic const char font[]            = "xft:minecraftia:pixlesize=14";      <                       _��    _�                        <    ����                                                                                                                                                                                                                                                                                                                                                             _�z     �         s      Estatic const char font[]            = "xft:minecraftia:pixlesize=14";5�_�                      ,    ����                                                                                                                                                                                                                                                                                                                                                             _��     �         s      @static const char font[]            = "xft:minecraftia:size=14";5�_�                        +    ����                                                                                                                                                                                                                                                                                                                                                             _��    �   r   t           �   q   s          };�   p   r          O	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },�   o   q          O	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },�   n   p          O	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },�   m   o          O	{ ClkTagBar,            0,              Button1,        view,           {0} },�   l   n          O	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },�   k   m          O	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },�   j   l          O	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },�   i   k          [	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },�   h   j          O	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },�   g   i          ^	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },�   f   h          O	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },�   e   g          T	/* click                event mask      button          function        argument */�   d   f          static Button buttons[] = {�   c   e          W/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */�   b   d          /* button definitions */�   a   c           �   `   b          };�   _   a          B	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },�   ^   `          >	TAGKEYS(                        XK_9,                      8)�   ]   _          >	TAGKEYS(                        XK_8,                      7)�   \   ^          >	TAGKEYS(                        XK_7,                      6)�   [   ]          >	TAGKEYS(                        XK_6,                      5)�   Z   \          >	TAGKEYS(                        XK_5,                      4)�   Y   [          >	TAGKEYS(                        XK_4,                      3)�   X   Z          >	TAGKEYS(                        XK_3,                      2)�   W   Y          >	TAGKEYS(                        XK_2,                      1)�   V   X          >	TAGKEYS(                        XK_1,                      0)�   U   W          I	{ MODKEY,                       XK_Right,  shiftview,      {.i = +1 } },�   T   V          5	{ MODKEY,			XK_Left,   shiftview,      {.i = -1 } },�   S   U          I	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },�   R   T          I	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },�   Q   S          I	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },�   P   R          I	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },�   O   Q          J	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },�   N   P          J	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },�   M   O          B	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },�   L   N          >	{ MODKEY,                       XK_p,  setlayout,      {0} },�   K   M          Q	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },�   J   L          Q	{ MODKEY,                       XK_a,      setlayout,      {.v = &layouts[1]} },�   I   K          Q	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[0]} },�   H   J          B	{ MODKEY,                       XK_c,      killclient,     {0} },�   G   I          B	{ MODKEY,                       XK_Tab,    view,           {0} },�   F   H          B	{ MODKEY,                       XK_Return, zoom,           {0} },�   E   G          K	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },�   D   F          K	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },�   C   E          I	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },�   B   D          I	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },�   A   C          I	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },�   @   B          I	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },�   ?   A          B	{ MODKEY,                       XK_b,      togglebar,      {0} },�   >   @          J	{ MODKEY,                       XK_l,	   spawn,          {.v = sEtup } },�   =   ?          8	{ MODKEY,			XK_f,	   spawn,          {.v = firef0x } },�   <   >          N	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },�   ;   =          O	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },�   :   <          G	/* modifier                     key        function        argument */�   9   ;          static Key keys[] = {�   8   :          # include "shiftview.c"�   7   9           �   6   8           �   5   7           �   4   6           �   3   5          :static const char *sEtup[]    = { "urxvt","setup", NULL };�   2   4          4static const char *firef0x[]  = { "firefox", NULL };�   1   3          2static const char *termcmd[]  = { "urxvt", NULL };�   0   2          Astatic const char *dmenucmd[] = { "rofi", "-show", "run", NULL };�   /   1          /* commands */�   .   0           �   -   /          I#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }�   ,   .          C/* helper for spawning shell commands in the pre dwm-5.0 fashion */�   +   -           �   *   ,          N	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },�   )   +          P	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \�   (   *          P	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \�   '   )          P	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \�   &   (          #define TAGKEYS(KEY,TAG) \�   %   '          #define MODKEY Mod1Mask�   $   &          /* key definitions */�   #   %           �   "   $          };�   !   #          	{ "[M]",      monocle },�       "          J	{ "><>",      NULL },    /* no layout function means floating behavior */�      !          6	{ "[]=",      tile },    /* first entry is default */�                 "	/* symbol     arrange function */�                !static const Layout layouts[] = {�                 �                [static const Bool resizehints = True; /* True means respect size hints in tiled resizals */�                Lstatic const int nmaster      = 1;    /* number of clients in master area */�                Sstatic const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */�                /* layout(s) */�                 �                };�                G	{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },�                G	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },�                L	/* class      instance    title       tags mask     isfloating   monitor */�                static const Rule rules[] = {�                 �                lstatic const char *tags[] = { "h0me", "c0de", "w0rk", "mUsic", "chAt", "gAmez", "aRt", "sch00l", "br0wse" };�                /* tagging */�                 �                Lstatic const Bool topbar            = True;     /* False means bottom bar */�                Hstatic const Bool showbar           = True;     /* False means no bar */�                ?static const unsigned int snap      = 52;      /* snap pixel */�   
             Mstatic const unsigned int borderpx  = 1;        /* border pixel of windows */�   	             0static const char selfgcolor[]      = "#eeeeee";�      
          0static const char selbgcolor[]      = "#000000";�      	          0static const char selbordercolor[]  = "#005577";�                0static const char normfgcolor[]     = "#bbbbbb";�                0static const char normbgcolor[]     = "#222222";�                0static const char normbordercolor[] = "#444444";�                @static const char font[]            = "xft:Minecraftia:size=14";�                /* appearance */�                 �                 9/* See LICENSE file for copyright and license details. */5�_�                      +    ����                                                                                                                                                                                                                                                                                                                                                             _�}     �         s      <static const char font[]            = "minecraftia:size=14";5�_�                        (    ����                                                                                                                                                                                                                                                                                                                                                             _��     �         s      <static const char font[]            = "Minecraftia:size=14";5��