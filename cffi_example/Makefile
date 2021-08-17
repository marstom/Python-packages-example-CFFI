compile:
	cd hash_table_lib && $(MAKE) lib
	# cp ./hash_table_lib/libperson.so ./libperson.so
	python hash_build.py

clean:
	rm -rf *.o *.out *.s *.so
	rm -Rf ./__pycache__
	cd hash_table_lib && $(MAKE) clean
	rm -f _person.c


virtualenv:
	virtualenv venv -p python3.9
	source ./venv/bin/activate
	which python
