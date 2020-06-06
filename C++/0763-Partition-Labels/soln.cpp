class Solution {
public:
    vector<int> partitionLabels(string S) {
        int lasts[26] = {0};
        int n = S.length();
        for(int i = 0; i < n; ++i) lasts[S[i] - 'a'] = i;
        vector<int> ans;
        int lo = 0, last = 0;
        for(int i = 0; i < n; ++i) {
            last = max(last, lasts[S[i] - 'a']);
            if (last == i) {
                ans.push_back(i - lo + 1);
                lo = i + 1;
            }
        }
        return ans;
    }
};
