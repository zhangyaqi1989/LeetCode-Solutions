class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = -50000;
        int max_seen = -2000;
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            ans = max(ans, max_seen + A[i] - i);
            max_seen = max(max_seen, A[i] + i);
        }
        return ans;
    }
};
