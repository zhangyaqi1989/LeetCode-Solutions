class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        for (auto i = 0; i < rowIndex + 1; ++i)
        {
            for(auto j = i - 1; j >= 1; --j)
                ans[j] = ans[j] + ans[j - 1];
        }
        return ans;
    }
};