class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        multiset<int> seen;
        int n = s.length();
        map<char, int> m = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int num = 0;
        for(int i = 0; i < 10; ++i) num = num * 4 + m[s[i]];
        seen.insert(num);
        int unit = pow(4, 10);
        for(int i = 10; i < n; ++i) {
            num = num * 4 - m[s[i - 10]] * unit + m[s[i]];
            if (seen.count(num) == 1) ans.push_back(s.substr(i - 9, 10));
            seen.insert(num);
        }
        return ans;
    }
};
