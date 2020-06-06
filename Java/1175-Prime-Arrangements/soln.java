class Solution {
    public int numPrimeArrangements(int n) {
        // number of primes
        int cnt = 0;
        for(int i = 2; i <= n; ++i) {
            if(isPrime(i)) ++cnt;
        }
        return (int) (factorial(cnt) * factorial(n - cnt) % 1000000007);
    }
    
    private long factorial(int n) {
        int mod = 1000000007;
        long ans = 1;
        for(int i = 1; i <= n; ++i) {
            ans = (ans * i) % mod;
        }
        return ans;
    }
    
    private boolean isPrime(int num) {
        for(int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
}
