# LeetCode-Problems
This repository contains all the competitive codes from leetcode.com


TRICKS:

7. Always try to use XOR for a problem where you have to eliminate numbers that 
occur twice. This is because XORing the same numbers results in 0. Or to find an 
element that occurs only once, you can use XOR.
Basic Working of XOR:
x^x = 0
x^0 = x

If suppose there one element that occurs once and the rest twice, XORing all
the elements of the array will help to obtain that one element.
Now if suppose there are two elements that occur once and you have to find them,
then XORing the entire array wont work. In this case, you XOR the entire array
such that you find a non-zero XOR value.
Eg: [4,2,3,2,3,1] XORing = 4^1 = 0101 in binary
Now take any kth bit say bit at 2nd position which is 1 and then make two groups
a group with elemets that have this bit set and the other that dont.
Set 1: 4
Set 2: 2,3,2,3,1
XORing elments of both sets individually will give you 4 and 1 respectively!!

AND operation helps to obtain carry: because when 1&1 is 1 else all other cases are 0

11. Depth First Search and Breadth First Search
DFS is implemented using stack whereas BFS is implemented using queue
In DFS: If the current node does not have any child nodes/ the child/adjacent nodes have been visited,
pop the element. It uses recursion. It is used for problems like reaching a specific goal/ sinking the
co-ordinate etc. Low memory requirements.

In BFS: If both the child nodes of the current nodes have been enqueued into the queue then dequeue
the current node. It never uses recursion. It is used for problems like finding shortest path.
High memory requirements.

Same space and Time complexities for both:
Space Complexity: O(|V|)
Time Complexity: O(|V| + |E|)


13. Dynamic Programming: Whenever you have to divide a problem into several sub-problems, we need
to use dynamic programming.


