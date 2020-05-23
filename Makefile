﻿CC=g++
CFLAGS=-Wall -std=c++17
LDFLAGS=
SOURCES=main.cpp trapeze.h pentagon.h point.h templates.h rhombus.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=hello

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@