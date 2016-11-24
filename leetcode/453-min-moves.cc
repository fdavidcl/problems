// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
#include <algorithm>

class Solution {
public:
  int minMoves(vector<int>& nums) {
    // incrementing all numbers except one is the same asdecrementing one of them
    int mn = *min_element(nums.begin(), nums.end());
    return accumulate(nums.begin(), nums.end(), 0, [&](int acc, int v) { return acc + v - mn; });
  }
};
