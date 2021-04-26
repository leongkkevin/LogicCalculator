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
    string statement = "(((a ^ c) -> (a -> b)) ^ ((c v d) -> (a v d))) -> (a -> c)";
    vector<string> statement2;
    map<Statement, vector<int>*> statementMap;
    int numVariables = f->parse2(statementMap, statement);
    f->makeTable(numVariables);
}

