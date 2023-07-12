#include "car.hpp"

void print(Car car){
    cout << "Name: " << car.get_name() << endl;
    cout << "Speed: " << car.get_speed() << endl;
}

int main(){
    Car z{"test",9};
    Car a("my_model_a", 20);

    cout << "Copy constructor should print {test, 9}: \n";
    auto b = z;
    print(b);

    cout << "Default constructor call should print {default_name, 50} - see car.hpp:\n";
    Car c;
    print(c);

    cout << "Assignment operator should print {my_model_a, 20}:\n";
    z = a;
    print(z);

    return 0;
}