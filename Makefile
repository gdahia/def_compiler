CXX = g++

CXXFLAGS = -std=c++11 -O3 -Wall

INCLUDE = -I $(CURDIR)/include

all: scanner_demo.out

scanner_demo.out: build/scanner.o build/scanner_demo.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

build/scanner.o: src/scanner.cpp include/lex.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/scanner_demo.o: src/scanner_demo.cpp include/lex.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f build/*.o *.out
