CXX=g++
CXXFLAGS=-Wall -ggdb -Iinclude -Isrc -std=c++20
AR=/usr/bin/ar -r 

src := $(wildcard src/*.cpp)
obj := $(subst src, build, $(src:.cpp=.o))


.PHONY: directories

all: directories libgraph.a prog
	@echo $(obj)

prog: main.cpp libgraph.a 
	$(CXX) $(CXXFLAGS) $^ -o $@ 

libgraph.a: ${obj}
	${AR} $@ $^

build/%.o: src/%.cpp include/%.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<


directories: build
build:
	mkdir -p $@


clean: 
	rm prog
	rm libgraph.a
	rm -r build