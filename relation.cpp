#include "relation.h"

Relation::Relation() { numRows = 0; }

void Relation::addColumns(Schema s) {
  columns = s;
}

void Relation::addRow(Tuple t) {
  // *** add a section to check for duplicates ***
  rows.push_back(t);
  numRows++;
}

Relation Relation::selectColumnValue(string column, string value) {
  Relation newTable;
  Schema newHeader;
  newTable.addColumns(this->columns);
  int columnIndex = this->columns.getIndexOf(column);

  for (int i = 0; i < numRows; i++) {
    Tuple tempTuple = getRowAt(i);
    if (tempTuple.getValueAt(columnIndex) == value) {
        newTable.addRow(tempTuple);
    }
  }
  return newTable;
}

Relation Relation::selectColumnColumn(string column1, string column2) {
  Relation newTable;
  Schema newHeader;
  int columnIndex1 = this->columns.getIndexOf(column1);
  int columnIndex2 = this->columns.getIndexOf(column2);
  newHeader.addAttribute(this->columns.getAttributeAt(columnIndex1));
  newHeader.addAttribute(this->columns.getAttributeAt(columnIndex2));

  for (int i = 0; i < numRows; i++) {
    Tuple tempTuple = getRowAt(i);
    if (tempTuple.getValueAt(columnIndex1) == tempTuple.getValueAt(columnIndex2)) {
        newTable.addRow(tempTuple);
    }
  }
  return newTable;
}

Schema Relation::getColumns() {
  return columns;
}

vector<Tuple> Relation::getRows() {
  return rows;
}

Tuple Relation::getRowAt(int i) {
  return rows.at(i);
}

string Relation::printColumns() {
    std::stringstream ss;
    ss << columns.toString();
    return ss.str();
}

string Relation::printRows() {
  std::stringstream ss;
  for (int i = 0; i < numRows; i++) {
    ss << rows.at(i).toString() << "\n";
  }
  return ss.str();
}
