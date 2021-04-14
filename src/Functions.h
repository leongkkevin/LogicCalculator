//
// Created by Kevin Leong on 4/14/21.
//

#ifndef LOGICCALCULATOR_FUNCTIONS_H
#define LOGICCALCULATOR_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Functions {
private:

public:
    Functions();

    void readFile(string&);

    vector<string> parseStatement(string&);
};


#endif //LOGICCALCULATOR_FUNCTIONS_H
