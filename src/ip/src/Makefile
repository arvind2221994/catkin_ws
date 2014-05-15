ROOTDIR = ./
CFLAGS = `pkg-config --cflags opencv`
LIBS = `pkg-config --libs opencv`

.PHONY: all clean 

% : %.cpp
	g++ $(CFLAGS) $< -o $@ $(LIBS) 
