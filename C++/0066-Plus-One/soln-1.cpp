class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits);
        int idx = -1, n = ans.size();
        for(int i = 0; i < n; ++i) {
            if (digits[i] != 9) idx = i;
        }
        int cur = idx + 1;
        for(; cur < n; ++cur) ans[cur] = 0;
        if (idx == -1) ans.insert(ans.begin(), 1);
        else ++ans[idx];
        return ans;
    }
};
