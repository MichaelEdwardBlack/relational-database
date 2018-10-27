#include <vector>
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
  Schema getColumns();
  vector<Tuple> getRows();
  Tuple getRowAt(int i);
  string printColumns();
  string printRows();
private:
	Schema columns;
  vector<Tuple> rows;
  int numRows;
};
