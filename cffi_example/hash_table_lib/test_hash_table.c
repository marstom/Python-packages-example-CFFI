#include <stdio.h>
#include "person.h"

// ----------- tests -------------------

void test_add_delete(){
    init_hash_table();
    add_person("Jacob", 256);
    add_person("Kate", 22);
    add_person("Mpho", 33);
    add_person("Sarah", 44);
    add_person("Jola", 55);
    add_person("Gita", 66); // collision
    add_person("Willard", 77);
    add_person("Samual", 88);
    add_person("John", 88); //collision
    hash_table_delete("Gita");
    print_table();
    print_person("Sarah");
}


void test_hash_function(){
    printf("%s\t\t%u\n", "tomeA", hash("tomeA"));
    printf("%s\t\t%u\n", "tomeB", hash("tomeB"));
    printf("%s\t\t%u\n", "tomeC", hash("tomeC"));
    printf("%s\t\t%u\n", "Natali", hash("Natali"));
    printf("%s\t%u\n", "Samantha", hash("Samantha"));
    printf("%s\t\t%u\n", "Jack", hash("Jack"));
    printf("%s\t\t%u\n", "A", hash("A"));
    printf("%s\t\t%u\n", "B", hash("B"));
    printf("%s\t\t%u\n", "C", hash("C"));
    printf("%s  %u\n", "Mark struggers", hash("Mark struggers"));
}


int main(){
    test_add_delete();
    test_hash_function();
    return 0;
}
