#include "tractor.hpp"

// Default constructor
Tractor::Tractor(string make, string model, string year, float weight, unsigned short trailing_load_in_tons):
    Towing_Car(make, model, year, weight, trailing_load_in_tons)
{
    //nothing to do here. the above initializer list is deriving the call to the parent class' constructor
};

// Copy constructor
Tractor::Tractor(const Tractor &tractor){
    this->make = tractor.get_make();
    this->model = tractor.get_model();
    this->year = tractor.get_year();
    this->weight = tractor.get_weight();
    this->trailing_load_in_tons = tractor.get_trailing_load_in_tons();
};

// assignment constructor
Tractor &Tractor::operator=(const Tractor &tractor){
    if(this != &tractor){
        this->make = tractor.get_make();
        this->model = tractor.get_model();
        this->year = tractor.get_year();
        this->weight = tractor.get_weight();
        this->trailing_load_in_tons = tractor.get_trailing_load_in_tons();
    }
    return *this;
};

// Destructor
Tractor::~Tractor(){

};

//tow-Method
void Tractor::tow(unsigned short speed){
    this->drive();
    cout << " in towing mode with speed " << speed << endl;
}

void Tractor::set_weight(float weight){
    this->weight = weight;
}