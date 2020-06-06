class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if (A.size() == 0) return 0;
        int ans = 0;
        sort(A.begin(), A.end());
        int need = A[0];
        for (int item : A) {
            ans += max(need - item, 0);
            need = max(need + 1, item + 1);
        }
        return ans;
    }
};