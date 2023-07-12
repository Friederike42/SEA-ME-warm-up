#include "go_cart.hpp"

// Default constructor
Go_Cart::Go_Cart(){
};

// Copy constructor
Go_Cart::Go_Cart(Go_Cart &other_go_cart){
    this->set_owner(other_go_cart.owner);
};

// assignment constructor
Go_Cart& Go_Cart::operator = (Go_Cart &go_cart){
    if (this->get_owner() != &go_cart.get_owner()){
        this->set_owner(go_cart.get_owner()); //todo has issues
    }
    return *this;
};

Go_Cart::~Go_Cart(){
};

void Go_Cart::go() {
    cout << "Here goes go cart owned by: " << this->get_owner();
};