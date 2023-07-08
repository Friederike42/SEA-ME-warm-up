#pragma once

#include <string>
#include <iostream>
using namespace std;

class Contact
{
private:
    string name;
    string phone_number;
    string nick_name;

public:
    Contact(std::string name,
            std::string phone_number,
            std::string nick_name);
    ~Contact();

    string to_string();
};