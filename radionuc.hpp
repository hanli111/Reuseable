#pragma once
#include <iostream>
#include <cmath>

class radioNuclide {
    // TODO: Implement radioNuclide class
    private:
        double lambda; // Decay constant
        int population; // Current population of nuclei
    public:
        radioNuclide() : lambda(0.0), population(0) {} // Default constructor
        radioNuclide(const double lambda, const int N) : lambda(lambda), population(N) {} // Constructor with parameters lambda and initial population size
        
        // Get the population size
        int Count() {
            return population;
        }

        // Simulates radioactive decay for a time interval
        int Decay(const double tinterval) {
            // Compute probability for a given single nucleus to decay in t interval seconds
            double probability = lambda * tinterval;

            // Sets the number of atoms decayed as 0 first
            int numDecayed = 0;

            // Loop through entire population to see which atoms deacy in t interval seconds
            for (int i = 0; i < population; ++i) {
                double randNum = (double)rand() / RAND_MAX;

                // Checks if the random number is less than the probability
                if (randNum < probability) {
                    ++numDecayed;
                }
            }
            // Reduce population size by the number of atoms that decayed
            population -= numDecayed;

            // Returns the number of atoms that decayed
            return numDecayed;
        }

        // Add new radionuclides to the population
        void Add(const int N) {
            population += N;
        }

        // Sets population to 0
        void Zero() {
            population = 0;
        }

        // Overload of the += operator to add nuclei to the population
        void operator+=(const int N) {
            Add(N);
        }
};
