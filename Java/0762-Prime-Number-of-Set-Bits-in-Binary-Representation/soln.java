class Solution {
    public int countPrimeSetBits(int L, int R) {
        final int N = 33;
        boolean [] isPrimes = new boolean [N];
        for(int num = 2; num < N; ++num) {
            isPrimes[num] = isPrime(num);
        }
        int cnt = 0;
        for(int num = L; num <= R; ++num) {
            if(isPrimes[setBits(num)]) ++cnt;
        }
        return cnt;
    }
    
    private boolean isPrime(int num) {
        for(int r = 2; r <= (int) Math.sqrt(num); ++r) {
            if(num % r == 0) return false;
        }
        return true;
    }
    
    private int setBits(int num) {
        int cnt = 0;
        while(num != 0) {
            cnt += num % 2;
            num /= 2;
        }
        return cnt;
    }
}
