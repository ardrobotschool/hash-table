#include <iostream>
#include "HashTable.hpp"

using namespace std;

int HashTable::hash(int id){
    return id % size;
}

Student* HashTable::getStudent(int id){
    Node* current = list[hash(id)];
    while(true){
       if(current == 0){
           return 0;
       }
       else if(current->data->id == id){
          return current->data; 
       }
       else{
           current = current->next;
       }
    }
}
