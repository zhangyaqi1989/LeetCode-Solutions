class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        for(int i = 2; i < A.size(); ++i) {
            if (A[i - 1] + A[i - 2] > A[i])
                ans = max(ans, A[i - 1] + A[i - 2] + A[i]);
        }
        return ans;
    }
};
