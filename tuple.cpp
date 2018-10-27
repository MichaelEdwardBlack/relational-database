#include "tuple.h"

Tuple::Tuple() {}

void Tuple::addValue(string v) {
  tupleValues.push_back(v);
}

string Tuple::toString() {
  std::stringstream ss;
  int size = tupleValues.size();
  for (int i = 0; i < size; i++) {
    ss << tupleValues.at(i) << ",\t";
  }
  return ss.str();
}
