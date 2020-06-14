class Solution {
    public int countLargestGroup(int n) {
        final int N = 100;
        int [] counter = new int [N];
        for(int num = 1; num <= n; ++num) {
            int val = num;
            int cnt = 0;
            while(val != 0) {
                cnt += val % 10;
                val /= 10;
            }
            ++counter[cnt];
        }
        int mx = 0;
        for(int i = 0; i < N; ++i) mx = Math.max(mx, counter[i]);
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            if(counter[i] == mx) ++ans;
        }
        return ans;
    }
}
