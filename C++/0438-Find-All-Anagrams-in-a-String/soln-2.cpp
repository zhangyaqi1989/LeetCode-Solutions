class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> chars(26, 0);
        for(char ch : p) ++chars[ch - 'a'];
        int ns = s.length(), np = p.length();
        for(int i = 0; i < ns; ++i) {
            --chars[s[i] - 'a'];
            if(i >= np) ++chars[s[i - np] - 'a'];
            if(i >= np - 1) {
                if(all_of(chars.begin(), chars.end(), [](int x) {return x == 0;})) {
                    ans.push_back(i - np + 1);
                }
            }
        }
        return ans;
    }
};
