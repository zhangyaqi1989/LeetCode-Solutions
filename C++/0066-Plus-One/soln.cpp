class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = -1;
        for(auto i = 0; i < digits.size(); ++i)
            if(digits[i] != 9)
                idx = i;
        if (idx == -1)
        {
            vector<int> ans(digits.size() + 1, 0);
            ans[0] = 1;
            return ans;
        } else
        {
            vector<int> ans(digits);
            ans[idx] += 1;
            for(auto j = idx + 1; j < ans.size(); ++j)
                ans[j] = 0;
            return ans;
        }
        
    }
};