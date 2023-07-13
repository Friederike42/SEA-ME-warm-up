#include "car.hpp"

class Sports_Car : public Car
{
    private:
        string top_speed;

    public:
        // Default constructor
        Sports_Car(string make = "Douglas Adams", string model = "H2G2", string year = "42", string top_speed = "light speed");

        // Copy constructor
        Sports_Car(const Sports_Car &other_car);

        // assignment constructor
        Sports_Car &operator=(const Sports_Car &);

        // Destructor
        ~Sports_Car();

        void drive() const override;

        string get_top_speed() const;
};