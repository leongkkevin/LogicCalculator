//
// Created by Kevin Leong on 4/16/21.
//

#ifndef LOGICCALCULATOR_STATEMENT_H
#define LOGICCALCULATOR_STATEMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <math.h>

using namespace std;

class Statement {
private:
    string name;
    vector<string>* statement;
    vector<int>* column;

public:
    Statement() = default;
    Statement(string name);

    void addStatement(string);

    string getName() const;

    vector<string>* getStatement();

    vector<int>* getColumn();

    bool operator<(const Statement&) const;
    bool operator==(const Statement&) const;
};


#endif //LOGICCALCULATOR_STATEMENT_H
