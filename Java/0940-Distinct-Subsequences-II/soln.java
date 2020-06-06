class Solution {
    public int distinctSubseqII(String S) {
        int memo [] = new int [26];
        int acc = 0, add = 0, mod = (int)1e9 + 7;
        for(char ch : S.toCharArray()) {
            add = (acc + 1 - memo[ch - 'a']) % mod;
            acc = (acc + add) % mod;
            memo[ch - 'a'] = (memo[ch - 'a'] + add) % mod;
        }
        return (acc + mod) % mod;
    }
}


