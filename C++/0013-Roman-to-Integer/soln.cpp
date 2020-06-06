class Solution {
public:
    int romanToInt(string s) {
        map<char, int> units;
        units['I'] = 1;
        units['V'] = 5;
        units['X'] = 10;
        units['L'] = 50;
        units['C'] = 100;
        units['D'] = 500;
        units['M'] = 1000;
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += units[s[i]];
            if (i > 0 && units[s[i]] > units[s[i - 1]]) {
                ans -= 2 * units[s[i - 1]];
            }
        }
        return ans;
    }
};
