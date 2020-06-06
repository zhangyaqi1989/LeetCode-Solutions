class Solution {
    public int fib(int N) {
        if (N < 2) return N;
        int pre = 0, cur = 1;
        for(int i = 2; i <= N; ++i) {
            int temp = cur;
            cur += pre;
            pre = temp;
        }
        return cur;
    }
}
