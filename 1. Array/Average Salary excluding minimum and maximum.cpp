
/*
Given an array of unique integers salary where salary[i] is the salary of the employee i.

Return the average salary of employees excluding the minimum and maximum salary.


Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500

*/

class Solution {
public:
    double average(vector<int>& salary) {
        
        int i=0;
        int sum = 0;
        int minSal = INT_MAX;
        int maxSal = INT_MIN;
        
        while(i<salary.size()) {
            
            maxSal = max(maxSal,salary[i]);
            minSal = min(minSal,salary[i]);
            sum = sum + salary[i];
            i++;
        }
        
        sum = sum - (maxSal + minSal);
        return sum/((salary.size()-2)*1.0);
       
    }
};