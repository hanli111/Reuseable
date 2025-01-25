#include "stats.hpp"
#include "library.hpp"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//REQUIRES: data contains at least 2 elements
//EFFECTS: Prints descriptive statistics for the given data
void print_descriptive_stats(vector<double> data) {
  // TODO: Implement this function, removing the assert(false); placeholder.
  cout << "count = " << count(data) << endl;
  cout << "sum = " << sum(data) << endl;
  cout << "mean = " << mean(data) << endl;
  cout << "stdev = " << stdev(data) << endl;
  cout << "median = " << median(data) << endl;
  cout << "min = " << min(data) << endl;
  cout << "max = " << max(data) << endl;
  cout << "  0th percentile = " << percentile(data, 0) << endl;
  cout << " 25th percentile = " << percentile(data, 0.25) << endl;
  cout << " 50th percentile = " << percentile(data, 0.5) << endl;
  cout << " 75th percentile = " << percentile(data, 0.75) << endl;
  cout << "100th percentile = " << percentile(data, 1.0) << endl;
  cout << endl;
}

//REQUIRES: Nothing
//EFFECTS:  Returns an approximation of the sampling distribution of the
//          difference in means between groups A and B, represented as a
//          vector of the computed difference in means for 1000 bootstrap
//          resamples of original samples data_A and data_B.
vector<double> mean_diff_sampling_distribution(vector<double> data_A, vector<double> data_B) {
  // TODO: Implement this function, removing the assert(false); placeholder.
  vector<double> differences;

  // Loop 1000 times
  for (size_t i = 0; i < 1000; ++i) {
    // Make the bootstrap resamples for both data groups
    vector<double> resampleA = bootstrap_resample(data_A, i);
    vector<double> resampleB = bootstrap_resample(data_B, i);

    // Find the means for both data groups
    double meanA = mean(resampleA);
    double meanB = mean(resampleB);

    // Find the difference between the means
    double diff = meanA - meanB;

    // Add the differences to the "differences" vector
    differences.push_back(diff);
  }

  return differences;

  // HINT: Repeat the following 1000 times:
  //   1. Generate bootstrap resamples for data_A and data_B by
  //      calling the bootstrap_resample() function from the library module.
  //      Make sure to pass in the iteration number as the sample_num.
  //   2. Compute the difference in means between the resamples
  //   3. Add the computed value to a vector
}

//REQUIRES: v is not empty
//          width is between 0 and 1, inclusive
//EFFECTS:  Returns a confidence interval for the data in v of the given
//          width, centered on the 50th percentile. The interval is represented
//          as a pair of upper and lower bounds. For example, the bounds on a
//          confidence interval with width 0.8 are the 10th and 90th percentiles.
pair<double, double> confidence_interval(vector<double> v, double width) {
  // TODO: Implement this function, removing the assert(false); placeholder.
  //sort(v.begin(), v.end());

  // Find lower and upper bounds
  double lower = percentile(v, (1 - width) / 2.0);
  double upper = percentile(v, 1 - (1 - width) / 2.0);

  return {lower, upper};
  
  // HINT: Use the percentile function as a helper
  //       to compute the lower and upper bounds.

  // HINT: You can return a pair like this:
  //   return {lower, upper};
}

void two_sample_analysis(string file_name, string filter_column_name, double filter_val_A, double filter_val_B, string data_column_name) {

  // Extract data from the input file, removing rows with missing data.
  // filter_data and data have type vector<double>
  auto [filter_data, data] = extract_columns(
    file_name, filter_column_name, data_column_name);
  
  // Filter data into groups A and B based on given criteria
  vector<double> data_A = filter(data, filter_data, filter_val_A);
  vector<double> data_B = filter(data, filter_data, filter_val_B);

  // Print descriptive statistics for group A
  cout << "Group A: " << data_column_name << " | " << filter_column_name
       << " = " << filter_val_A << endl;
  print_descriptive_stats(data_A);
  cout << endl;

  // Print descriptive statistics for group B
  cout << "Group B: " << data_column_name << " | " << filter_column_name
       << " = " << filter_val_B << endl;
  print_descriptive_stats(data_B);
  cout << endl;

  // Use bootstrap resampling to approximate the sampling distribution of the
  // difference in means between groups A and B and compute a confidence interval.
  vector<double> mean_diffs = mean_diff_sampling_distribution(data_A, data_B);
  pair<double, double> ci_95 = confidence_interval(mean_diffs, 0.95);

  // Print confidence interval for the difference in means
  cout << "Confidence interval for mean(" << data_column_name
       << " | A) - mean(" << data_column_name << " | B):" << endl;
  cout << "  95% [" << ci_95.first << ", " << ci_95.second  << "]" << endl;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    // No command-line arguments, use default values for cats.csv sample data
    two_sample_analysis("cats.csv", "food", 1, 2, "weight");
  }
  else if (argc == 6) {
    // Use custom values from command-line arguments
    two_sample_analysis(argv[1], argv[2], stod(argv[3]), stod(argv[4]), argv[5]);
  }
  else {
    cout << "Error: requires exactly zero or five command-line arguments." << endl
         << "Usage:" << endl
         << "  ./two_sample.exe" << endl
         << "  ./two_sample.exe file_name filter_column_name "
         << "filter_val_a filter_val_b data_column_name" << endl;
    return 1;
  }
}