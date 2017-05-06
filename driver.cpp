#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

/*
 * This program allows the user to work with a list of students; the user can add and delete an individual student.
 * Completed by Artur Drobot, May 2017. 
 */

struct Student{//Datum in studentList
  char *fname;
  char *lname;
  int id;
  float gpa;
  ~Student(){//These were made using the new operator:
    delete[] fname;
    delete[] lname;
  }
};

//Function prototypes
void printStudentList(vector<Student*> studentList);
void deleteStudent(vector<Student*> &studentList);

int main(){
  vector<Student*> studentList;
  char input[25]; //Input of command
  cout << "Enter \"ADD\" to add a new student entry, \"PRINT\" to print out the current list of students, or \"DELETE\" to delete a student entry." << endl;
  cout << "Enter \"q\" at any time to quit the program." << endl;

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
      //Wipe everything the contents of the vector point to.
      for(vector<Student*>::iterator it = studentList.begin(); it != studentList.end(); it++){
	delete (*it);
      }
      //The vector itself should be removed automatically.
      return 0;
    }
    else if(strcmp(input, "add") == 0){
      studentList.push_back(getStudentPointer());
    }
    else if(strcmp(input, "print") == 0){
      printStudentList(studentList);
    }
    else if(strcmp(input, "delete") == 0){
      deleteStudent(studentList);
    }
    else{
      cout << "Command not found." << endl;
    }
  }


  //studentList.push_back(ptr);
  //cout << studentList[0]->fname << endl;
}

Student* getStudentPointer(){
  
}

void printStudentList(vector<Student*> studentList){//
  
}

void deleteStudent(int id){//
  
}