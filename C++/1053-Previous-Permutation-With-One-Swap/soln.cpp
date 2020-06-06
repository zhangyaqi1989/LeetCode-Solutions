class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        for(int i = n - 1; i > 0; --i) {
            if (A[i] < A[i - 1]) {
                for(int j = n - 1; j > 0; --j) {
                    if (A[j] < A[i - 1]) {
                        swap(A[j], A[i - 1]);
                        return A;
                    }
                }
            }
        }
        return A;
    }
};
