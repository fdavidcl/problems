#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
unsigned partition(vector<T>& ar, unsigned lo, unsigned hi) {
  unsigned i = lo;

  for (unsigned j = lo; j < hi; ++j) {
    if (ar[j] <= ar[hi]) {
      swap(ar[i], ar[j]);
      i += 1;
    }
  }

  swap(ar[i], ar[hi]);


  return i;
}

template<class T>
void quicksort(vector<T>& ar, unsigned lo, unsigned hi) {
  if (lo < hi) {

    unsigned p = partition(ar, lo, hi);

    for (auto& e : ar)
      cout << e << " ";
    cout << endl;

    quicksort(ar, lo, p - 1);
    quicksort(ar, p, hi);
  }
}

int main() {
  // Hackerrank inputs
  int size;
  cin >> size;
  vector<int> ar(size);
  for (auto& e : ar) {
    cin >> e;
  }
  quicksort(ar, 0, ar.size()-1);
  return 0;
}
