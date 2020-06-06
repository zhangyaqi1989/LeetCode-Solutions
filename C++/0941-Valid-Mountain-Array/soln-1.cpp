class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int i = 0, j = n - 1;
        while (i + 1 < n && A[i + 1] > A[i]) ++i;
        while (j - 1 >= 0 && A[j - 1] > A[j]) --j;
        return i > 0 && i == j && j < n - 1;
    }
};