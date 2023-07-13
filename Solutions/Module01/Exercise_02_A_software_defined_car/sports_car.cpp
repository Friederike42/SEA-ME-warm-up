#include "sports_car.hpp"

// todo think whether there are more intelligent datatypes for year, use chrono include= auto y = year{2016};?
Sports_Car::Sports_Car(string make, string model, string year, string top_speed)
{
    this->make = make;
    this->model = model;
    this->year = year;
    this->top_speed = top_speed;
};

Sports_Car::Sports_Car(const Sports_Car &other_Sports_Car)
{
    this->make = other_Sports_Car.get_make();
    this->model = other_Sports_Car.get_model();
    this->year = other_Sports_Car.get_year();
    this->top_speed = other_Sports_Car.get_top_speed();
};

Sports_Car &Sports_Car::operator = (const Sports_Car& car)
{
    if (this != &car)
    {
        this->top_speed = car.get_top_speed();
        this->make = car.get_make();
        this->model = car.get_model();
        this->year = car.get_year();
    }
    return *this;
};

Sports_Car::~Sports_Car(){};

void Sports_Car::drive() const
{

    Car::drive();
    cout << " at top speed of " << this->top_speed << endl;
}

string Sports_Car::get_top_speed() const
{
    return this->top_speed;
}