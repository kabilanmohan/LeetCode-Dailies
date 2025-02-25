class Solution {
public:

    // Sieve of Eratosthenes
    void seive(int n , vector<bool> &primes)
    {
        for(int p = 2 ; p*p <= n ; p++)
        {
            if(primes[p])
            {
                for(int i = p*p ; i <= n ; i += p) primes[i] = false;
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) 
    {
        vector<bool> primes(n+1 , true);
        vector<vector<int>> result;

        seive(n , primes);

        for(int i = 2 ; i <= n/2 ; i++)
        {
            if(primes[i] && primes[n-i]) result.push_back({i,n-i});
        }
        return result;
    }
};
