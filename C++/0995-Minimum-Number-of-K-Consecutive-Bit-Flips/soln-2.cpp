class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        // A = [0, 1, 0]
        // [left, right]
        int cur_flips = 0;
        int ans = 0;
        const int n = A.size();
        vector<int> flips(n, 0);
        int i = 0;
        for(; i + K - 1 < n; ++i) {
            if (cur_flips % 2 == A[i]) {
                ++flips[i];
                --flips[i + K - 1];
                ++ans;
            }
            cur_flips += flips[i];
            // cout << cur_flips << endl;
        }
        for(int j = i; j < n; ++j) {
            if (cur_flips % 2 == A[j]) {
                return -1;
            }
            cur_flips += flips[j];
        }
        return ans;
    }
};
