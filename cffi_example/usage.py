from _person import lib

lib.init_hash_table()
lib.add_person(b"Marek", 22)
lib.add_person(b"Arek", 15)

# It will not break C library, python catch integer overflow
try:
    lib.add_person(b"Darek", 4433333333333)
except Exception as e:
    print(f"Something went wrong...{e}")


lib.add_person(b"Joanna", 44)
lib.print_table()