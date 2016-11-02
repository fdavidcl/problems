#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int test_cases;
  cin >> test_cases;

  for (int t = 0; t < test_cases; ++t) {

    int size;
    cin >> size;
    vector<unsigned> ar(size);
    for (auto& e : ar) {
      cin >> e;
    }

    // Naive approach
    /*
    bool found = false;

    for (int i = 1; i < ar.size() && !found; ++i) {
      int left_sum, right_sum;
      left_sum = accumulate(ar.begin(), ar.begin() + i - 1, 0, plus<int>());
      right_sum = accumulate(ar.begin() + i, ar.end(), 0, plus<int>());

      found = left_sum == right_sum;
    }
    */

    long long int sum = accumulate(ar.begin(), ar.end(), 0, plus<int>());
    long long int partial_sum = 0;
    bool found = false;

    for (unsigned i = 0; i < ar.size(); ++i) {
      if ((sum - ar[i]) % 2 == 0 && (sum - ar[i])/2 == partial_sum)
        found = true;

      partial_sum += ar[i];
    }

    if (found) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
