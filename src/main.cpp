//
// Created by Kevin Leong on 4/14/21.
//

#include <iostream>

using namespace std;

int main(int argc, char** argv){
    string file = argv[1];
    Functions* f = new Functions();
    f->readFile(file);
}

