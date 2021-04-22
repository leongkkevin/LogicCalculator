//
// Created by Kevin Leong on 4/16/21.
//

#include "Statement.h"

Statement::Statement(string name) {
    this->name = name;
    this->table = new map<char, vector<int>>();
}

void Statement::createTable(vector<char>& other) {
    // create the unchanging variable for size since I need to check it for the table
    int size = other.size();

    // iterate through all the characters in the other vector
    for (int i = 1; i <= size; i++) {
        // vector for the table
        vector<int>* yesNo = new vector<int>();

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

        // insert the char vector pair into the table
        table->insert(pair<char, vector<int>>(other.back(), *yesNo));
        // pop the character that was just inserted
        other.pop_back();
    }
}

void Statement::printChars() {
    for (auto& itr : *table) {
        vector<int> temp = itr.second;
        cout << itr.first << ": ";
        for (int i = 0; i < temp.size(); i++)
            cout << temp.at(i);
        cout << endl;
    }
}
