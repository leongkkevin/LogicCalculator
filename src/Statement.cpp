//
// Created by Kevin Leong on 4/16/21.
//

#include "Statement.h"

Statement::Statement(string name) {
    this->name = name;
    this->statement = new vector<string>();
    this->column = new vector<int>();
}

void Statement::addStatement(string statement) {
    this->statement->push_back(statement);
}

string Statement::getName() const { return name; }

vector<string>* Statement::getStatement() { return statement; }

vector<int>* Statement::getColumn() { return column; }

bool Statement::operator<(const Statement& other) const {
    int thisLength = strlen(this->name.c_str());
    int otherLength = strlen(other.getName().c_str());
    if ((thisLength - otherLength < 0))
        return true;
    else if ((thisLength - otherLength > 0))
        return false;
    else
        return strcmp(this->name.c_str(), other.getName().c_str()) < 0;
}

bool Statement::operator==(const Statement& other) const {
    cout << "\"" << this->name << "\" against \"" << other.getName() << "\"" << endl;
    return this->name == other.getName();
}