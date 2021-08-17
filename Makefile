all: compile bdist_wheel sdist 

compile:
	cd cffi_example && $(MAKE) compile

bdist_wheel:
	python setup.py sdist bdist_wheel

sdist:
	python setup.py sdist sdist


clean_build:
	rm -f -R ./build ./dist ./tomek_marstomek.egg-info ./.eggs ./__pycache__
	cd cffi_example && $(MAKE) clean

