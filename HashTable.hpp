//Hash table of students; ID is used as the key.
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

struct Student{//Datum in studentList
  Student(const char* newFname, const char* newLname, int newId, float newGpa){
      fname = strcpy(new char[strlen(newFname) + 1], newFname);
      lname = strcpy(new char[strlen(newLname) + 1], newLname);
      id = newId;
      gpa = newGpa;
  }  
  char *fname;
  char *lname;
  int id;
  float gpa;
  void print(){
      //Prints student's information.
      cout << lname << ", " << fname << ". ID: " << id << "  GPA: ";
      cout << setprecision (2) << fixed << gpa << endl;
  }
  ~Student(){//These should be allocated on the heap
    delete[] fname;
    delete[] lname;
  }
};

struct Node{
    Node(Student* data) : data(data), next(0) {}
    ~Node(){
        //delete data;
    }
    Student* data;
    Node* next;
};

class HashTable{
   public:
    HashTable();
    ~HashTable();
    Student* getStudent(int id);
    void addStudent(char* fname, char* lname, int id, float gpa);
    bool deleteStudent(int id);
    void printStudentList();
   private: 
    Node** list;
    int size;
    int hash(int id);
    void addStudent(Student*);
};