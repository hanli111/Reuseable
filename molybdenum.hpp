#include "radionuc.hpp"
#include <cmath>

class Mo99 : public radioNuclide {
    public:
        Mo99() : radioNuclide(log(2) / 65.94, 0) {} // Default constructor
        Mo99(const int N) : radioNuclide(log(2) / 65.94, N) {} // Custom constructor that takes in a value for the population size
};
