CXX = clang++

CXXFLAGS = -std=c++11 -O3 -Wall

INCLUDE = -I $(CURDIR)/include

all: def_compiler.out

def_compiler.out: build/parser.o build/ast.o build/codegen.o build/semantic.o build/symbol_table.o build/scanner.o build/def_compiler.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

build/scanner.o: src/scanner.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/parser.o: src/parser.cpp include/parser.hpp include/ast.hpp include/holder.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/symbol_table.o: src/symbol_table.cpp include/symbol_table.hpp include/parser.hpp include/ast.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/ast.o: src/ast.cpp include/ast.hpp include/symbol_table.hpp include/parser.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/semantic.o: src/semantic.cpp include/ast.hpp include/symbol_table.hpp include/parser.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

build/codegen.o: src/codegen.cpp include/ast.hpp include/symbol_table.hpp include/parser.hpp
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
	@rm -f build/*.o *.out

wipe: clean
	src/parser.cpp src/scanner.cpp include/parser.hpp
