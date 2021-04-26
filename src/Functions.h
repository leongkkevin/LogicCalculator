//
// Created by Kevin Leong on 4/14/21.
//

#ifndef LOGICCALCULATOR_FUNCTIONS_H
#define LOGICCALCULATOR_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>

#include "Statement.h"

using namespace std;

class Functions {
private:
    map<Statement, vector<int>*>* statements;
public:
Functions();

void makeTable(int);

void makeChars(vector<int>*, int, int);

void printTable();

void addStatements(map<Statement, vector<int>*>*);

void readFile(string&);

void parse2(map<Statement, vector<int>> &statementMap, string& line);

string getComplex(vector<string>&, vector<char>&, int);

vector<string> parseStatement(string&);

bool isChar(string);

bool isSimple(string);
};

#endif //LOGICCALCULATOR_FUNCTIONS_H
