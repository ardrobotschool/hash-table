#include <iostream>
#include "HashTable.hpp"

using namespace std;

int HashTable::hash(int id){
    return id % size;
}

Student* HashTable::getStudent(int id){
    return list[hash(id)];
}

