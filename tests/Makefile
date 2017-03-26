make: cdef

cdef:
	flex -w -o cdef.yy.cpp cdef.l
	g++ -o cdef.out cdef.yy.cpp -lfl

clean:
	rm -rf cdef.yy.cpp cdef
