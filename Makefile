CXX = g++

CXXFLAGS = -std=c++11 -O3 -Wall

INCLUDE = -I $(CURDIR)/include

all: build/scanner.o

build/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f build/*.o *.out
