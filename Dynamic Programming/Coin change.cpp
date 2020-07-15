/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up 
that amount. If that amount of money cannot be made up by any combination of the
coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1

 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        /* Solution: Dynamic Programming
         * solve smaller problems and use them to solve larger problems
        */
        
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        sort(coins.begin(),coins.end());
        
        for(int i=1; i<=amount;i++) {
            for(int j=0;j<coins.size();j++) {
                
                if(coins[j] <= i) {
                    int remaining_amount = i-coins[j];
                    dp[i] = min(dp[i], dp[remaining_amount] + 1);
                } 
                else {
                    break;
                }
            }
        }
        
        if(dp[amount] == amount+1) {
            return -1;
        }
        return dp[amount];
    }
};