CFLAGS += -Wall -Wextra -Iinstall_dir/include
LDFLAGS += -L../install_dir/include/libSDL2 -lm install_dir/lib/libSDL2.so
CC = gcc

sokoban : main.o grid.o player.o sdl2.o
	$(CC) -g $(CFLAGS) main.o grid.o player.o sdl2.o $(LDFLAGS) -o sokoban

main.o : main.c grid.h player.h sdl2.h
	$(CC) -g $(CFLAGS) -c main.c 

grid.o : grid.c grid.h player.h
	$(CC) -g $(CFLAGS) -c grid.c 

player.o : player.c player.h grid.h sdl2.h
	$(CC) -g $(CFLAGS) -c player.c

sdl2.o : sdl2.c sdl2.h grid.h
	$(CC) -g $(CFLAGS) -c sdl2.c 

sdl2 : 
	cd SDL2 && sh ./configure --prefix=$$PWD/../install_dir 
	cd SDL2 && make install -j6

LEVELS = $(wildcard level*.txt)

web : build/index.html

build/index.html : main.c grid.c player.c sdl2.c grid.h player.h sdl2.h web/shell.html $(LEVELS)
	mkdir -p build
	emcc -Wall -Wextra -O2 main.c grid.c player.c sdl2.c -sUSE_SDL=2 -sASYNCIFY -sEXIT_RUNTIME=1 $(foreach f,$(LEVELS),--preload-file $(f)) --shell-file web/shell.html -o build/index.html

archive : 
	tar -cf BARTZ_Cyril.tar.gz main.c grid.c grid.h player.c player.h sdl2.c sdl2.h Makefile level1.txt README.md Doxyfile

doc : 
	doxygen
	rm -rf latex/
	xdg-open html/index.html

clean : 
	rm -f *.o sokoban 
	rm -rf install_dir
	rm -rf html
	rm -rf build

