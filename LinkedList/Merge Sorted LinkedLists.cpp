/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) {
            return l2;
        } 
        if(l2 == NULL) {
            return l1;
        }
        
        ListNode *curr1, *curr2, *curr3, *l3;
        l3 = NULL;
        curr3 = NULL;
        curr1 = l1;
        curr2 = l2;
        
        while(curr1 && curr2) {
            
            int value = 0;
            if(curr1->val < curr2->val) {
                value = curr1->val;
                curr1 = curr1->next;
            }
            
            else {
                value = curr2->val;
                curr2 = curr2->next;
            }
            
            if(l3 == NULL) {
                l3 = new ListNode(value);
                curr3 = l3;
            } else {
                curr3->next = new ListNode(value);
                curr3 = curr3->next;
            }
            
        }
        
        while(curr1) {
            curr3->next = new ListNode(curr1->val);
            curr1 = curr1->next;
            curr3 = curr3->next;
        }
        
        while(curr2) {
            curr3->next = new ListNode(curr2->val);
            curr2 = curr2->next;
            curr3 = curr3->next;
        }
        
        return l3;
    }
};