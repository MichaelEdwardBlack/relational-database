#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Tuple {
public:
	Tuple();
  void addValue(string v);
  string toString();
private:
	vector<string> tupleValues;
};
