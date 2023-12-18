CC = g++
CFLAGS = -Wall -Wextra -std=c++17
EXECUTABLE = main

SOURCES = main.cpp \
Extended-Euclidean/Extended-Euclidean.cpp \
Chinese-Remainder/Chinese-Remainder.cpp \
Diffie-Hellman/Diffie-Hellman.cpp \
EL-Gamal/EL-Gamal.cpp \
Miller-Rabin/Miller-Rabin.cpp \
Elliptic-Curve/Elliptic-Curve.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@    

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
