class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool inc = A[n - 1] > A[0];
        for(int i = 1; i < n; ++i) {
            if (A[i] != A[i - 1] && A[i] > A[i - 1] != inc)
                return false;
        }
        return true;
    }
};
