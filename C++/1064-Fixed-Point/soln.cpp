class Solution {
public:
    int fixedPoint(vector<int>& A) {
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            if (i == A[i]) return i;
        }
        return -1;
    }
};
