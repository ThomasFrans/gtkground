all: build

build : gtkground.c

gtkground.c:
	gcc -o bin/gtkground src/main.c `pkg-config --cflags --libs gtk+-3.0`
	
clean:
	rm -r bin/*
