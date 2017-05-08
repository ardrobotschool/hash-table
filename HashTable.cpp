#include <iostream>
#include "HashTable.hpp"

using namespace std;

int HashTable::hash(int id){
    return id % size;
}

Student* HashTable::getStudent(int id){
    Node* node = getNode(id);
    return node == 0 ? 0 : node->data;
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

Node* getNode(int id){
    Node* current = list[hash(id)];
    while(true){
       if(current == 0){
           return 0;
       }
       else if(current->data->id == id){
          return current; 
       }
       else{
           current = current->next;
       }
    }
}