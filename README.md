# Python packages

## What we will learn here?

- How to create basic python bindings for C code using CFFI
- Whait is Python.h
- Difference between source distribution and wheel
- What is the meaning of wheel file name, what is python abi: {dist}-{version}(-{build})?-{python}-{abi}-{platform}.whl
- Why pypi prefer installing from wheel first and why it is easier for end user

## How to build this project

virtualenv -p python3 venv
source venv/bin/activate
make all

It compiles all modules, and modules are ready to install.



## Examples of python libs with c bindings in our project
psycopg2
https://github.com/psycopg/psycopg2


numpy
https://github.com/numpy/numpy



## More knowledge
Packaging and publishing projects official docs
https://packaging.python.org/tutorials/packaging-projects/


What are python wheels
https://realpython.com/python-wheels/


How to create python C bindings
https://realpython.com/python-bindings-overview/