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
    string name;
    vector<int>* column;

public:
    Statement() = default;
    Statement(string name);

    string getName() const;

    bool operator<(const Statement&) const;
    bool operator==(const Statement&) const;
};


#endif //LOGICCALCULATOR_STATEMENT_H
