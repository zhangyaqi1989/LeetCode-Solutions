class Solution {
    public boolean queryString(String S, int N) {
        int num = N;
        int n = 0;
        int ns = S.length();
        while (num > 0) {
            ++n;
            num /= 2;
        }
        if (n * ns < N) return false;
        Set<Integer> seen = new HashSet<>();
        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i < ns + 1 - len; ++i) {
                seen.add(toBin(S.substring(i, i + len)));
            }
        }
        for(int i = 1; i <= N; ++i) {
            if(!seen.contains(i)) return false;
        }
        return true;
    }
    
    public int toBin(String S) {
        int ans = 0;
        for(int ch : S.toCharArray()) {
            ans = ans * 2 + (ch - '0');
        }
        return ans;
    }
}
