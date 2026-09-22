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
    ListNode* deleteDuplicates(ListNode* head) {
        // Return immediately if the list is empty or has only one node
        if (!head) return nullptr;
        
        ListNode* current = head;
        
        // Traverse the list until the second-to-last node
        while (current && current->next) {
            // If the current value matches the next value, skip the next node
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // Free memory in C++ to prevent leaks
            } else {
                // Otherwise, move to the next distinct node
                current = current->next;
            }
        }
        
        return head;
    }
};
