//
// Created by Kevin Leong on 4/14/21.
//

#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

int main(int argc, char** argv){
    //string file = argv[1];
    //Functions* f = new Functions();
    //f->readFile(file);
    string statement = "((a ^ c) -> (a -> b)) ^ (c v d)";
    //vector<string> statements = f->parseStatement(statement);
    //makeTables(statements);

    //for (int i = 0; i < statements.size(); i++)
    //    cout << statements.at(i) << endl;

    Statement* s = new Statement(statement);
    vector<char>* thing = new vector<char>();
    thing->push_back('a');
    thing->push_back('b');
    thing->push_back('c');
    thing->push_back('d');
    s->createTable(*thing);
    s->printChars();
}

