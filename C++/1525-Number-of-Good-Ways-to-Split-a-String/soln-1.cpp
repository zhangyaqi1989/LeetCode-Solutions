class Solution {
public:
    int numSplits(string s) {
        int l_counter[26] = {0};
        int r_counter[26] = {0};
        int l = 0, r = 0;
        for(char ch : s) {
            if(r_counter[ch - 'a']++ == 0) ++r;
        }
        int ans = 0;
        for(char ch : s) {
            if(r_counter[ch - 'a']-- == 1) --r;
            if(l_counter[ch - 'a']++ == 0) ++l;
            ans += l == r;
        }
        return ans;
    }
};
