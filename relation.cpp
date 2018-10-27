#include "relation.h"

Relation::Relation() {}

void Relation::addColumns(Schema s) {
  columns = s;
}

void Relation::addTuple(Tuple t) {
  rows.push_back(t);
}

//Relation Relation::select(string column, string value) {}

//Relation Relation::select(string column1, string column2) {}

string Relation::printColumns() {
    std::stringstream ss;
    ss << columns.toString();
    return ss.str();
}

string Relation::printRows() {
  std::stringstream ss;
  int size = rows.size();
  for (int i = 0; i < size; i++) {
    ss << rows.at(i).toString() << "\n";
  }
  return ss.str();
}
