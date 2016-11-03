// https://www.hackerrank.com/challenges/maxsubarray
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// max_subarray_with_last
// Retrieves the maximum sum for a contiguous subarray
// containing the last element of the array (array[size-1])
int max_subarray_with_last(int* array, int size) {
  int current_sum = array[size - 1];
  int max = current_sum;

  // Add elements from the last and get the maximum possible sum
  for (int first = size - 2; first >= 0; first--) {
    current_sum += array[first];

    if (current_sum > max)
      max = current_sum;
  }

  return max;
}

// recursive solution
// The maximum value for a subarray is either the maximum value
// of a subarray that doesn't contain the last value or the maximum
// subarray that contains the last value
// Times out on test #1
int max_subarray_recursive(int* array, int size) {
  if (size == 1) {
    return array[0];
  } else {
    return max(max_subarray_recursive(array, size - 1),
               max_subarray_with_last(array, size));
  }
}

// iterative solution
// for each element, find the best subarray finishing with that element
// Times out on test #1
int max_subarray_iter(int* array, int size) {
  int best_solution = numeric_limits<int>::min();

  for (int s = 0; s < size; s++) {
    best_solution = max(best_solution, max_subarray_with_last(array, s + 1));
  }
  
  return best_solution;
}

// memoized solution
// calculate all the sums for any subarray and store them as partial results
// in a matrix, and find the best
// Aborts on test #1 (maybe reserving too much memory?)
int max_subarray_memoized(int* array, int size) {
  int** sums = new int*[size];
  for (int i = 0; i < size; i++) sums[i] = new int[size];

  int max = numeric_limits<int>::min();
  
  for (int first = 0; first < size; first++) {
    sums[first][first] = array[first];
    if (array[first] > max)
      max = array[first];
    
    for (int last = first + 1; last < size; last++) {
      sums[first][last] = sums[first][last - 1] + array[last];
      if (sums[first][last] > max)
        max = sums[first][last];
    }
  }

  return max;
}

// Select your solution here:
int (*max_subarray)(int*, int) = max_subarray_memoized;

// Find the maximum non-contiguous non-empty subarray
int sum_positives(int* array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i] * (array[i] > 0);
  }

  // Consider always at least one element
  if (sum == 0) {
    int max = numeric_limits<int>::min();
    for (int i = 0; i < size; i++) {
      if (array[i] == 0) return 0;
      else if (array[i] > max) max = array[i];
    }
    return max;
  }
  
  return sum;
}

int main() {
  unsigned tests;
  cin >> tests;
  for (int _t = 0; _t < tests; _t++) {
    unsigned size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
      cin >> arr[i];

    cout << max_subarray(arr, size) << " " << sum_positives(arr, size) << endl;

    delete[] arr;
  }
  return 0;
}
