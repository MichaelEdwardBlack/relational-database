#include <vector>
#include "schema.h"
#include "tuple.h"

using namespace std;

class Relation {
public:
	Relation();
  void addColumns(Schema s);
  void addTuple(Tuple t);
  //Relation select(string column, string value);
  //Relation select(string column1, string column2);
  string printColumns();
  string printRows();
private:
	Schema columns;
  vector<Tuple> rows;
};
