class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        vector<int> ds(26, 0);
        for(size_t i = 0; i < s.length(); ++i) {
            int d = t[i] - s[i];
            if(d < 0) d += 26;
            if(d != 0) ++ds[d];
        }
        for(int i = 0; i < 26; ++i) {
            if(ds[i] != 0) {
                int mx = i + (ds[i] - 1) * 26;
                if(mx > k) return false;
            }
        }
        return true;
    }
};
