# dwm version
VERSION = 6.4 - ba56fe9fea0a28d8184a727a987836a0903e2682

# Customize below to fit your system

#append a custom name to the DWM binary for multiple installations
CUSTOMNAME = 

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man
XSESSIONSDIR = /usr/share/xsessions

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# Xinerama, comment if you don't want it
XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA

# freetype
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2
# OpenBSD (uncomment)
#FREETYPEINC = ${X11INC}/freetype2
#MANPREFIX = ${PREFIX}/man

# yajl
YAJLLIBS = -lyajl
YAJLINC = /usr/include/yajl

# includes and libs
INCS = -I${X11INC} -I${FREETYPEINC} -I${YAJLINC}
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS} ${YAJLLIBS} -lXrender

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=200809L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
#CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Wno-incompatible-pointer-types -Os ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}

# Solaris
#CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
#LDFLAGS = ${LIBS}

# compiler and linker
CC = cc
