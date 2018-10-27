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
	headers.addAttribute("CLASS");
	Tuple michael;
	michael.addValue("Michael");
	michael.addValue("24");
	michael.addValue("Junior");
	Tuple hollan;
	hollan.addValue("Hollan");
	hollan.addValue("21");
	hollan.addValue("Senior");
	Tuple sean;
	hollan.addValue("Sean");
	hollan.addValue("21");
	hollan.addValue("Sophomore");
	Tuple arthur;
	hollan.addValue("Arthur");
	hollan.addValue("19");
	hollan.addValue("Freshman");
	Tuple sidney;
	hollan.addValue("Sidney");
	hollan.addValue("19");
	hollan.addValue("Sophomore");
	Tuple nicole;
	hollan.addValue("Nicole");
	hollan.addValue("23");
	hollan.addValue("Senior");
	students.addColumns(headers);
	students.addRow(michael);
	students.addRow(hollan);
	students.addRow(sean);
	students.addRow(arthur);
	students.addRow(sidney);
	students.addRow(nicole);

	cout << students.printColumns() << endl << students.printRows();

	return 0;
}
