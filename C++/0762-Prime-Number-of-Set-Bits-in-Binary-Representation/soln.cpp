class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        vector<bool> primes(32, false);
        for(int i = 2; i <= 32; ++i) {
            if(isPrime(i)) primes[i] = true;
        }
        int cnt = 0;
        for(int i = L; i <= R; ++i) {
            if(primes[__builtin_popcount(i)]) ++cnt;
        }
        return cnt;
    }
    
    bool isPrime(int n) {
        for(int i = 2; i < (int) sqrt(n) + 1; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
    
};
