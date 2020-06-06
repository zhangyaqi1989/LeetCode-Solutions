class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1, 0);
        for(int i = 0; i < n; ++i) {
            int inc = pow(2, i);
            int size = ans.size();
            for(int j = size - 1; j >= 0; --j)
                ans.push_back(ans[j] + inc);
        }
        return ans;
    }
};