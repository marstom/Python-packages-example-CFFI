# https://packaging.python.org/tutorials/packaging-projects/
from setuptools import setup, find_packages

with open("README.md", "r", encoding="utf-8") as fh:
    long_description = fh.read()

setup(name='tomek-marstomek',
      version='0.0.7',
      description='My CFFI python example hash table',
      long_description=long_description,
      author='Tomasz Marszalek',
      author_email='marstomek@gmail.com',
      url='http://mt-software.info/',
      package_dir={"": "."},
      package_data= {'':['*.so']},
      packages=['cffi_example'], # can use : packages=setuptools.find_packages(where="."),
      options={"bdist_wheel": {"universal": False}},
      install_requires=["cffi"],
      setup_requires=["cffi", "pytest-runner"],
      cffi_modules=["cffi_example/hash_build.py:ffi"],
      tests_require = ["pytest"],
      python_requires=">=3.6",
      platforms=['linux'],
      classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: POSIX :: Linux",
    ],
     )
