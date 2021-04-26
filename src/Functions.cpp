//
// Created by Kevin Leong on 4/14/21.
//

#include "Functions.h"
#include "Statement.h"
#include <iostream>
#include <fstream>
#include <set>

Functions::Functions() {
    statements = new map<Statement, vector<int>*>();
}

void Functions::readFile(string& fileName) {
    ifstream file(fileName);
}

string Functions::getComplex(vector<string> &complexStats, vector<char> &charVect, int index){
    string returnStatement;
    for(int i = index; i < charVect.size(); ++i){
        if(charVect[i] == '('){
            string paranthStr = getComplex(complexStats, charVect, i + 1);
            charVect[i] = '[';
            complexStats.push_back(paranthStr);
            paranthStr.clear();
        }
        if(charVect[i] == ')'){
            string op;
            charVect[i] = ']';
            return returnStatement;
        }
        returnStatement += charVect[i];
    }
    complexStats.push_back(returnStatement);
    return returnStatement;
}
void Functions::parse2(map<Statement, vector<int>*> &statementMap, string& line){
    set<char> simple;
    vector<char> allChar;
    for(int i = 0; i < line.size(); ++i){
        if(isalpha(line[i]) && line[i] != 'v'){
            simple.insert(line[i]);

            string newStr;
            newStr += line[i];
            Statement newStatement(newStr);
            vector<int>* emptyVect = new vector<int>();
            statementMap.insert({newStatement, emptyVect});
        }
        allChar.push_back(line[i]);
    }

    vector<string> complexStatements;
    getComplex(complexStatements, allChar, 0);
    for(int i = 0; i < complexStatements.size(); ++i){
        Statement newStatement(complexStatements[i]);
        vector<int>* emptyVect = new vector<int>();
        statementMap.insert({newStatement, emptyVect});
    }
    addStatements(&statementMap);
}

/*
 * Iterative version of the parseStatement function, only goes up to "complex statements", i.e. "(a^b)->(cvd)"
 * An idea for the recursive version is some way to generalize the isChar and isSimple functions, maybe just using
 * length, or always parsing for certain characters in any statement that should be skipped over. 
 */
vector<string> Functions::parseStatement(string& line) {
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

bool Functions::isChar(string thing) {
    return (thing.size() < 2 && thing[0] >= 97 && thing[0] <= 122 && thing[0] != 'v');
}

bool Functions::isSimple(string thing) {
    return (thing.size() > 2 && thing.size() < 5);
}

/*
 * Makes a table given the number of simple variables and the class map of statements
 */
void Functions::makeTable(int numVars) {
    int charNum = 1;
    for (auto& itr : *statements) {
        // if the statement is a variable
        if (itr.first.getName().size() == 1) {
            makeChars(itr.second, numVars, charNum);
            charNum++;
        }
        else {
            // handle for the complex statements here
            Statement statement = itr.first;
            vector<string> *pieces = statement.getStatement();

            vector<int>* firstStatement = statements->at(pieces->at(0));
            string joiner = pieces->at(1);
            vector<int>* secondStatement = statements->at(pieces->at(2));

            for (int i = 0; i < firstStatement->size(); i++) {
                if (joiner == "^")
                    itr.second->push_back((firstStatement->at(i) && secondStatement->at(i)) ? 1 : 0);
                else if (joiner == "v")
                    itr.second->push_back((firstStatement->at(i) || secondStatement->at(i)) ? 1 : 0);
                else if (joiner == "->")
                    itr.second->push_back((!firstStatement->at(i) || firstStatement->at(i) == secondStatement->at(i)) ? 1 : 0);
            }
        }
    }
    printTable();
}

/*
 * This method is called if a Statement in the map consists of a single
 * character.
 */
void Functions::makeChars(vector<int>* yesNo, int numVars, int charNum) {
    // create the unchanging variable for size since I need to check it for the table
    int size = numVars;
    int i = charNum;

    // integer to flip between 1 and 0
    int binary = 1;

    // this loop is the number of times it prints the 10 pair
    for (int j = 0; j < pow(2, i); j++) {
        // this loop is the number of 1s and 0s per pair
        for (int k = 0; k < pow(2, size - i); k++)
            yesNo->push_back(binary);

        // flip the binary
        binary++;
        binary %= 2;
    }
}

void Functions::printTable() {
    for (auto& itr : *statements) {
        vector<int>* temp = itr.second;
        cout << itr.first.getName() << ": ";
        for (int i = 0; i < temp->size(); i++)
            cout << temp->at(i) << " ";
        cout << endl;
    }
}

void Functions::addStatements(map<Statement, vector<int>*>* statements) {
    this->statements = statements;
}