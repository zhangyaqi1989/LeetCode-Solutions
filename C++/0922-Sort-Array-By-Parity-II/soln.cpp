class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int i = 0, j = n - 1;
        for (int i = 0, j = n - 1; i < n, j >= 0; i += 2, j -= 2) {
            while(i < n && A[i] % 2 == 0) i += 2;
            while(j >= 0 && A[j] % 2 == 1) j -= 2;
            if (i < n && j >= 0) swap(A[i], A[j]);
        }
        return A;
    }
};