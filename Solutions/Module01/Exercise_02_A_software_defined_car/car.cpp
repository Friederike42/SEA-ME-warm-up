#include "car.hpp"

Car::Car(string make, string model, string year)
{
    this->make = make;
    this->model = model;
    this->year = year;
};

Car::Car(const Car &other_car)
{
    this->make = other_car.get_make();
    this->model = other_car.get_model();
    this->year = other_car.get_year();
};

Car& Car::operator = (const Car &car)
    if(this != &car){
        this->make = car.get_make();
        this->model = car.get_model();
        this->year = car.get_year();
    }
    return *this;
};

Car::~Car(){
};

void Car::drive() const
{
    cout << "Here drives a car make " << this->make << ", model " << this->model << " and year " << this->year ;
}

string Car::get_make() const
{
    return this->make;
}

string Car::get_model() const
{
    return this->model;
}

string Car::get_year() const
{
    return this->year;
}