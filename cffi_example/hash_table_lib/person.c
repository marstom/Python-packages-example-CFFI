/*
@Author Tomasz Marszałek

Hash table is:
- array with hash function
- hash table with linked list!


*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "person.h"


Person *hash_table[TABLE_SIZE];

void init_hash_table(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    
}


int hash(char *name){
    int length = strlen(name);
    int hash_value = 0;
    for(int i = 0; i < length; i++){
        hash_value += name[i];
        hash_value *= name[i];
        hash_value %= TABLE_SIZE;
    }
    
    return hash_value;
}


void print_table() {
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hash_table[i] == NULL){
            printf("\t%i\t---\n", i);
        }
        else{
            printf("\t%i\t", i);
            Person *tmp = hash_table[i];
            while(tmp != NULL){
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    
}


int hash_table_insert(Person *p){
    if(p == NULL) return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return 1;
}


int add_person(const char *name, int age){
    Person *p = malloc(sizeof(Person));
    strcpy(p->name, name);
    p->age = age;
    if(hash_table_insert(p)){
	    return 1;
    }else{
        free(p);
        return 0;
    }
}


Person *hash_table_lookup(char *name){
    int index = hash(name);
    Person *tmp = hash_table[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) !=0){
        tmp = tmp->next;
    }
    return tmp;
}


Person *hash_table_delete(char *name){
    int index = hash(name);
    Person *tmp = hash_table[index];
    Person *prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) !=0){
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL) return NULL;
    if(prev == NULL) {
        //deleteng the head
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
    
}


void print_person(char *name){
    Person *tmp =  hash_table_lookup(name);
    if(tmp !=NULL){
        printf("name: %s age: %i\n", tmp->name, tmp->age);
    }else{
        printf("Not found\n");
    }
}
