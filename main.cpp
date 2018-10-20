#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"

using namespace std;

int main(int argc, char* argv[]) {

	//OPEN FILE/CHECK ERRORS
	ifstream in(argv[1]);
	//ofstream out(argv[2]); //uncomment this to use an output file

	Lexer myLexer;
	Parser myParser;

	myLexer.scan(in);

	try {
		myParser.parse(myLexer.getTokens());
		cout << myParser.toString();
	}
	catch (int error) {
		stringstream errorStream;
		errorStream << "Failure!" << endl << "  " << myLexer.getTokens()[error].toString() << endl;
		cout << errorStream.str();

		in.close();
		//out.close(); //uncomment this and to use output file
		return 0;
	}

	in.close();
	//out.close(); //uncomment this to use output file and change all couts to outs
	return 0;
}
