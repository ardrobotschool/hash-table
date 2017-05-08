//Hash table of students; ID is used as the key.

struct Student{//Datum in studentList
  Student(const char* newFname, const char* newLname, int id, float gpa){
      fname = strcpy(new char[strlen(newFname) + 1], newFname);
      lname = strcpy(new char[strlen(newLname) + 1], newLname);
      id = id;
      gpa = gpa;
  }  
  char *fname;
  char *lname;
  int id;
  float gpa;
  void print(){
      //Prints student's information.
      cout << lname << ", " << fname << ". ID: " << id << "  GPA: " << gpa;
  }
  ~Student(){//These should be allocated on the heap
    delete[] fname;
    delete[] lname;
  }
};

struct Node{
    Node(Student* data) : student(data), next(0) {}
    ~Node(){
        delete data;
    }
    Student* data;
    Node* next;
}

class HashTable{
   public:
    Student* getStudent(int id);
    void addStudent(char* fname, char* lname, int id, float gpa);
    bool deleteStudent(int id);
    void printStudentList();
   private: 
    Node** list;
    int size;
    int hash(int id);
};