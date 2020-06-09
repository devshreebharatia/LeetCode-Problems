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

8. So when the numbers are from 1 to n, its a hint that the problem can be solved
in the given time O(n) and without any extra space. Also, when the given data is
sorted, it is of a lot of help. But if neither of these bonuses are available, it
indicates that you need to use extra space. If in case extra space does not help,
then using extra time will be the last option to be used.

9. When the position i does not matter you have to use vector.push_back. 

10. SLIDING WINDOW PROBLEM:

Identifying these problems:
a. Sequential iteration of a data structure
b. for identifying contiguous sequence of elements(Eg: a subarray)
c. Usually used with strings, arrays and linked lists
d. While trying to find min, max, longest subarray, shortest subarray,somethings is contained within a DS.

Two Types of sliding window problems:
1. static i.e. the size of the window remains the same, which are easy problems
2. dynamic i.e we have to grow and shrink the size of the sliding window according to the given conditions