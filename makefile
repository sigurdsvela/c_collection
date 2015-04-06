build:
	mkdir bin;\
	cd bin;\
	gcc -I../src -c ../tests/*.c ../src/*.h ../src/*.c;\
	gcc *.o -o build

clean:
	rm -rf bin

run:
	./bin/build
