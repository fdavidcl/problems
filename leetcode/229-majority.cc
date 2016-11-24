// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    unsigned count1 = 0, count2 = 0;
    int el1, el2;

    // Modification of https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    for (int n : nums) {
      if (count1 == 0 && n != el2) {
        el1 = n;
        count1 = 1;
      } else if (count2 == 0 && n != el1) {
        el2 = n;
        count2 = 1;
      } else if (n == el1) {
        count1 += 1;
      } else if (n == el2) {
        count2 += 1;
      } else {
        count1 -= 1;
        count2 -= 1;
      }
    }
        
    vector<int> frequent;
    count1 = 0; count2 = 0;
        
    for (int n : nums) {
      count1 += n == el1;
      count2 += n == el2;
    }
    if (count1 > nums.size()/3) {
      frequent.push_back(el1);
    }
    if (count2 > nums.size()/3 && el2 != el1) {
      frequent.push_back(el2);
    }
        
    return frequent;
  }
};
