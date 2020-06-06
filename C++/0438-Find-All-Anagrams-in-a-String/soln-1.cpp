class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        if (np > ns) return {};
        vector<int> ans;
        map<int, int> mp;
        map<int, int> ms;
        for(char ch : p) ++mp[ch];
        for(int i = 0; i < np; ++i) ++ms[s[i]];
        if (mapEqual(mp, ms)) ans.push_back(0);
        for(int i = 0; i < ns - np; ++i) {
            --ms[s[i]];
            if (ms[s[i]] == 0) ms.erase(s[i]);
            ++ms[s[i + np]];
            if (mapEqual(mp, ms)) ans.push_back(i + 1);
        }
        return ans;
    }
    
    bool mapEqual(map<int, int> & ms, map<int, int> & mp) {
        return ms.size() == mp.size() && equal(mp.begin(), mp.end(), ms.begin());
    }
};
