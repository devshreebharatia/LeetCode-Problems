/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *curr,*prev;
        prev = head;
        
        while(prev && prev->next) {
            
            curr = prev->next;
            if(prev->val == curr->val) {
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
           
        }
        
        return head;
        
        
    }
};