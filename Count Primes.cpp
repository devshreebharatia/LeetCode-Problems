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
        
        //According to Wilson's formula, a number k is prime only when ((k-1)!+1)%k == 0
        /*int count = 0;
        if(n == 0 || n ==1) {
            return count;
        }
        
        int fact = 1;
        for(int i=2;i<n;i++) {
            fact = fact * (i-1);
            cout<<"\n fact: "<<fact;
            if((fact+1)%i == 0) {
                cout<<"\n"<<i;
                count++;
            }
        }
        return count;*/
        
        
        //According to Sieve of Eratosthenes method:
        
        if(n == 0) {
            return 0;
        }
        vector<bool> primes(n,true);
        primes[0] = false;
        primes[1] = false;
      
        for(int i=2; i<=sqrt(n); i++) {
            
            if(primes[i]) {
                
                for(int j=i*i; j<n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        
        return count(primes.begin(),primes.end(),true);
    }
};