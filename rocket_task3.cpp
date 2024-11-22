#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
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
    double h = 0.0; // Height of rocket from surface
    double re = 6356; // Radius of Earth
    double gn;
    double amd;
    double cd = 0.500; // Drag Coefficient
    double area = M_PI * pow(3.3e-3, 2); // Cross sectional Area
    
    while (v >= 0) {
        gn = 3.962e5 / pow(h + re, 2); // Gravitational force on rocket
        amd = 1.225e6 * exp(-h / 9); // Air mass density

        double v_escape = sqrt(2 * gn * (h + re)); // Escape velocity (km/s)
        if (v >= v_escape) {
            cout << "Escape velocity reached" << endl;
            return 1;
        }

        if (M_fuel_current > 0) {
            M = M - (thrust * delta_t) / exhaust_velocity; // Update mass
            M_fuel_current = M - M_payload; // Update current fuel
        } else {
            thrust = 0;
        }
        
        v = v + ((thrust / M) - gn - ((1 / (2 * M)) * amd * cd * area * pow(v, 2))) * delta_t; // Update velocity
        h = h + v * delta_t; // Update height

        if (h < 0) {
            break;
        }

    }

    cout.precision(3);
    cout << h << endl;

    return 0;
}
