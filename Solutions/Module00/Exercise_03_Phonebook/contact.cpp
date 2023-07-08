#include "contact.hpp"

// Constructor
Contact::Contact(string name, string phone_number, string nick_name)
{
    this->name = name;
    this->phone_number = phone_number;
    this->nick_name = nick_name;
}
Contact::~Contact(){};

string Contact::to_string() { return this->name + "\n" + this->phone_number + "\n" + this->nick_name; }


// Converter::Converter(){}