CXX = g++

CXXFLAGS = -std=c++11 -O3 -Wall

INCLUDE = -I $(CURDIR)/include

all: def_compiler.out

def_compiler.out: build/parser.o build/ast.o build/scanner.o build/def_compiler.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

build/scanner.o: src/scanner.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/parser.o: src/parser.cpp include/parser.hpp include/ast.hpp include/holder.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

src/scanner.cpp: src/lex.l
	lex -o $@ $<

src/parser.cpp: src/grammar.y
	bison -d -o $@ $<

include/parser.hpp: src/parser.cpp
	mv src/parser.hpp $@

build/%.o: src/%.cpp include/%.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/def_compiler.o: src/def_compiler.cpp include/parser.hpp include/ast.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -f build/*.o *.out src/parser.cpp src/scanner.cpp include/parser.hpp
