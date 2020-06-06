class Solution {
    public int uniqueLetterString(String S) {
        int [] lefts = new int[26];
        int [] rights = new int[26];
        Arrays.fill(lefts, -1);
        Arrays.fill(rights, -1);
        long ans = 0;
        int mod = 1000000007;
        int n = S.length();
        for(int idx = 0; idx < n; ++idx) {
            char ch = S.charAt(idx);
            int l = lefts[ch - 'A'];
            int r = rights[ch - 'A'];
            ans = (ans + (r - l) * (idx - r)) % mod;
            lefts[ch - 'A'] = r;
            rights[ch - 'A'] = idx;
        }
        for(int i = 0; i < 26; ++i) {
            ans = (ans + (rights[i] - lefts[i]) * (n - rights[i])) % mod;
        }
        return (int) ans;
    }
}
