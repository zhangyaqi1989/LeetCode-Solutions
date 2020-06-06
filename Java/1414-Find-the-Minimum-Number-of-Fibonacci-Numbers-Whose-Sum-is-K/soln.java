class Solution {
    public int findMinFibonacciNumbers(int k) {
        List<Integer> fibs = new ArrayList<>();
        fibs.add(1);
        fibs.add(1);
        int a = 1, b = 1;
        while(b <= k) {
            int c = a + b;
            a = b;
            b = c;
            fibs.add(c);
        }
        int cnt = 0;
        while(k != 0) {
            // find the first value >= k
            ++cnt;
            int lo = 0, hi = fibs.size();
            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (fibs.get(mid) >= k) hi = mid;
                else lo = mid + 1;
            }
            if(fibs.get(lo) == k) k = 0;
            else k -= fibs.get(lo - 1);
        }
        return cnt;
    }
}
