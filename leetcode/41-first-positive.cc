// https://leetcode.com/problems/first-missing-positive/

// Solution with linear space :(
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int max_pos = nums.size();
    vector<bool> positives(max_pos, false);
        
    for (int e : nums) if (e > 0 && e <= max_pos)
                         positives[e-1] = true;
        
    int p;
    for (p = 1; p <= max_pos; ++p) {
      if (!positives[p-1]) return p;
    }
    return p;
  }
};

// Solution in constant space! :)
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    // IDEA: the first missing positive is surely (by pigeonhole principle?) between 1 and length of nums
    //   Also, we can linearly put each positive in its indexed position (e.g. if we find a 1, we put it
    //   in the position 0). Then we scan for the first index that does not "define" its element
    int max_pos = nums.size();
        
    for (int i = 0; i < max_pos;) {
      if (nums[i] > 0 && nums[i] <= max_pos && nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      } else {
        // Only advance the loop when no more swaps are needed in this position
        i += 1;
      }
    }
        
    for (int i = 0; i < max_pos; ++i) {
      if (nums[i] != i + 1) {
        return i+1;
      }
    }
    return max_pos + 1;
  }
};
