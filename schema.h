#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Schema {
public:
	Schema();
  void addAttribute(string a);
  string toString();
private:
	vector<string> schema;
};
