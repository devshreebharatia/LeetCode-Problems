# LeetCode-Problems
This repository contains all the competitive codes from leetcode.com


TRICKS:

1. When the time complexity is expected to be o(logn), always use binary search.

2. Time complexity for insertion, deletion, traversal etc for vectors is less
expensive than arrays. 

3. Always try to use arrays and vectors instead of hashmaps. Hashmaps are much 
more expensive. If arrays/vectors cannot be used, then only use maps.
Note: Map traversal is not in order. Especially when the problem says, only
lowercase letters are used, always use arrays/vectors.

4. Never use swap operations. They are extremely expensive. Always try to 
overwrite the values. This will make the valid values come at the start of the
array, and the invalid values at the end. But most sums always want the length
of the array till the valid values. Hence the rest of the elements do not
matter.

5. Try to use WHILE loop when you need flexibility in the index movements. If not
use FOR loop. For maps, use for each loop with an iterator.

6. In a loop always first check the termination condition which is required for making
iterator changes. The changes which are common for every iteration,
must be specified at the end before the loop ends.(Code Optimization)

7. Always try to use XOR for a problem where you have to eliminate numbers that 
occur twice. This is because XORing the same numbers results in 0. 
Basic Working of XOR:
x^x = 0
x^0 = x
AND operation helps to obtain carry: because when 1&1 is 1 else all other cases are 0

8. So when the numbers are from 1 to n, its a hint that the problem can be solved
in the given time O(n) and without any extra space. Also, when the given data is
sorted, it is of a lot of help. But if neither of these bonuses are available, it
indicates that you need to use extra space. If in case extra space does not help,
then using extra time will be the last option to be used.

9. When the position i does not matter you have to use vector.push_back. 

