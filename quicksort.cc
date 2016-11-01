#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


template<class T>
pair<pair<vector<T>, vector<T>>, vector<T>> qs_partition(const vector<T>& ar) {
  vector<T> left, right, equal;
  for (auto& e : ar) {
    if (e < ar[0])
      left.push_back(e);
    else if (e > ar[0])
      right.push_back(e);
    else
      equal.push_back(e);
  }

  return make_pair(make_pair(left, right), equal);
}

template<class T>
vector<T> quicksort(const vector<T>& ar) {
  if (ar.size() <= 1) {
    return ar;
  }

  auto parts = qs_partition(ar);
  auto left = quicksort(parts.first.first);
  auto right = quicksort(parts.first.second);
  auto equal = parts.second;

  for (auto& e : equal)
    left.push_back(e);
  for (auto& e : right)
    left.push_back(e);

  for (auto& e : left)
    cout << e << " ";
  cout << endl;

  return left;
}

int main() {
  // Hackerrank inputs
  int size;
  cin >> size;
  vector<int> ar(size);
  for (auto& e : ar) {
    cin >> e;
  }
  quicksort(ar);
  return 0;
}
