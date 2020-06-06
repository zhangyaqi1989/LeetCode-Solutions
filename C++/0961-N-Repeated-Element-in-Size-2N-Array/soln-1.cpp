class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int i = 0, j = 0, n = A.size();
        while (i == j || A[i] != A[j]) {
            i = rand() % n;
            j = rand() % n;
        }
        return A[i];
    }
};
