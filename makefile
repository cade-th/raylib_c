CXX = clang++
CXXFLAGS = -lraylib

# Target and command
all: main

# Compile and link the program
main: main.cpp
	$(CXX) main.cpp -o main $(CXXFLAGS)

# Clean up the build
clean:
	rm -f main

