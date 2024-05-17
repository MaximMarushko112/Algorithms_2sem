CC=g++

CFLAGS=-c -Wall -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline \
          -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default \
		  -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
		  -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op \
		  -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith \
		  -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits \
		  -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE -O0

all: Test_Generator.exe Answer_Generator.exe Tester.exe


Test_Generator.exe: Test_Generator.o
	$(CC) $^ -o $@

Test_Generator.o: Test_Generator.cpp
	$(CC) $(CFLAGS) $<

Answer_Generator.exe: Answer_Generator.o
	$(CC) $^ -o $@

Answer_Generator.o: Answer_Generator.cpp
	$(CC) $(CFLAGS) $<

Tester.exe: Tester.o Testing.o Quadratic_Sort.o Heap_Sort.o Merge_Sort.o SD_Sorts.o Q_Sort.o
	$(CC) $^ -o $@

Tester.o: Tester.cpp Testing.h Testing.cpp Quadratic_Sort.cpp Quadratic_Sort.h Heap_Sort.cpp Heap_Sort.h \
		  Merge_Sort.cpp Merge_Sort.h SD_Sorts.cpp SD_Sorts.h Q_Sort.cpp Q_Sort.h
	$(CC) $(CFLAGS) $<

Testing.o: Testing.cpp Testing.h
	$(CC) $(CFLAGS) $<

Quadratic_Sort.o: Quadratic_Sort.cpp Quadratic_Sort.h
	$(CC) $(CFLAGS) $<

Heap_Sort.o: Heap_Sort.cpp Heap_Sort.h
	$(CC) $(CFLAGS) $<

Merge_Sort.o: Merge_Sort.cpp Merge_Sort.h
	$(CC) $(CFLAGS) $<

SD_Sorts.o: SD_Sorts.cpp SD_Sorts.h
	$(CC) $(CFLAGS) $<

Q_Sort.o: Q_Sort.cpp Q_Sort.h
	$(CC) $(CFLAGS) $<

.PHONY: clean
clean:
	rm -rf *.o Tester.exe
