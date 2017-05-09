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

void HashTable::printStudentList(){
    for(int i = 0; i < size; i++){
        Node* current = list[i];
        while(current != 0){
            current->data->print();
            current = current->next;
        }
    }
}

bool HashTable::deleteStudent(int id){
    Node** current = &list[hash(id)];
    while(*current != 0){
        if((*current)->data->id == id){
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            return true;
        }
        else{
           current = &((*current)->next); 
        } 
    }
    return false;
}