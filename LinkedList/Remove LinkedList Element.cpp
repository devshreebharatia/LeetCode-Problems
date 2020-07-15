/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
         if(head == NULL) {
            return NULL;
        }
        
        ListNode *prev, *curr;
        prev = head;
        
        
        while(prev && prev->next) {
            
            curr = prev->next;
            if(curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
            
        }
        
        if(head->val == val) {
            head = head->next;
        }
        
        return head;
    }
};