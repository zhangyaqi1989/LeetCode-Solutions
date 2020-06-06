class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> seen(1 << k, false);
        int unit = 1 << k;
        const int kN = s.length();
        int cur = 0;
        for(int i = 0; i < kN; ++i) {
            cur = cur * 2 + s[i] - '0';
            if(i >= k && s[i - k] == '1') cur -= unit;
            if(i >= k - 1) seen[cur] = true;
        }
        return find(seen.begin(), seen.end(), false) == seen.end(); 
    }
};
