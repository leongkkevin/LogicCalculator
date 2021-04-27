//
// Created by Kevin Leong on 4/14/21.
//

#ifndef LOGICCALCULATOR_FUNCTIONS_H
#define LOGICCALCULATOR_FUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <fstream>

#include "Statement.h"

using namespace std;

class Functions {
private:
    map<Statement, vector<int>*>* statements;
public:
    /**
     * Constructor for function class
     * Creates the statements map
     */
    Functions();

    /**
     * Makes a table given the number of simple variables and the class map of statements
     */
    void makeTable(int);

    /**
     * This method is called if a Statement in the map consists of a single character.
     */
    void makeChars(vector<int>*, int, int);

    /**
     * Prints the contents of the table onto the terminal
     */
    void printTable();

    /**
     * Assigns a map<Statement, vector<int>*> to the object
     */
    void addStatements(map<Statement, vector<int>*>*);

    /**
     * Parses the terminal inquiry using recursion and a stack
     * Adds to the statementMap
     * Returns the amount of single, unique, character variables in the statement
     */
    int parse(map<Statement, vector<int>*> &statementMap, string& line);

    /**
     * Gets the longer, complex mini statements in the long statement using recursion and a stack
     * Returns a string (the complex statment)
     */
    string getComplex(vector<string>&, vector<char>&, int);

    /**
     *
     * Prints the contents of the statementMap onto a .csv file
     * Found in artifacts folder
     */
    void outputFile(map<Statement, vector<int>*> &statementMap, ofstream &output);
};

#endif //LOGICCALCULATOR_FUNCTIONS_H
