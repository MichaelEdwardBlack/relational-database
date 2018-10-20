#include"relation.h"

using namespace std;

class Database {
public:
  Database();
private:
  map<string, relation> relations;
};
