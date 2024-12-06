#include <fstream>
#include <iostream>
#include <cmath>
#include <cassert>
#include "radionuc.hpp"

using namespace std;

void testDecay();

int main() {
    // Seed RNG
    srand(0);
    // Run test
    testDecay();
    // Return 0 on successful program completion
    return 0;
}

void testDecay()
{
    // Create file
    ofstream output("output.txt");

    const int N0 = 10000000; // Initial population size
    const double lambda = log(2.0) / (109.771 / 60.0); // Rate of decay
    const double tmax = 20; // End time of simulation (hours)
    const double dt = 0.01; // Time step of simulation (hours)
    double t = 0; // Current time of simulation (hours)
    radioNuclide F18(lambda,N0); // Construct population of Fluorine18 nuclei

    cout << "t\tF18" << endl; // Print column headers
    while (t < tmax + dt)
    { // Loop while within defined simulation time
        cout << t << "\t" << F18.Count() << endl; // Print time and population size
        output << t << "\t" << F18.Count() << endl; // Pipe output into a file
        F18.Decay(dt); // Decay the population
        t += dt; // Advance simulation time
    }

    // Close file
    output.close();
}
