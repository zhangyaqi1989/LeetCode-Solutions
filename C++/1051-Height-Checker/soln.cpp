class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> rhs(heights.begin(), heights.end());
        sort(rhs.begin(), rhs.end());
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (rhs[i] != heights[i]) ++cnt;
        }
        return cnt;
    }
};
