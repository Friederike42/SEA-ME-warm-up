#include "towing_car.hpp"

#include "car.hpp"

class Tractor final : public Towing_Car
{
private:
    string top_speed;

public:
    // Default constructor
    Tractor(string make, string model, string year, float weight, unsigned short trailing_load_in_tons);

    // Copy constructor
    Tractor(const Tractor &other_car);

    // assignment constructor
    Tractor &operator=(const Tractor &);

    // Destructor
    ~Tractor();

    virtual void tow(unsigned short load) override;

    void set_weight(float weight);
};