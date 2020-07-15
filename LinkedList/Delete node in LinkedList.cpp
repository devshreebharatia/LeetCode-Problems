/*
Write a function to delete a node (except the tail) in a singly linked list, 
given only access to that node.

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list 
should become 4 -> 1 -> 9 after calling your function.

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
    void deleteNode(ListNode* node) {
        
        ListNode *front, *rear;
        
        front = node;
        rear = front->next;
        
        while(rear->next != NULL) {
            
            front->val = rear->val;
            rear = rear->next;
            front = front->next;
        }
        
        front->val = rear->val;
        delete(rear);
        front->next = NULL;
        
    }
};