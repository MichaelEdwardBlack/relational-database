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
