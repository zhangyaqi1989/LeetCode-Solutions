class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<int> primes(n, 1);
        primes[0] = 0;
        primes[1] = 0;
        for(int i = 2; i < n; ++i)
        {
            if(primes[i] == 1)
            {
                for(int j = 2 * i; j < n; j += i)
                    primes[j] = 0;
            }
        }
        return accumulate(primes.begin(), primes.end(), 0);
    }
};