CFLAGS = -O3
OBJECTS = dici.o io.o core.o
lzw: $(OBJECTS)

clean:
	rm -rf *.o *.gch

purge: clean
	rm -f lzw

remake: purge
	make
	make clean
