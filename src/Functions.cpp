//
// Created by Kevin Leong on 4/14/21.
//

#include "Functions.h"
#include "Statement.h"
#include <iostream>
#include <fstream>

void readFile(string& fileName) {
    ifstream file(fileName);
}

/*
 * Iterative version of the parseStatement function, only goes up to "complex statements", i.e. "(a^b)->(cvd)"
 * An idea for the recursive version is some way to generalize the isChar and isSimple functions, maybe just using
 * length, or always parsing for certain characters in any statement that should be skipped over. 
 */
vector<string> parseStatement(string& line) {
    vector<string> statements;

    // loop through a single line and push back individual characters
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

    // index of the start of the simple statements
    int simpleStatementIndex = statements.size();

    // push back simple 2-variable statements that include the "->", "^", and "v" operator
    for(int i = 0; i < simpleStatementIndex; ++i){
        if(statements[i] == "->" || statements[i] == "^" || statements[i] == "v") {
            // only add simple statements if both sides of the operator are variables
            if (isChar(statements[i - 1]) && isChar(statements[i + 1])) {
                string newStatement;
                newStatement = statements[i - 1] + statements[i] + statements[i + 1];
                statements.push_back(newStatement);
            }
            else
                statements.push_back(statements[i]);
        }
    }

    // index of the start of the complex statements
    int complexStatementIndex = statements.size();

    // push back compound statements of things in parentheses joined by the "->", "^", and "v" operator
    for (int i = simpleStatementIndex; i < statements.size(); i++) {
        if(statements[i] == "->" || statements[i] == "^" || statements[i] == "v") {
            // only add complex statements if both sides of the operator are simple statements
            if (isSimple(statements[i - 1]) && isSimple(statements[i + 1])) {
                string newStatement;
                newStatement = "(" + statements[i - 1] + ")" + statements[i] + "(" + statements[i + 1] + ")";
                statements.push_back(newStatement);
            }
            else
                statements.push_back(statements[i]);
        }
    }

    // remove insignificant characters
    for (int i = 0; i < simpleStatementIndex; i++)
        if ((statements[i].size() == 1 || statements[i].size() == 2) && !isChar(statements[i])) {
            statements.erase(statements.begin() + i);
            i--;
        }

    return statements;
}

bool isChar(string thing) {
    return (thing.size() < 2 && thing[0] >= 97 && thing[0] <= 122 && thing[0] != 'v');
}

bool isSimple(string thing) {
    return (thing.size() > 2 && thing.size() < 5);
}

void makeTables(vector<string> statement) {
    vector<Statement> stateVect;
    for(int i = 0; i < statement.size(); ++i){
        stateVect.push_back(Statement(statement[i]));
    }
}
