#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
using namespace std;

// Declare functions
double calculate_height(double fuel_mass, double thrust, double exhaust_velocity, double M_payload);
double find_optimal_mass(double thrust, double exhaust_velocity, double M_payload);

int main() {
    ifstream oldInit("init_opt.txt");

    // assign values for thrust, exhaust velocity, and mass of payload
    double thrust, exhaust_velocity, M_payload;
    oldInit >> thrust;
    oldInit >> exhaust_velocity;
    oldInit >> M_payload;
    oldInit.close();

    double optimal_fuel_mass = find_optimal_mass(thrust, exhaust_velocity, M_payload);

    // check if rocket is too heavy
    if (optimal_fuel_mass == -1) {
        cout << "Rocket too heavy" << endl;
        return 1;
    } else {
        cout.precision(3);
        cout << optimal_fuel_mass << endl;
        return 0;
    }

}

double calculate_height(double fuel_mass, double thrust, double exhaust_velocity, double M_payload) {
    double delta_t = 0.001; // Change in time seconds
    double v = 0.0; // Initial velocity (km/s)
    double h = 0.0; // Height of rocket from surface
    double re = 6356.0; // Radius of Earth
    double g;
    double amd;
    double cd = 0.500; // Drag Coefficient
    double area = M_PI * pow(3.3e-3, 2); // Cross sectional Area
    double M_total = fuel_mass + M_payload; // Total mass of rocket

    // Updates variables until there is no more velocity
    while (v >= 0) {
        g = 3.962e5 / pow(h + re, 2); // Gravitational force on rocket
        amd = 1.225e6 * exp(-h / 9); // Air mass density

        double v_escape = sqrt(2 * g * (h + re)); // Escape velocity (km/s)
        if (v >= v_escape) {
            return -1;
        }

        if (fuel_mass > 0) {
            M_total = M_total - (thrust * delta_t) / exhaust_velocity; // Update mass
            fuel_mass = M_total - M_payload; // Update current fuel
        } else {
            thrust = 0;
        }
        
        v = v + (thrust / M_total - g - ((1 / (2 * M_total)) * amd * cd * area * pow(v, 2))) * delta_t; // Update velocity
        h = h + v * delta_t; // Update height

        if (h < 0) {
            break;
        }
    }
    return h;
}

double find_optimal_mass(double thrust, double exhaust_velocity, double M_payload) {
    double low = 0.0;
    double high = thrust / (3.962e5 / pow(6356.0, 2)) - M_payload;
    bool reached = false;

    // Binary search to find optimal fuel mass
    while (high - low > 0) {
        double mid = (low + high) / 2;
        double height = calculate_height(mid, thrust, exhaust_velocity, M_payload);

        if (height > 2005) {
            high = mid;
        } else if (height < 1995) {
            low = mid;
        } else {
            reached = true;
            return mid;
        }
    }

    if (!reached) {
        return -1;
    }
    return (low + high) / 2.0;
}
