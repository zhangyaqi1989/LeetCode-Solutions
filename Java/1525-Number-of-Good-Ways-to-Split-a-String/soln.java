class Solution {
    public int numSplits(String s) {
        int [] l_counter = new int [26];
        int [] r_counter = new int [26];
        int l = 0, r = 0;
        for(char ch : s.toCharArray()) {
            if(r_counter[ch - 'a']++ == 0) ++r;
        }
        int ans = 0;
        for(char ch : s.toCharArray()) {
            if(r_counter[ch - 'a']-- == 1) --r;
            if(l_counter[ch - 'a']++ == 0) ++l;
            if(l == r) ++ans;
        }
        return ans;
    }
}
