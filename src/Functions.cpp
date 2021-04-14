//
// Created by Kevin Leong on 4/14/21.
//

#include "Functions.h"
#include <iostream>
#include <fstream>

Functions::Functions() {}

void Functions::readFile(string& fileName) {
    ifstream file(fileName);
}

vector<string> Functions::parseStatement(string& line) {
    vector<string> statements;
    for (int i = 0; i < line.size(); i++) {
        // grab a character or statement
        char* temp = new char[10];
        temp[0] = line[i];
        if (line[i] == '-') {
            i++;
            temp[1] = line[i];
        }
        else if (line[i] == '=') {
            i++;
            temp[1] = line[i];
        }
        else if (line[i] == ' ') {
            continue;
        }

        statements.push_back(temp);
    }
    return statements;
}