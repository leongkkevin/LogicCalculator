//
// Created by Kevin Leong on 4/16/21.
//

#ifndef LOGICCALCULATOR_STATEMENT_H
#define LOGICCALCULATOR_STATEMENT_H

#include <vector>
#include <string>

using namespace std;

class Statement {
private:
    vector<char> variables;
    vector<vector<int>> table;
    string name;

public:
    Statement() = default;
    Statement(string name);
    void createTable();




};


#endif //LOGICCALCULATOR_STATEMENT_H
