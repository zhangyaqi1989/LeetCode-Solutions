class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> idxes = {-20000};
        int n = S.length();
        for(int i = 0; i < n; ++i) {
            if (S[i] == C) idxes.push_back(i);
        }
        idxes.push_back(40000);
        vector<int> ans;
        int idx = 0;
        for(int i = 0; i < n; ++i) {
            while (idxes[idx] < i) ++idx;
            ans.push_back(min(idxes[idx] - i, i - idxes[idx - 1]));
        }
        return ans;
    }
};
