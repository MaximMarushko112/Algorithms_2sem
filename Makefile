CC=g++

CFLAGS=-c -Wall -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline \
          -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
		  -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
		  -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
		  -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith \
		  -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
		  -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: Test3.exe


Test3.exe: Test3.o Vector.o Stack_with_Vector.o
	$(CC) $^ -o $@

Test3.o: Test3.cpp Stack_with_Vector.cpp Stack_with_Vector.h Vector.cpp Vector.h
	$(CC) $(CFLAGS) $<

Stack_with_Vector.o: Stack_with_Vector.cpp Stack_with_Vector.h Vector.cpp Vector.h
	$(CC) $(CFLAGS) $<

Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.o Test3.exe
