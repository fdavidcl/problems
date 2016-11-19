// https://www.hackerrank.com/challenges/ctci-making-anagrams
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
  vector<int> diff(26, 0);
  
  for (const char& c : a) {
    diff[c - 'a'] += 1;
  }
  for (const char& c : b) {
    diff[c - 'a'] -= 1;
  }
  
  return accumulate(diff.begin(), diff.end(), 0, [](int accumulator, int d) { 
    return accumulator + (d >= 0 ? d : -d); 
  });
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
