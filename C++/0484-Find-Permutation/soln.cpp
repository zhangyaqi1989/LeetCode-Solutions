class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.length();
        vector<int> ans;
        ans.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            ans[i] = i + 1;
        }
        int cnt = 0;
        s += 'I';
        for(int i = 0; i < n + 1; ++i) {
            if (s[i] == 'D') {
                ++cnt;
            } else {
                int lo = i - cnt;
                reverse(ans.begin() + lo, ans.begin() + lo + cnt + 1);
                cnt = 0;
            }
        }
        return ans;
    }
};
