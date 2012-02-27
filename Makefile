CXX=g++ -c
LD=g++
CFLAGS=-Wall -O2 `sdl-config --cflags` -g
LDFLAGS=`sdl-config --libs` -lGL -lGLU -g

SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

TARGET=StonedWeasel

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

src/main.o: src/main.cpp src/stonedweasel.h
	$(CXX) $(CFLAGS) -o $@ $<

src/stonedweasel.o: src/stonedweasel.cpp src/stonedweasel.h
	$(CXX) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o src/*.o $(TARGET)