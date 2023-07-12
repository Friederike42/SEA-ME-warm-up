#include "car.hpp"
#include "go_cart.hpp"
#include "sports_car.hpp"

// careful, compiler g++ shows errors !!!

// function overloading = when you have multiple functions with the same name that take diffrent arguments
void print(Car* car){
    car->drive();
    cout << endl;
}
void print(Sports_Car* car){
    car->drive();
}
void print(Go_Cart* cart){
    cart->go();
}

int main(){
    Sports_Car *car = new Sports_Car(); 
    print(car);

    Car *car2 = new Car("My_car", "My_make", "My_model");
    print(car2);

    Sports_Car static_sports_car("My_static_sports_car", "My_make", "My_model", "70");
    Sports_Car *my_static_sports_car_pointer = &static_sports_car;
    print(my_static_sports_car_pointer);

    Go_Cart tims_go_cart;
    tims_go_cart.set_owner("Tim");


    // Delete dynamically created objects (created with new operator) with delete; statically created ones do not need this
    delete car;
    delete car2;
    return 0;
}