ass Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int mx = INT_MIN;
        int n = A.size();
        for(int i = 0; i < n - 2; ++i) {
            mx = max(A[i], mx);
            if (mx > A[i + 2]) return false;
        }
        return true;
    }
};
