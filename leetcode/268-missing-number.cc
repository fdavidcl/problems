// https://leetcode.com/problems/missing-number/

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    // relocate each number to their position
    // (basically, sort the array except for n)
    int n = nums.size();
    for (int i = 0; i < n;) {
      if (i != nums[i] && nums[i] < n) {
        swap(nums[i], nums[nums[i]]);
      } else {
        i += 1;
      }
    }
        
    for (int i = 0; i < n; ++i) {
      if (nums[i] == n) return i;
    }
    return n;
  }
};
