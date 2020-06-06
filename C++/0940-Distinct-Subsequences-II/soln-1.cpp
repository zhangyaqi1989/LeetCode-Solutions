class Solution {
public:
    int distinctSubseqII(string S) {
        vector<int> memo(26, 0);
        int mod = 1000000007;
        int acc = 0;
        for(char ch : S) {
            int add = (acc - memo[ch - 'a'] + 1) % mod;
            memo[ch - 'a'] = (memo[ch - 'a'] + add) % mod;
            acc = (acc + add) % mod;
        }
        return (acc + mod) % mod;
    }
};
