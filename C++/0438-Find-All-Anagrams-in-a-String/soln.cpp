class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        if (np > ns) return {};
        vector<int> ans;
        map<int, int> mp;
        for(char ch : p) ++mp[ch];
        for(int i = 0; i < ns - np + 1; ++i) {
            map<int, int> ms;
            for(int j = i; j < i + np; ++j) {
                ++ms[s[j]];
            }
            if (ms.size() == mp.size() && equal(mp.begin(), mp.end(), ms.begin()))
                ans.push_back(i);
        }
        return ans;
    }
};
