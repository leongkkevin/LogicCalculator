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
    string statement = "((a ^ c) -> (a -> b)) ^ ((c v d) -> (a v d)) -> (a -> c)";
    vector<string> statement2;
    map<Statement, vector<int>> statementMap;
    f->parse2(statementMap, statement);

    /*
    vector<string> statements = parseStatement(statement);
    makeTables(statements);
     */

    //for (int i = 0; i < statements.size(); i++)
    //    cout << statements.at(i) << endl;

    map<Statement, vector<int>*>* thing = new map<Statement, vector<int>*>();
    Statement one("a");
    one.addStatement("a");
    Statement two("b");
    two.addStatement("b");
    Statement three("c");
    three.addStatement("c");
    Statement four("d");
    four.addStatement("d");
    Statement five("(a^b)");
    five.addStatement("a");
    five.addStatement("^");
    five.addStatement("b");
    Statement six("(cvd)");
    six.addStatement("c");
    six.addStatement("v");
    six.addStatement("d");
    Statement seven("(a^b)->(cvd)");
    seven.addStatement("(a^b)");
    seven.addStatement("->");
    seven.addStatement("(cvd)");
    vector<int>* temp5 = new vector<int>();
    thing->insert(pair<Statement, vector<int>*>(five, temp5));
    vector<int>* temp6 = new vector<int>();
    thing->insert(pair<Statement, vector<int>*>(six, temp6));
    vector<int>* temp7 = new vector<int>();
    thing->insert(pair<Statement, vector<int>*>(seven, temp7));
    vector<int>* temp1 = new vector<int>();
    thing->insert(pair<Statement, vector<int>*>(one, temp1));
    vector<int>* temp2 = new vector<int>();
    thing->insert(pair<Statement, vector<int>*>(two, temp2));
    vector<int>* temp3 = new vector<int>();
    thing->insert(pair<Statement, vector<int>*>(three, temp3));
    vector<int>* temp4 = new vector<int>();
    thing->insert(pair<Statement, vector<int>*>(four, temp4));

    f->addStatements(thing);
    f->makeTable(4);
}

