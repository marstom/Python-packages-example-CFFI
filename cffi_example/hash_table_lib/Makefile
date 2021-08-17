test:
	gcc ./person.c test_hash_table.c -o test.out
	./test.out
	rm ./test.out


lib:
	gcc -c -fpic person.c  -I "/usr/include/python3.7"
	# gcc -shared -o libperson.so person.o
	ar rcs libperson.a person.o

clean:
	rm -rf *.a *.o *.out *.so