TARGET=HexagonEngine

CC      = gcc
CFLAGS  = -fPIC -g -O0 -D DEBUG -Wall -Wextra #-Werror
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lstdc++
RM      = rm -f

SOURCES = $(shell find src/ -name "*.cpp")
OBJECTS = $(SOURCES:%.cpp=%.cpp.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): %.cpp.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET)
	$(RM) $(OBJECTS)

