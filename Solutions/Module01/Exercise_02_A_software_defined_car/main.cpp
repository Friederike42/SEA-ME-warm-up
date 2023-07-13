#include "car.hpp"
#include "go_cart.hpp"
#include "sports_car.hpp"
#include "tractor.hpp"

// careful, compiler g++ shows errors !!!

// function overloading = when you have multiple functions with the same name that take diffrent arguments
void print(Car* car){
    car->drive();
    cout << endl;
}
void print(Sports_Car* car){
    car->drive();
}

int main(){

    Car *car = new Car("My_car", "My_make", "My_model");
    print(car);

    Sports_Car *sports_car = new Sports_Car(); 
    print(sports_car);

    Sports_Car static_sports_car("My_static_sports_car", "My_make", "My_model", "70");
    Sports_Car *sports_car2 = &static_sports_car;
    print(sports_car2);

    Go_Cart tims_go_cart;
    tims_go_cart.set_owner("Tim");
    tims_go_cart.go();

    // Note that towing_car is an abstract class due to the tow() method and cannot be instantiated
    Tractor patriks_tractor("Patriks", "Towing car make", "2003", 3800.3f, ((unsigned short)2));
    patriks_tractor.tow(((unsigned short)30));

    Tractor aleks_tractor = patriks_tractor;
    aleks_tractor.set_make("Aleks");
    aleks_tractor.set_weight(1800.3f);
    aleks_tractor.drive(); // should result in error since aleks tractor is now lighter than its trailing load

    // Delete dynamically created objects (created with new operator) with delete; statically created ones do not need this
    delete car;
    delete sports_car;
    return 0;
}