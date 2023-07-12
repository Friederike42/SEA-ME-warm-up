#include "go_cart.hpp"

// Default constructor
Go_Cart::Go_Cart(){
};

// Copy constructor
Go_Cart::Go_Cart(const Go_Car &other_go_car){
    this->set_owner(other_go_car.get_owner());
};

// assignment constructor
Go_Cart& Go_Cart::operator = (const Go_Car &go_car){
    if (this->get_owner() != &go_car.get_owner()){
        this->set_owner(go_car.get_owner()); //todo has issues
    }
    return *this;
};

Go_Cart::~Go_Cart(){
};

void Go_Cart::go() const {
    cout << "Here goes go cart owned by: " << this->get_owner();
};