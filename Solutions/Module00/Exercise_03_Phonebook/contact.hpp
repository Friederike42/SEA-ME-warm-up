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
    bool is_bookmarked;

public:
    Contact(std::string name,
            std::string phone_number,
            std::string nick_name);
    Contact(const Contact &other);
    ~Contact();

    string to_string();

    void set_phone_number(string phone_number);
    string get_phone_number() const;

    void set_bookmark(bool is_bookmarked);
    bool get_bookmark() const;

    void set_name(string name);
    string get_name() const;

    void set_nick_name(string nick_name);
    string get_nick_name() const;

};