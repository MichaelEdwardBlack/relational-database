#include <iostream>
#include <fstream>
#include <sstream>
#include "database.h"

using namespace std;

int main(int argc, char* argv[]) {
	Relation students;
	Schema headers;
	headers.addAttribute("NAME");
	headers.addAttribute("AGE");
	headers.addAttribute("CLASS");
	Tuple michael;
	michael.push_back("Michael");
	michael.push_back("24");
	michael.push_back("Junior");
	Tuple hollan;
	hollan.push_back("Hollan");
	hollan.push_back("21");
	hollan.push_back("Senior");
	Tuple sean;
	sean.push_back("Sean");
	sean.push_back("21");
	sean.push_back("Sophomore");
	Tuple arthur;
	arthur.push_back("Arthur");
	arthur.push_back("19");
	arthur.push_back("Freshman");
	Tuple sidney;
	sidney.push_back("Sidney");
	sidney.push_back("19");
	sidney.push_back("Sophomore");
	Tuple nicole;
	nicole.push_back("Nicole");
	nicole.push_back("23");
	nicole.push_back("Senior");
	students.addColumns(headers);
	students.addRow(michael);
	students.addRow(hollan);
	students.addRow(sean);
	students.addRow(arthur);
	students.addRow(sidney);
	students.addRow(nicole);

	Relation students_21 = students.selectColumnValue("AGE","21");
	cout << "Students that are 21 years old" << endl;
	cout << students_21.printColumns() << endl << students_21.printRows();

	Relation midterms;
	Schema examNumbers;
	examNumbers.addAttribute("STUDENT");
	examNumbers.addAttribute("EXAM_1");
	examNumbers.addAttribute("EXAM_2");
	examNumbers.addAttribute("EXAM_3");
	examNumbers.addAttribute("EXAM_4");
	Tuple mike;
	mike.push_back("mike");
	mike.push_back("85");
	mike.push_back("90");
	mike.push_back("85");
	mike.push_back("107");
	Tuple holly;
	holly.push_back("holly");
	holly.push_back("99");
	holly.push_back("90");
	holly.push_back("99");
	holly.push_back("92");
	Tuple sam;
	sam.push_back("sam");
	sam.push_back("100");
	sam.push_back("82");
	sam.push_back("88");
	sam.push_back("79");
	Tuple adam;
	adam.push_back("adam");
	adam.push_back("89");
	adam.push_back("92");
	adam.push_back("94");
	adam.push_back("82");
	Tuple sarah;
	sarah.push_back("sarah");
	sarah.push_back("77");
	sarah.push_back("89");
	sarah.push_back("82");
	sarah.push_back("94");
	Tuple marlee;
	marlee.push_back("marlee");
	marlee.push_back("82");
	marlee.push_back("85");
	marlee.push_back("88");
	marlee.push_back("90");
	midterms.addColumns(examNumbers);
	midterms.addRow(mike);
	midterms.addRow(holly);
	midterms.addRow(sam);
	midterms.addRow(adam);
	midterms.addRow(sarah);
	midterms.addRow(marlee);

	Relation exams_1_3 = midterms.selectColumnColumn("EXAM_1","EXAM_3");
	cout << "Showing scores where exam 1 is the same as exam 2" << endl;
	cout << exams_1_3.printColumns() << endl << exams_1_3.printRows();

	Schema projHeaders;
	projHeaders.addAttribute("STUDENT");
	projHeaders.addAttribute("EXAM_1");
	projHeaders.addAttribute("EXAM_4");
	Relation firstAndLastExams = midterms.project(projHeaders);
	cout << "Projecting just the first and last exams of all students" << endl;
	cout << firstAndLastExams.printColumns() << endl << firstAndLastExams.printRows();

	return 0;
}
