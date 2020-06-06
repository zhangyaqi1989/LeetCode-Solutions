class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        const int kN = A.size();
        for(int i = 0; i < kN - 2; ++i) {
            if (A[i] < A[i + 1] + A[i + 2]) return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};
