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

void makeTables(vector<string> statement);

void readFile(string&);

vector<string> parseStatement(string&);

bool isChar(string);

bool isSimple(string);


#endif //LOGICCALCULATOR_FUNCTIONS_H
