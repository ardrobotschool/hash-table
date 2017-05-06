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
  ~Student(){//These should be allocated on the heap
    delete[] fname;
    delete[] lname;
  }
};

class HashTable{
   public:
    Student* getStudent(int id);
    void addStudent(char* fname, char* lname, int id, float gpa);
    bool deleteStudent(int id);
    void printStudentList();
   private: 
    Student** list;
    int size;
    int hash(int id);
};