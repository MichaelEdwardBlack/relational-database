#include "database.h"

Database::Database() {};

void Database::doSchemes(vector<Predicate> schemes) {
  Relation tempTable;
  string tableName;
  Schema tempHeaders;
  int numSchemes = schemes.size();
  int numAttributes;
  vector<string> attributes;
  for (int i = 0; i < numSchemes; i++) {
    tempTable.clear();
    tempHeaders.clear();
    tableName = schemes.at(i).getName();
    attributes = schemes.at(i).getParameters();
    numAttributes = attributes.size();
    for (int j = 0; j < numAttributes; j++) {
      tempHeaders.addAttribute(attributes.at(j));
    }
    tempTable.addColumns(tempHeaders);
    this->tables.insert({tableName, tempTable});
  }
}

void Database::doFacts(vector<Predicate> facts) {
  string tableName;
  Tuple row;
  vector<string> tupleValues;
  int numTupleValues;
  int numFacts = facts.size();
  for (int i = 0; i < numFacts; i++) {
    row.clear();
    tupleValues.clear();
    tableName = facts.at(i).getName();
    tupleValues = facts.at(i).getParameters();
    numTupleValues = tupleValues.size();
    for (int j = 0; j < numTupleValues; j++) {
      row.push_back(tupleValues.at(j));
    }
    this->tables[tableName].addRow(row);
  }
}

string Database::printTables() {
  stringstream ss;
  for (map<string, Relation>::iterator it = this->tables.begin(); it != this->tables.end(); it++) {
    ss << it->first << "\n";
    ss << it->second.printColumns() << "\n";
    ss << it->second.printRows() << "\n";
  }
  return ss.str();
}
