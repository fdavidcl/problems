// https://www.hackerrank.com/challenges/bonetrousle

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// slow recursive solution
int select_sticks(unsigned sticks_left, vector<bool>& available, unsigned boxes_left) {
  if (boxes_left == 0) {
    if (sticks_left == 0) {
      return 0;
    } else {
      return -1;
    }
  } else {
    // Recursively try with each available slot
    for (unsigned slot = 0; slot < available.size(); slot++) {
      if (available[slot]) {
	available[slot] = false;
	if (select_sticks(sticks_left - slot - 1, available, boxes_left - 1) == 0) {
          return 0;
        } else {
          available[slot] = true;
	}
      }
    }
  }
    
  return -1;
}


int main() {
  int trips;
  cin >> trips;
    
  for (int _t = 0; _t < trips; _t++) {
    int sticks, max, boxes;
    cin >> sticks;
    cin >> max;
    cin >> boxes;
        
    // so we need a_1+a_2+...+a_b = sticks
    // verifying that a_1,a_2,...a_b <= max
    vector<bool> available(max, true);
    if (select_sticks(sticks, available, boxes) < 0) {
      cout << "-1\n";
    } else {
      bool first = true;
      for (int e = 0; e < available.size(); e++) {
	if (!available[e]) {
	  cout << (first ? "" : " ") << (e+1);
	  first = false;
	}
      }
      cout << endl;
    }
  }
    
  return 0;
}
