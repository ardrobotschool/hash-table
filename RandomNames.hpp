#include <vector>

using namespace std;

class RandomNames{
    public:
      RandomNames(const char* fnames, const char* lnames);
      ~RandomNames();
      char* getFname();
      char* getLname();
      int getId();
      float getGpa();
    private:
      vector<char*> fnames;
      vector<char*> lnames;
      int id;
};