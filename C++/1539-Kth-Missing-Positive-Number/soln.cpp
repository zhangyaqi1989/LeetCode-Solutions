class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx = 0;
        const int kN = arr.size();
        for(int nxt = 1; ; ++nxt) {
            if(idx < kN && arr[idx] == nxt) {
                ++idx;
            } else {
                if(k-- == 1) return nxt;
            }
        }
        return -1;
    }
};
