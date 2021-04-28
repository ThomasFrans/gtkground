all: build

build : gtkground.cpp

gtkground.cpp:
	g++ -o bin/MakeGUI src/InputPrompt.cpp src/main.cpp -Isrc/include `pkg-config --cflags --libs gtkmm-3.0`
	
clean:
	rm -r bin/*
