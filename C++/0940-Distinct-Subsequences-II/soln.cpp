class Solution {
public:
    int distinctSubseqII(string S) {
        vector<int> memo(26, 0);
        int mod = 1000000007;
        long long acc = 0LL;
        for(char ch : S) {
            int add = (acc - memo[ch - 'a'] + 1) % mod;
            memo[ch - 'a'] += add;
            acc = (acc + add) % mod;
        }
        return acc;
    }
};
