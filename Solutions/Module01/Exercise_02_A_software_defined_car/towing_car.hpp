#include "car.hpp"
class Towing_Car : public Car
{
protected:
    float weight;
    unsigned short trailing_load_in_tons;


public:
    // Default constructor
    Towing_Car(string make = "Towing Car Make", string model = "Model 1", string year = "1999", float weight = 3.0f, unsigned short trail_load = ((unsigned short) 3));

    // Copy constructor
    Towing_Car(const Towing_Car &other_car);

    // assignment constructor
    Towing_Car &operator=(const Towing_Car &towing_car);

    // Destructor is virtual as this class shall have child classes tractor and truck
    virtual ~Towing_Car();

    //this means this method disallows any implementation in this class, but shall have implementation in child classes
    virtual void tow(unsigned short load) = 0;
    
    void drive() const override;

    float get_weight() const { return this->weight; };
    float get_trailing_load_in_tons() const { return this->trailing_load_in_tons; };
};