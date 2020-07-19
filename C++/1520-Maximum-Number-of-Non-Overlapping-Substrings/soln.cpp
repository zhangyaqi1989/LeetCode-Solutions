class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> left(26, -1), right(26, -1);
        for(int i = 0; i < s.length(); ++i) {
            int idx = s[i] - 'a';
            if(left[idx] == -1) left[idx] = i;
            right[idx] = i;
        }
        vector<pair<int, int>> cands;
        for(int i = 0; i < 26; ++i) {
            if(left[i] != -1) {
                int lo = left[i];
                int hi = right[i];
                for(int j = left[i]; j <= right[i]; ++j) {
                    int idx = s[j] - 'a';
                    lo = min(lo, left[idx]);
                    hi = max(hi, right[idx]);
                }
                int l = left[i], r = right[i];
                while(l > lo || r < hi) {
                    if(l > lo) {
                        int idx = s[l] - 'a';
                        lo = min(lo, left[idx]);
                        hi = max(hi, right[idx]);
                        --l;
                    }
                    if(r < hi) {
                        int idx = s[r] - 'a';
                        lo = min(lo, left[idx]);
                        hi = max(hi, right[idx]);
                        ++r;
                    }
                }
                cands.emplace_back(lo, hi);
            }
        }
        int lo = -1;
        sort(cands.begin(), cands.end(), [](const pair<int, int> & a, const pair<int, int> & b) {
            return a.second == b.second ? a.second - a.first < b.second - b.first : a.second < b.second;
        });
        vector<string> ans;
        for(const auto & [a, b] : cands) {
            if(lo < a) {
                lo = b;
                ans.push_back(s.substr(a, b - a + 1));
            }
        }
        return ans;
    }
};
