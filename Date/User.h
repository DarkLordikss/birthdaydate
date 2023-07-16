#pragma once

#include <string>

using namespace std;


// User`s class
class User {
public:
    string name;
    string birthday;

    User(string name, string birthday) {
        this->name = name;
        this->birthday = birthday;
    }

    string getBirthday()
    {
        return birthday;
    }

    string getName()
    {
        return name;
    }
};