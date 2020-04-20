/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        
        //Solution 1: Reverse the complete linkedist and then compare the previous list to the new one.
        
        //Solution 2: Reverse only the second half and then compare the two halves.
        
        
        //Find the middle
        ListNode *fast, *slow, *prev, *front, *rear;
        fast = head;
        slow = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(fast) {
            slow = slow->next;
        }
        
        
        //Reversing the second half
        front = slow;
        prev = NULL;
        
        while(front) {
            
            rear = front->next;
            front->next = prev;
            prev = front;
            front = rear;
            
        }
    
        //Comparing the two halves
        front = head;
        rear = prev;
        
        while(rear != NULL) {
            
            if(front->val != rear->val) {
                return false;
            }
            front = front->next;
            rear = rear->next;
        }
        
        return true;
        
    }
};