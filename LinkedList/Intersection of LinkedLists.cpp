/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two 
lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, 
it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes 
before the intersected node in B.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) {
            return NULL;
        }
        
        ListNode *a, *b;
        a = headA;
        b = headB;
        
        int distance = len(a) - len(b);
        
        //If list A is longer than B
        while(distance > 0) {
            a = a->next;
            distance--;
        }
        
        //If list B is longer than A
        while(distance < 0) {
            b = b->next;
            distance++;
        }
        
          
        while(a && b) {
            if(a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
        
        return NULL;
    }
    
public:
    int len(ListNode *curr) {
        
        int length = 0;
        while(curr) {
            length++;
            curr = curr->next;
        }
        return length;
    }
};