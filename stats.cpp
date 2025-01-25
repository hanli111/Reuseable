// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

int count(vector<double> v) {
    // Return number of elements in the vector
    return v.size();
}

double sum(vector<double> v) {
    // Make sure v is not empty
    assert(!v.empty());

    double total = 0;

    // Loops through the vector and adds all elements together
    for (size_t i = 0; i < v.size(); ++i) {
        total += v[i];
    }
    return total;
}

double mean(vector<double> v) {
    // Make sure v is not empty
    assert(!v.empty());

    double totalNumber = count(v);
    double sumVal = sum(v);

    // Finds the mean
    double mean = (1 / totalNumber) * sumVal;
    return mean;
}

double median(vector<double> v) {
    // Make sure v is not empty
    assert(!v.empty());

    sort(v.begin(), v.end());

    // Check is vector is odd
    if (v.size() % 2 != 0) {
        // If it is, then return the middle element
        return v[v.size() / 2];
    } else {
        // If it's not, then return the average of the two middle elements
        return (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2.0;
    }
}

double min(vector<double> v) {
    // Make sure v is not empty
    assert(!v.empty());

    sort(v.begin(), v.end());

    // Return first element, which is the minimum since the vector is sorted least to greatest
    return v[0];
}

double max(vector<double> v) {
    // Make sure v is not empty
    assert(!v.empty());

    sort(v.begin(), v.end());

    // Return last element, which is the maximum since the vector is sorted least to greatest
    return v[v.size() - 1];
}

double stdev(vector<double> v) {
    // Make sure v has at least 2 elements
    assert(v.size() >= 2);

    double average = mean(v);
    double STD = 0;

    // Loops through the vector and calculates the sum of squared differences from the mean
    for (size_t i = 0; i < v.size(); ++i) {
        STD += pow(v[i] - average, 2);
    }

    return sqrt((1.0 / (v.size() - 1)) * STD);
}

double percentile(vector<double> v, double p) {
    // Make sure v is not empty
    assert(!v.empty());

    // Make sure p is between 0 and 1
    assert(p >= 0 && p <= 1);

    sort(v.begin(), v.end());
    double rank = p * (v.size() - 1);
    double intpart = 0;
    double fractpart = 0;

    if (p == 1) {
        fractpart = 0;
    }

    // Split rank into an integer and decimal portion
    fractpart = modf(rank, &intpart);

    // Calculates percentile
    size_t low = static_cast<size_t> (intpart);
    size_t up = min(low + 1, v.size() - 1);

    double percentile = v[low] + fractpart * (v[up] - v[low]);
    return percentile;
}

vector<double> filter(vector<double> v, vector<double> criteria, double target) {
    // Make sure v and criteria have the same # of elements
    assert(v.size() == criteria.size());

    vector<double> result;

    // Loops through the criteria vector and if an element is equal to target, the result vector would add the element from the v vector's index
    for (size_t i = 0; i < criteria.size(); ++i) {
        if (criteria[i] == target) {
            int index = i;
            result.push_back(v[index]);
        }
    }

    return result;
}
