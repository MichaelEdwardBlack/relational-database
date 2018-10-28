#include <set>
#include "schema.h"
#include "tuple.h"

using namespace std;

class Relation {
public:
	Relation();
  void addColumns(Schema s);
  void addRow(Tuple t);
  Relation selectColumnValue(string column, string value);
  Relation selectColumnColumn(string column1, string column2);
	Relation project(Schema s);
	Schema getColumns();
  set<Tuple> getRows();
	void clear();
	string printColumns();
  string printRows();
private:
	Schema columns;
  set<Tuple> rows;
  int numRows;
};
