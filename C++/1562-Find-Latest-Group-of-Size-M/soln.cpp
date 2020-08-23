class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        set<int> zeros;
        const int kN = arr.size();
        int ans = -1;
        int cnt = 0;
        for(int i = 0; i < kN + 2; ++i) zeros.insert(i);
        for(int i = 0; i < kN; ++i) {
            int idx = arr[i];
            auto it = zeros.find(idx);
            if(*(next(it)) - *(prev(it)) - 1 == m) ++cnt;
            if(*it - *(prev(it)) - 1 == m) --cnt;
            if(*(next(it)) - *it - 1 == m) --cnt;
            if(cnt > 0) ans = i + 1;
            zeros.erase(it);
        }
        return ans;
    }
};
