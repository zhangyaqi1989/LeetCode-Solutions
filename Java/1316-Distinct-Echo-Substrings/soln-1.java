class Solution {
    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        long [] ps = new long [n];
        ps[0] = 1;
        final int P = 31;
        final int Mod = 1000000009;
        for(int i = 1; i < n; ++i) ps[i] = (ps[i - 1] * P) % Mod;
        long [] hs = new long [n + 1];
        for(int i = 0; i < n; ++i) {
            hs[i + 1] = (hs[i] + (text.charAt(i) - 'a') * ps[i]) % Mod;
        }
        int cnt = 0;
        for(int l = 1; l <= n / 2; ++l) {
            Set<Long> seen = new HashSet<>();
            for(int i = 0; i < n - 2 * l + 1; ++i) {
                long a = (hs[i + l] + Mod - hs[i]) % Mod;
                a = (a * ps[n - 1 - i]) % Mod;
                long b = (hs[i + l * 2] + Mod - hs[i + l]) % Mod;
                b = (b * (ps[n - 1 - i - l])) % Mod;
                if (a == b) seen.add(a);
            }
            cnt += seen.size();
        }
        return cnt;
    }
}
