all: main

CXX = g++
override CXXFLAGS += -g -Wall
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LIBS)

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o $@ $(LIBS)

clean:
	rm -f main main-debug
