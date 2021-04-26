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

int Functions::parse2(map<Statement, vector<int>*> &statementMap, string& line){
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

    return simple.size();
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

            vector<int>* firstStatement;
            string joiner;
            vector<int>* secondStatement;
            bool gotFirst = false;
            bool gotSecond = false;
            int index = 0;
            for (auto itr2 = statements->begin(); itr2 != statements->end();) {
                string smallerStatement = itr2->first.getName();
                if (strlen(smallerStatement.c_str()) > 3) {
                    smallerStatement = "[" + itr2->first.getName() + "]";
                }
                string biggerStatement = statement.getName();
                double statementLength = strlen(biggerStatement.c_str());
                int smallerStatementLength = strlen(smallerStatement.c_str());
                if (statementLength/smallerStatementLength > 1.2) {
                    string testString = statement.getName().substr(index, statementLength - index);
                    if (joiner == "->")
                        testString = statement.getName().substr(index, statementLength - index);
                    if (!gotFirst && smallerStatement == statement.getName().substr(0, smallerStatementLength)) {
                        firstStatement = itr2->second;
                        joiner = statement.getName().substr(smallerStatementLength + 1, 1);
                        index = smallerStatementLength + 3;
                        if (joiner == "-") {
                            joiner = statement.getName().substr(smallerStatementLength + 1, 2);
                            index++;
                        }
                        //cout << "First: " << smallerStatement << endl;
                        //cout << "Joiner: " << joiner << endl;
                        gotFirst = true;
                        itr2 = statements->begin();
                    }
                    else if (gotFirst && !gotSecond && smallerStatement == testString) {
                        secondStatement = itr2->second;
                        //cout << "Second: " << smallerStatement << endl;
                        gotSecond = true;
                        break;
                    }
                    else
                        itr2++;
                }
                else
                    itr2++;
            }

            for (int i = 0; i < firstStatement->size(); i++) {
                //cout << firstStatement->at(i) << " " << secondStatement->at(i);
                if (joiner == "^") {
                    itr.second->push_back((firstStatement->at(i) && secondStatement->at(i)) ? 1 : 0);
                    //cout << " " << ((firstStatement->at(i) && secondStatement->at(i)) ? 1 : 0) << endl;
                }
                else if (joiner == "v") {
                    itr.second->push_back((firstStatement->at(i) || secondStatement->at(i)) ? 1 : 0);
                    //cout << " " << ((firstStatement->at(i) || secondStatement->at(i)) ? 1 : 0) << endl;
                }
                else if (joiner == "->") {
                    itr.second->push_back((!firstStatement->at(i) || (firstStatement->at(i) && secondStatement->at(i))) ? 1 : 0);
                    //cout << " " << ((!firstStatement->at(i) || (firstStatement->at(i) && secondStatement->at(i))) ? 1 : 0) << endl;
                }
            }
        }
    }
    //printTable();
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

void Functions::outputFile(map<Statement, vector<int> *> &statementMap, ofstream &output) {
    auto itr = statementMap.begin();
    while(itr != statementMap.end()){
        output << itr->first.getName() << ",";
        ++itr;
    }
    output << endl;
    for(int i = 0; i < statementMap.begin()->second->size(); ++i){
        auto innerItr = statementMap.begin();
        while(innerItr != statementMap.end()){
            output << innerItr->second->at(i) << ",";
            ++innerItr;
        }
        output << endl;
    }
}
