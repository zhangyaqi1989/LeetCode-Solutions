class Solution {
    public double[] sampleStats(int[] count) {
        double [] ans = new double [5];
        int total = 0;
        double mean = 0.0;
        int mode = -1, mx_cnt = 0;
        int mn = -1, mx = -1;
        for(int num = 0; num < 256; ++num) {
            int cnt = count[num];
            if (cnt > 0) {
                if(mn == -1) mn = num;
                mx = num;
                if(cnt > mx_cnt) {
                    mx_cnt = cnt;
                    mode = num;
                }
            }
            total += cnt;
            mean += cnt * num;
            if(num > 0) count[num] += count[num - 1];
        }
        mean /= total;
        // System.out.println(total);
        if (total % 2 == 1) ans[3] = find(count, (total + 1) / 2);
        else ans[3] = 0.5 * ((double) find(count, total / 2 + 1) + find(count, total / 2));
        ans[0] = mn;
        ans[1] = mx;
        ans[2] = mean;
        ans[4] = mode;
        return ans;
    }
    
    private int find(int [] count, int k) {
        // find first idx such that count[idx] >= k
        int lo = 0, hi = count.length;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (count[mid] >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        // System.out.println(lo);
        return lo;
    }
}
