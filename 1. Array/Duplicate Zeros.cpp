/*

Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]

*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int count = 0;
        for(int i=0;i<arr.size();i++) {
            if(arr[i] == 0) {
                count++;
            }
        }
        if(count > 0) {
            
            for(int i=arr.size()-1;i>=0;i--) {
                
                if(arr[i] == 0) {
                    count--;
                }
                if(i+count < arr.size()) {
                    
                    arr[i + count] = arr[i];
                    
                    //Adding a duplicate zero
                    if(arr[i] == 0 && (i+count+1)<arr.size()) {
                        arr[i+count+1] = 0;
                    }
                } 
                
            }
    
        }
    }
};
