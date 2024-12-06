#include "radionuc.hpp"
#include <cmath>

class Tc99 : public radioNuclide {
    public:
        Tc99() : radioNuclide(log(2) / 6.0067, 0) {} // Default constructor
        Tc99(const int N) : radioNuclide(log(2) / 6.0067, N) {} // Custom constructor that takes in a value for the population size
};
