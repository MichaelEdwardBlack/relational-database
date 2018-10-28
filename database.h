#include <map>
#include <sstream>
#include "relation.h"
#include "parser.h"

using namespace std;

class Database {
public:
  Database();
  void doSchemes(vector<Predicate> schemes);
  void doFacts(vector<Predicate> facts);
  string printTables();
private:
  map<string, Relation> tables;
};
