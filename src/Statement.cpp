//
// Created by Kevin Leong on 4/16/21.
//

#include "Statement.h"

Statement::Statement(string name) {
    this->name = name;
    this->column = new vector<int>();
}

string Statement::getName() const { return name; }

bool Statement::operator<(const Statement& other) const {
    return this->name.size() - other.getName().size() < 0;
}
bool Statement::operator==(const Statement& other) const {
    return this->name.size() == other.getName().size();
}