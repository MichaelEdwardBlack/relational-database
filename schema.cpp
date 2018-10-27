#include "schema.h"

Schema::Schema() { numAttributes = 0; }

void Schema::addAttribute(string a) {
  schema.push_back(a);
  numAttributes++;
}

int Schema::getIndexOf(string s) {
  for (int i = 0; i < numAttributes; i++) {
    if (schema.at(i) == s) {
      return i;
    }
  }
  return -1; // error
}

int Schema::size() {
  return numAttributes;
}

string Schema::getAttributeAt(int i) {
  return schema.at(i);
}

string Schema::toString() {
  std::stringstream ss;
  int size = schema.size();
  for (int i = 0; i < size; i++) {
    ss << schema.at(i) << ",\t";
  }
  return ss.str();
}
