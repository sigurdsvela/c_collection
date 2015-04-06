build-test:
	gcc -c ./tests/*.c ./*.h ./*.c

run-tests:
	./a.out
