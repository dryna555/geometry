FLAGS = -Wall -Werror


all: bin build bin/geom bin/test

#src

bin/geom: build/src/main.o build/src/foo.o
	gcc $(FLAGS) build/src/main.o build/src/foo.o -o bin/geom -lm

build/src/main.o: src/main.c
	gcc $(FLAGS) -c src/main.c -o build/src/main.o

build/src/foo.o: src/foo.c
	gcc $(FLAGS) -c src/foo.c -o build/src/foo.o

#test

bin/test: build/test/main.o build/test/foo.o build/src/foo.o
	gcc $(FLAGS) build/test/main.o build/test/foo.o build/src/foo.o -o bin/test -lm

build/test/main.o: test/main.c
	gcc $(FLAGS) -c test/main.c -o build/test/main.o
build/test/foo.o: test/foo.c
	gcc $(FLAGS) -c test/foo.c -o build/test/foo.o


run: all
	./bin/test
	./bin/geom

.PHONY: clean all run

clean:
	rm -rf bin/geom bin/test build/src/*.o build/test/*.o
