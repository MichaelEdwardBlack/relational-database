#include <map>
#include "relation.h"
#include "parser.h"

using namespace std;

class Database {
public:
  Database();
  void doSchemes(vector<Predicate> schemes);
private:
  map<string, Relation> tables;
};
