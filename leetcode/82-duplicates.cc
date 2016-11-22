// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include <unordered_map>

class Solution {
public:
  // This is a more general solution: it doesn't assume that the list is sorted
  ListNode* deleteDuplicates(ListNode* head) {
    unordered_map<int, unsigned> count;
    // just count
    for (ListNode* cur = head; cur != NULL; cur = cur->next) {
      if (count.find(cur->val) == count.end()) count[cur->val] = 0;
      count[cur->val] += 1;
    }
        
    ListNode* new_head = head;
    while (!(new_head == NULL || count[new_head->val] == 1)) new_head = new_head->next; 
    if (new_head != NULL) {
      ListNode* prev = new_head;
      for (ListNode* cur = prev->next; cur != NULL; cur = cur->next) {
        if (count[cur->val] > 1) {
          prev->next = cur->next;
        } else {
          prev = cur;
        }
      }
    }
        
    return new_head;
  }
};
