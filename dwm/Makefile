# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c dwm.c util.c
OBJ = ${SRC:.c=.o}

all: options dwm dwm-msg

options:
	@echo dwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

dwm-msg: dwm-msg.o
	${CC} -o $@ $< ${LDFLAGS}

dwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f dwm${CUSTOMNAME} dwm-msg dwm-msg.o ${OBJ} dwm${CUSTOMNAME}-${VERSION}.tar.gz

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwm ${DESTDIR}${PREFIX}/bin/dwm${CUSTOMNAME}
	cp -f dwm-msg ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm${CUSTOMNAME}
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm-msg
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm${CUSTOMNAME}.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm${CUSTOMNAME}.1
	mkdir -p ${XSESSIONSDIR}
	sed "s/CUSTOMNAME/${CUSTOMNAME}/g" < dwm.desktop > ${XSESSIONSDIR}/dwm${CUSTOMNAME}.desktop
	#cp -f dwm.desktop ${XSESSIONSDIR}/dwm${CUSTOMNAME}.desktop
	chmod 644 ${XSESSIONSDIR}/dwm${CUSTOMNAME}.desktop

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm${CUSTOMNAME}\
	  ${DESTDIR}${PREFIX}/bin/dwm-msg\
		${DESTDIR}${MANPREFIX}/man1/dwm${CUSTOMNAME}.1\
		${XSESSIONSDIR}/dwm${CUSTOMNAME}.desktop

.PHONY: all options clean install uninstall
