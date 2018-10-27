#include "schema.h"

Schema::Schema() {}

void Schema::addAttribute(string a) {
  schema.push_back(a);
}

string Schema::toString() {
  std::stringstream ss;
  int size = schema.size();
  for (int i = 0; i < size; i++) {
    ss << schema.at(i) << ",\t";
  }
  return ss.str();
}
