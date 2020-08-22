/*
We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.

Example 1:

Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
Output: 9
Explanation: The subset chosen is the first, third, and fifth item.

Example 2:

Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
Output: 12
Explanation: The subset chosen is the first, second, and third item.

Example 3:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
Output: 16
Explanation: The subset chosen is the first and fourth item.

Example 4:

Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
Output: 24
Explanation: The subset chosen is the first, second, and fourth item.

*/

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit)     {
        
        if(values.size() == 1) {
            return values[0];
        }
        vector<pair<int,int>> data;
        map<int,int> mp;
        
        for(int i=0;i<values.size();i++) {
            data.push_back(pair<int,int>(values[i],labels[i]));
            mp[labels[i]] = 0;
        }
        
        sort(data.begin(),data.end(),[](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first>b.first;
        });
        int result = 0;
        int count = 0;
        
        for(auto each_pair: data) {
            
            if(mp[each_pair.second] < use_limit) {
                result = result + each_pair.first;
                mp[each_pair.second]++;
                count++;
            }
            if(count == num_wanted) {
                break;
            }
        }
        return result;
    }
};