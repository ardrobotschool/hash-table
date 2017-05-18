#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

/*
 * This program allows the user to work with a list of students; the user can add and delete an individual student.
 * Completed by Artur Drobot, May 2017. 
 */

int main(){
  char input[25]; //Input of command
  cout << "Enter \"ADD\" to add a new student entry, \"PRINT\" to print out the current list of students, or \"DELETE\" to delete a student entry." << endl;
  cout << "Enter \"q\" at any time to quit the program." << endl;
  HashTable hashTable;

  while (true){ //Primary loop
    cout << "Type a command: ";
    cin >> input;
    cout << endl;
    //Convert input to lower case
    int i = 0;
    while(input[i]){
      input[i] = tolower(input[i]);
      i++;
    }
    if(strcmp(input, "q") == 0){//quit
      //Deallocate stuff.
      return 0;
    }
    else if(strcmp(input, "add") == 0){
      char fname[32], lname[32];
      int id;
      float gpa;
      cout << "Enter the following information.\nFirst name: ";
      cin.getline(fname, 32);
      cout << "Last name: ";
      cin.getline(lname, 32);
      cout << "ID: ";
      cin >> id;
      cout << "GPA: ";
      cin >> gpa;
      hashTable.addStudent(fname, lname, id, gpa);
      cout << "Student added. << endl;
    }
    else if(strcmp(input, "print") == 0){
      hashTable.print();
    }
    else if(strcmp(input, "delete") == 0){
      int id;
      cout << "Enter ID: ";
      cin >> id;
      if(hashTable.deleteStudent(id)){
        cout << "Student deleted." << endl;
      }
      else{
        cout << "Student not found." << endl;
      }
    }
    else{
      cout << "Command not found." << endl;
    }
  }

}
