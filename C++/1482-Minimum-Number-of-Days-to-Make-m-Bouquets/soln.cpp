class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int kN = bloomDay.size();
        if(kN < m * k) return -1;
        auto min_max = minmax_element(bloomDay.begin(), bloomDay.end());
        int lo = *(min_max.first), hi = *(min_max.second);
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(valid(bloomDay, m, k, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return valid(bloomDay, m, k, lo) ? lo : -1;
    }
    
private:
    bool valid(const vector<int> & bloomDay, int m, int k, int day) {
        int lo = 0;
        const int kN = bloomDay.size();
        int cnt = 0;
        for(int i = 0; i < kN; ++i) {
            if((day >= bloomDay[i]) != (day >= bloomDay[lo])) {
                if (day >= bloomDay[lo]) cnt += (i - lo) / k;
                lo = i;
            }
        }
        if(day >= bloomDay[lo]) {
            cnt += (kN - lo) / k;
        }
        return cnt >= m;
    }
};
