#include <iostream>
#include "HashTable.hpp"

using namespace std;

HashTable::HashTable(){
    size = 100;
    list = new Node*[100];
}

HashTable::~HashTable(){
    for(int i = 0; i<size; i++){
        Node* current = list[i];
        while(current){
            Node* temp = current;
            current = current->next;
            delete current->data;
            delete current;
        }
    }
    delete list;
}

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
            delete temp->data;
            delete temp;
            return true;
        }
        else{
           current = &((*current)->next); 
        } 
    }
    return false;
}

void HashTable::addStudent(char *fname, char *lname, int id, float gpa){
    Node** current = &list[hash(id)];
    int count = 0;
    while(*current != 0){
        current = &(*current)->next;
        count++;
    }
    if(count >= 3){
        //Double array size!
        size *= 2;
        Node** old = list;
        list = new Node*[size];
        for(int i = 0; i < size/2; i++){
            Node* current = old[i];
            while(current){
                addStudent(current->data);
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] old;
        addStudent(fname, lname, id, gpa);
    }
    else{
        *current = new Node(new Student(fname, lname, id, gpa));
    }
}

void HashTable::addStudent(Student* student){
    addStudent(student->fname, student->lname, student-> id, student->gpa);
    delete student;
}

