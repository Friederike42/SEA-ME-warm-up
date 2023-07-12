#include "car.hpp"


Car::Car(string name, unsigned int speed)
{
    this->name = name;
    this->speed = speed;
};

Car::Car(const Car &other_car)
{
    this->name = other_car.get_name();
    this->speed = other_car.get_speed();
};

Car& Car::operator = (const Car &car)
{
    if(this != &car){
        this->name = car.get_name();
        this->speed = car.get_speed();
    }
    return *this;
};

Car::~Car(){
    this->name = "";
    this->speed = 0;
};

string Car::get_name() const
{
    return this->name;
}

unsigned int Car::get_speed() const
{
    return this->speed;
}