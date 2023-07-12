#pragma once

#include <string>
#include <iostream>

using namespace std;

class Car{
    protected:
        string make;
        string model;
        string year;


    public:
        //Default constructor
        Car(string make = "Douglas Adams", string model = "H2G2", string year = "42");

        //Copy constructor
        Car(const Car &other_car);

        //assignment constructor
        Car& operator = (const Car&);

        //Destructor is virtual, because of a potential downcast
        virtual ~Car();

        virtual void drive() const;

        string get_make() const;
        string get_model() const;
        string get_year() const;

};