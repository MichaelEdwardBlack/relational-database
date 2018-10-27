#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"
#include "relation.h"

using namespace std;

int main(int argc, char* argv[]) {
	Relation students;
	Schema headers;
	headers.addAttribute("NAME");
	headers.addAttribute("AGE");
	headers.addAttribute("HOME TOWN");
	Tuple michael;
	michael.addValue("Michael");
	michael.addValue("24");
	michael.addValue("Colorado Springs");
	Tuple hollan;
	hollan.addValue("Hollan");
	hollan.addValue("21");
	hollan.addValue("Wilson");
	students.addColumns(headers);
	students.addTuple(michael);
	students.addTuple(hollan);
	cout << students.printColumns() << endl << students.printRows();

	return 0;
}
