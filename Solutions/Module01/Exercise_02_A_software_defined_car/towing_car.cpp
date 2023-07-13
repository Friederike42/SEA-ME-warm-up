#include "towing_car.hpp"

Towing_Car::Towing_Car(string make, string model, string year, float weight, unsigned short trail_load )
{
    //Car my_car(make, model, year, top_speed); -> todo think can the super constructor be used?
    this->make = make;
    this->model = model;
    this->year = year;
    this->weight = weight;
    this->trailing_load_in_tons = trail_load;
};

// Copy constructor
Towing_Car::Towing_Car(const Towing_Car &other_car){
    this->make = other_car.get_make();
    this->model = other_car.get_model();
    this->year = other_car.get_year();
    this->weight = other_car.get_weight();
    this->trailing_load_in_tons = other_car.get_trailing_load_in_tons();
};

// assignment constructor
Towing_Car& Towing_Car::operator = (const Towing_Car &towing_car){
    if (this != &towing_car)
    {
        this->make = towing_car.get_make();
        this->model = towing_car.get_model();
        this->year = towing_car.get_year();
        this->weight = towing_car.get_weight();
        this->trailing_load_in_tons = towing_car.get_trailing_load_in_tons();
    }
    return *this;
};

// Destructor
Towing_Car::~Towing_Car(){

};

void Towing_Car::drive() const {
    
    if((this->weight) / 1000 < this->trailing_load_in_tons){
        cout << endl;
        cerr << "Towing car of make "<< this->make << " cannot tow more than its own weight (kg) " << this->weight << ". Please reduce towing weight of (tons)" << this->trailing_load_in_tons << " else it cannot drive.\n";
    }else{
        Car::drive();
        cout << ". The car is a towing car. It slowly starts to drive with towing weight " << this->trailing_load_in_tons << endl;
    }
};