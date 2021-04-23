//
// Created by Kevin Leong on 4/16/21.
//

#ifndef LOGICCALCULATOR_STATEMENT_H
#define LOGICCALCULATOR_STATEMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

class Statement {
private:
    map<char, vector<int>>* table;
    string name;

public:
    Statement() = default;
    Statement(string name);
    void createTable(vector<char>&);
    void printChars();

    string getName() const;

    bool operator<(const Statement&) const;
    bool operator==(const Statement&) const;
};


#endif //LOGICCALCULATOR_STATEMENT_H
