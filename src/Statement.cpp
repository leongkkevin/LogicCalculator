//
// Created by Kevin Leong on 4/16/21.
//

#include "Statement.h"

Statement::Statement(string name) {
    this->name = name;
    createTable();
}

void Statement::createTable() {
    vector<vector<int>> table;
    if(this->name.size() == 1){
        vector<int> variable = {0, 0, 1, 1};
        table.push_back(variable);
    }
}
