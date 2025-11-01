// LeetCode Problem No. 3217
// Daily Challenge - 01/11/2025

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur != nullptr) {
            if (numbers.count(cur->val)) {
                if (prev == nullptr) {
                    head = head->next;
                } else {
                    prev->next = cur->next;
                }
            } else {
                prev = cur;
            }
            cur = cur->next;
        }

        return head;
    }
};