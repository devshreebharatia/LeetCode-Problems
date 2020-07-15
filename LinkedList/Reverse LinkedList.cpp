/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    ListNode* reverseList(ListNode* head) {
     
        
        //Solution 1: Iterative reverse
        /*if(head == NULL) {
            return NULL;
        }
        
        ListNode *prev, *front, *rear;
        
        prev = NULL;
        front = head;
        rear = front->next;
        
        while(front) {

            rear = front->next;
            front->next = prev;
            prev = front;
            front = rear;

        }
        return prev;
        
        */
        
        //Solution 2: Recursive reverse
        
       return (reverse(head, NULL));
    
       
        
    }

public: 
    ListNode* reverse(ListNode *front, ListNode *prev) {
    
        if(front == NULL) {
            return prev;
        }
        ListNode *rear = front->next;
        front->next = prev;
        return reverse(rear,front);
        
    }
};