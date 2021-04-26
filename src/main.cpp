//
// Created by Kevin Leong on 4/14/21.
//

#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

int main(int argc, char** argv){
    //string file = argv[1];
    //f->readFile(file);
    Functions* f = new Functions();
    string statement = "(((a ^ c) -> (a -> b)) ^ ((c ^ d) -> (a -> d))) -> (a -> c)";
    vector<string> statement2;
    map<Statement, vector<int>*> statementMap;
    int numVariables = f->parse2(statementMap, statement);
    f->makeTable(numVariables);

    ofstream outstream;
    outstream.open("../artifacts/output.csv");
    f->outputFile(statementMap, outstream);
    outstream.close();
}

