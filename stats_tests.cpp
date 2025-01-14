#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();

// Precision for floating point comparison
const double epsilon = 0.00001;

static bool almost_equal(double x, double y) {
  return abs(x - y) < epsilon;
}

// Add prototypes for your test functions here.
void test_count();
void test_sum();
void test_mean();
void test_median();
void test_min();
void test_max();
void test_stdev();
void test_percentile();
void test_filter();

int main() {
  test_sum_small_data_set();
  // Call your test functions here
  test_count();
  test_sum();
  test_mean();
  test_median();
  test_min();
  test_max();
  test_stdev();
  test_percentile();
  test_filter();
  cout << "All tests passed!" << endl;
  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.
void test_count() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(count(v) == 8);
}

void test_sum() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(sum(v) == 106.3);
}

void test_mean() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(almost_equal(mean(v), 13.2875));
}

void test_median() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(median(v) == 13.55);
}

void test_min() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(min(v) == 4.3);
}

void test_max() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(max(v) == 22.1);
}

void test_stdev() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(almost_equal(stdev(v), 7.02514616));
}

void test_percentile() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  assert(almost_equal(percentile(v, 0.5), 13.55));
  assert(almost_equal(percentile(v, 0.1), 5.28));
}

void test_filter() {
  vector<double> v = {22.1, 14.2, 19.8, 20.2, 4.3, 5.7, 7.1, 12.9};
  vector<double> criteria = {0, 1, 1, 2, 2, 1, 1, 0};
  vector<double> result = filter(v, criteria, 1);
  vector<double> expected = {14.2, 19.8, 5.7, 7.1};
  assert(result == expected);
}
