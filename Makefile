all:bin/prog

bin/prog: build/main.o build/foo.o 
	gcc build/main.o build/foo.o -o bin/prog -lm 

build/main.o: src/main.c src/foo.h
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/foo.o: src/foo.c src/foo.h
	gcc -Wall -Werror -c src/foo.c -o build/foo.o

clean: 
	rm -rf Vivod bin/prog build/*.o	

.PHONY: all clean
