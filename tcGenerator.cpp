#include "molybdenum.hpp"
#include "technetium.hpp"
#include <iostream>

using namespace std;

void processCommandLine(int argc, char *argv[], int &initMoPop, int &Tf);
int technetiumGenerator(const int moPopSize, const int Tf);

int main(int argc, char *argv[]) { 
    // Initial population
    int initMoPop;

    // Length of simulation
    int Tf;

    // Process command line 
    processCommandLine(argc, argv, initMoPop, Tf);

    // Run simulation
    technetiumGenerator(initMoPop, Tf);

    return 0; 
}

void processCommandLine(int argc, char *argv[], int &initMoPop, int &Tf) {
    /// TODO: Implement processCommandLine
    if (argc != 3) {
        cout << "Incorrect number of command line arguments." << endl;
        exit(1);
    }

    // Change into integers
    initMoPop = stoi(argv[1]);
    Tf = stoi(argv[2]);

    // Check if population is less than 1000 or greater than 10000000
    if (initMoPop < 10e3 || initMoPop > 10e7) {
        cout << "Invalid initial Mo-99 population." << endl;
        exit(1);
    }

    // Check if simulation length is less than 10 or greater than 500 hours
    if (Tf < 10 || Tf > 500) {
        cout << "Invalid simulation length." << endl;
        exit(1);
    }
}

int technetiumGenerator(const int moPopSize, const int Tf) {
    /// TODO: simulate technetium generator
    // Seed the rng
    srand(0);

    // Initial population of Mo99 (specified parameter)
    Mo99 mo99(moPopSize);

    // Initial population of Tc99 (0)
    Tc99 tc99;

    // Variable to track the number of Tc99 harvested
    int tcHarvested = 0;

    // Print column headers
    cout << "t\tMo99\tTc99" << endl;

    // Run the simulation
    for (int t = 0; t <= Tf; ++t) {
        // Print the current hour and the populations
        cout << t << "\t" << mo99.Count() << "\t" << tc99.Count() << endl;

        // Decay Mo99 and produce Tc99 for this hour
        int decayedMo = mo99.Decay(1.0); // Decay over 1 hour
        tc99.Add(decayedMo); // Add the decayed Mo99 as Tc99

        // Decay over 1 hours
        tc99.Decay(1.0);

        // Check if Tc99 population reaches the threshold for harvesting
        if (tc99.Count() >= 10000) {
            // Harvest the Tc99 and update the total
            tcHarvested += tc99.Count();

            // Set Tc99 to 0
            tc99.Zero();
        }
    }

    cout << "Initial Mo99 population: " << moPopSize << endl;
    cout << "Simulation length: " << Tf << " hours" << endl;
    cout << "Total Tc99 harvested: " << tcHarvested << endl;

    // Return the total number of Tc99 harvested
    return tcHarvested;
}
