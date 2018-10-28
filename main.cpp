#include <iostream>
#include <fstream>
#include <sstream>
#include "database.h"

using namespace std;

int main(int argc, char* argv[]) {
	//OPEN FILE/CHECK ERRORS
	ifstream in(argv[1]);

	Lexer myLexer;
	Parser myParser;
	Database myDatabase;

	myLexer.scan(in);
	myParser.parse(myLexer.getTokens());
	myDatabase.doSchemes(myParser.getSchemes());
	myDatabase.doFacts(myParser.getFacts());
	cout << myDatabase.printTables() << endl;

	in.close();
	return 0;
}
