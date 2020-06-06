class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int mn = -1, mx = -1;
        int mx_cnt = 0, mode = -1;
        int total = 0;
        double mean = 0.0;
        for(int num = 0; num < 256; ++num) {
            int cnt = count[num];
            if(cnt > 0) {
                if(mn == -1) mn = num;
                mx = num;
                total += cnt;
                mean += cnt * num;
                if (cnt > mx_cnt) {
                    mx_cnt = cnt;
                    mode = num;
                }
                
            }
            if (num > 0) count[num] += count[num - 1];
        }
        mean /= total;
        double median = 0.0;
        if(total % 2 == 1) median = find(count, (total + 1) / 2);
        else median = 0.5 * ((double) find(count, total / 2) + find(count, total / 2 + 1));
        return {mn, mx, mean, median, mode};
    }
    
    private:
    int find(vector<int> count, int k) {
        int lo = 0, hi = count.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(count[mid] >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
