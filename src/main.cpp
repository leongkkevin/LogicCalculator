//
// Created by Kevin Leong on 4/14/21.
//

#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

int main(int argc, char** argv){
    Functions* f = new Functions();

    //TEST statement: (((a ^ c) -> (a -> b)) ^ ((c ^ d) -> (a -> d))) -> (a -> c)
    cout << "Hello! Welcome to the ALMIGHTY TRUTH TABLE GENERATOR!" << endl;
    cout << "Type any logical statement and find a perfectly crafted truth table in the artifacts folder (output.csv)." << endl;
    cout << "NOTE: Use of parentheses is extremely important for this generator. Please refer to the README file for more information. \n" << endl;
    cout << "Please put a logical statement below: " << endl;
    string statement;
    getline(cin, statement);
    vector<string> statement2;
    map<Statement, vector<int>*> statementMap;
    int numVariables = f->parse2(statementMap, statement);
    f->makeTable(numVariables);

    ofstream outstream;
    outstream.open("../artifacts/output.csv");
    f->outputFile(statementMap, outstream);
    outstream.close();

    cout << "The output has been saved in the output.csv file in the artifacts folder. Thank you!" << endl;
}

