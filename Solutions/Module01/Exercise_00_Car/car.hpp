#pragma once

#include <string>
#include <iostream>

using namespace std;

class Car{
    private:
        string name;
        unsigned int speed;

    public:
        //Default constructor
        Car(string name = "default_name",
            unsigned int speed = 50);

        //Copy constructor
        Car(const Car &other_car);

        //assignment constructor
        Car& operator = (const Car&);

        //Destructor
        ~Car();

        string get_name() const;

        unsigned int get_speed() const;
};