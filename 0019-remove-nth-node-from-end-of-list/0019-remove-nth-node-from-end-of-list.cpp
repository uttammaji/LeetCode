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
    // Function that takes the head of a linked list and an integer n, returning the modified list's head
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Initialize two pointers, 'ptr' (fast) and 'temp' (slow), both pointing to the start of the list
        ListNode *ptr = head, *temp = head;
        
        // Move the fast pointer 'ptr' ahead by 'n' steps to create a gap of 'n' nodes between 'ptr' and 'temp'
        for (int i = 0; i < n; i++) ptr = ptr->next;
        
        // If 'ptr' reaches NULL, it means 'n' equals the list length, so the head node itself must be removed
        if (!ptr) return head->next;
        
        // Move both pointers forward one step at a time until 'ptr' reaches the very last node
        while (ptr->next) {
            ptr = ptr->next;   // Advance the fast pointer
            temp = temp->next; // Advance the slow pointer (stops right before the target node)
        }
        
        // Bypass the target N-th node from the end by linking the previous node to the node after it
        temp->next = temp->next->next;
        
        // Return the head of the updated linked list
        return head;
    }
};
