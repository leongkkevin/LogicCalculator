//
// Created by Kevin Leong on 4/14/21.
//

#include "Functions.h"
#include <iostream>
#include <fstream>

Functions::Functions() {

}

void Functions::readFile(string fileName) {
    ifstream file(fileName);
}

bool Functions::parseStatement(string line) {
    for (int i = 0; i < line.size(); i++) {
        // grab a character or statement
        char* temp = new char[10];
        temp[0] = line[i];
        if (temp[0] == '-') {
            i++;
            temp[1] = line[i];
        }
        else if (temp[0] == ' ') {
            i++;
            temp[0] = line[i];
        }


    }
}