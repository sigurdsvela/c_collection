build:
	mkdir bin;\
	cd bin;\
	gcc -c ../tests/*.c ../*.h ../*.c;\
	gcc *.o -o build

clean:
	rm -rf bin

run:
	./bin/build
