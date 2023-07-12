#include "contact.hpp"

// Constructor
Contact::Contact(string name, string phone_number, string nick_name)
{
    this->name = name;
    this->phone_number = phone_number;
    this->nick_name = nick_name;
    this->is_bookmarked = false;
}
Contact::Contact(const Contact &other){
    this->name = other.get_name();
    this->phone_number = other.get_phone_number();
    this->nick_name = other.get_nick_name();
    this->is_bookmarked = other.get_bookmark();
}

Contact::~Contact(){};

inline string bool_to_string(bool b) { return b ? "yes" : "no"; }

string Contact::to_string() { return "Name: " + this->name + "\nPhone number: " + this->phone_number + "\nNick name: " + this->nick_name + "\nBookmark: " + bool_to_string(this->is_bookmarked); } 

void Contact::set_phone_number(string phone_number) { this->phone_number = phone_number; }
string Contact::get_phone_number() const { return this->phone_number; }

void Contact::set_bookmark(bool is_bookmarked) { this->is_bookmarked = is_bookmarked; }
bool Contact::get_bookmark() const { return this->is_bookmarked; };

void Contact::set_name(string name) { this->name = name; }
string Contact::get_name() const { return this->name; }

void Contact::set_nick_name(string nick_name) { this->nick_name = nick_name; }
string Contact::get_nick_name() const{ return this->nick_name; }
