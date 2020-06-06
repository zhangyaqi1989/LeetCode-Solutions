class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size(), false);
        int val = 0;
        for(int i = 0; i < A.size(); ++i) {
            int num = A[i];
            val = (val * 2 + num) % 5;
            if (val == 0) ans[i] = true;
        }
        return ans;
    }
};
