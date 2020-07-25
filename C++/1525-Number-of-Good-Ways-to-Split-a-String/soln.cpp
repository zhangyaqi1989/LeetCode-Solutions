class Solution {
public:
    int numSplits(string s) {
        int l_counter[26] = {0};
        int r_counter[26] = {0};
        int l = 0, r = 0;
        for(char ch : s) {
            if(r_counter[ch - 'a'] == 0) {
                ++r;
            }
            ++r_counter[ch - 'a'];
        }
        int ans = 0;
        for(char ch : s) {
            if(r_counter[ch - 'a'] == 1) {
                --r;
            }
            if(l_counter[ch - 'a'] == 0) {
                ++l;
            }
            --r_counter[ch - 'a'];
            ++l_counter[ch - 'a'];
            ans += l == r;
        }
        return ans;
    }
};
