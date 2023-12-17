CC = g++
CFLAGS = -Wall -Wextra -std=c++17
EXECUTABLE = extended_euclidean

# Add more source files here if needed
SOURCES = main.cpp Extended-Euclidean/Extended-Euclidean.cpp

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

