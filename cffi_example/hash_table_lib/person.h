/*
@Author Tomasz Marszałek
*/
#pragma once

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;
} Person;



void init_hash_table();
int hash(char *name);
void print_table();
int add_person(const char *name, int age);
void print_person(char *name);
Person *hash_table_delete(char *name);
