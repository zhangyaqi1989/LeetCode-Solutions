class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans = 0, zeros = 0, n = A.size();
        for(int l = 0, h = 0; h < n; ++h) {
            if (A[h] == 0) ++zeros;
            while (zeros > K) {
                if (A[l++] == 0)
                    --zeros;
            }
            ans = max(ans, h - l + 1);
        }
        return ans;
    }
};
