class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n, 1);
        for(int i = 2; i < n; ++i) {
            if (primes[i]) {
                for(int j = i * 2; j < n; j += i) primes[j] = 0;
            }
        }
        return n >= 2 ? accumulate(primes.begin() + 2, primes.end(), 0) : 0;
    }
};
