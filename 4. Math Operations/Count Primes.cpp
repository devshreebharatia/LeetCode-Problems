/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */


class Solution {
public:
    int countPrimes(int n) {

        //Solution 1: Simplest solution is consider each number till n and
        // check if that number is prime. If yes increment the count.
        // Extremely inefficient solution with Time Complexity: O(n^2)
        int count = 0;
        if(n==0 || n==1) {
            return count;
        }
        for(int i=2;i<n;i++) {
            int j=2;
            bool prime = true;
            while(j<i) {
                if(i%j == 0) {
                    prime = false;
                    break;
                }
                j++;
            }
            if(prime) {
                count++;
            }
        }
        return count;
        
        //Solution 2: According to Wilson's formula, a number k is prime only 
        //when ((k-1)!+1)%k == 0
        int count = 0;
        if(n == 0 || n ==1) {
            return count;
        }
        
        int fact = 1;
        for(int i=2;i<n;i++) {
            fact = fact * (i-1);
            if((fact+1)%i == 0) {
                count++;
            }
        }
        return count;
        
        
        //Solution 3: According to Sieve of Eratosthenes method:
        //We traverse from 2 and strike off all the multiples of 2 till n.
        //The we move to next number 3, and strike off all its multiples.
        //We continue this process for all numbers upto n.
        
        if(n == 0) {
            return 0;
        }

        //Initially set all the values to true except for 0 and 1.
        vector<bool> primes(n,true);
        primes[0] = false;
        primes[1] = false;
      
        for(int i=2; i<=sqrt(n); i++) {
            
            if(primes[i]) {
                
                // For all the multiples of i, set them as non-prime
                for(int j=i*i; j<n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        
        return count(primes.begin(),primes.end(),true);
    }
};