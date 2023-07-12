using namespace std;
#include <iostream>
#include <string>

class Go_Cart final
{
private:
    string owner;

public:
    // Default constructor
    Go_Cart();

    // Copy constructor
    Go_Cart(Go_Cart &other_cart);

    // assignment constructor
    Go_Cart &operator=(Go_Cart &go_cart);

    // Destructor is not virtual, because this class is not supposed to have child classes (see final key word above)
    ~Go_Cart();

    void go();

    string get_owner() { return this->owner; };
    void set_owner(string owner) { this->owner = owner; };
};