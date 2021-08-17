import pathlib
import cffi
import os


THIS_DIR = os.path.dirname(__file__)
print("------------")
print(THIS_DIR)
print("------------")

def read_header_file(filename):
    with open(filename) as h_file:
        content = h_file.read()
    return content

ffi = cffi.FFI()



lib = ffi.set_source(
    "_person",
    """
        #include "person.h"
    """,
    libraries=["person"],
    library_dirs=[os.path.join(THIS_DIR, "hash_table_lib")],
    include_dirs=[os.path.join(THIS_DIR, "hash_table_lib"), "/usr/include"],
    extra_link_args=["-Wl,-rpath,."],
    extra_compile_args=['-Werror', '-Wall']
)

ffi.cdef(read_header_file(os.path.join(THIS_DIR, "hash_table_lib", "person.h")))
if __name__ == "__main__":
    ffi.compile(verbose=1)
