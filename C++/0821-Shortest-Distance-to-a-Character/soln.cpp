class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> idxes = {-20000};
        int n = S.length();
        for(int i = 0; i < n; ++i) {
            if (S[i] == C) idxes.push_back(i);
        }
        idxes.push_back(20000);
        vector<int> ans;
        ans.reserve(n);
        int left = 0;
        for(int i = 0; i < n; ++i) {
            if (i >= idxes[left + 1]) ++left;
            ans.push_back(min(i - idxes[left], idxes[left + 1] - i));
        }
        return ans;
    }
};
