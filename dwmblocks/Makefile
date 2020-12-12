PREFIX ?= /usr/local
SCRIPTSPATH = /env/scripts
CC ?= cc

output: dwmblocks.c blocks.def.h blocks.h
	${CC} `pkg-config --cflags x11 --libs x11` dwmblocks.c -o dwmblocks

blocks.h:
	cp blocks.def.h $@

clean:
	rm -f *.o *.gch dwmblocks

scripts:
	mkdir -p $(SCRIPTSPATH)
	cp -f ./scripts/* $(SCRIPTSPATH)

install: output
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 dwmblocks $(DESTDIR)$(PREFIX)/bin/dwmblocks

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/dwmblocks
