#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream oldInit("init.txt");

    // assign values for T, ve, Mtotal and Mpayload
    double thrust, exhaust_velocity, M_total, M_payload;
    oldInit >> thrust;
    oldInit >> exhaust_velocity;
    oldInit >> M_total;
    oldInit >> M_payload;
    oldInit.close();

    double delta_t = 0.001; // Change in time seconds
    double v = 0.0; // Initial velocity (km/s)
    double M = M_total; // Initial total mass
    double M_fuel_current = M_total - M_payload; // Current mass of fuel

    while (M_fuel_current > 0) {
        v = v + (thrust / M) * delta_t; // Update velocity
        M = M - (thrust * delta_t) / exhaust_velocity; // Update mass
        M_fuel_current = M - M_payload; // Update current fuel
    }

    cout.precision(3);
    cout << v << endl;

    /*// Testing
    cout << M_payload << endl;
    double test = M_total * pow(2.718, -((v) / exhaust_velocity));
    cout << test << endl;*/

    return 0;
}
