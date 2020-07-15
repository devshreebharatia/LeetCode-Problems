/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
 */

 class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		map<string,vector<string>> m;
		for(int i=0;i<strs.size();i++){
			string temp=strs[i];
			sort(temp.begin(),temp.end());
			m[temp].push_back(strs[i]);
		}
		for(auto element:m){
			result.push_back(element.second);
		}
		return result;
	}
};