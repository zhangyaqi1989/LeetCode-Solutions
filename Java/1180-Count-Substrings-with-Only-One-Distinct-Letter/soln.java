class Solution {
    public int countLetters(String S) {
        Map<Character, Integer> window = new HashMap<>();
        int ans = 0, i = 0, n = S.length();
        for(int j = 0; j < n; ++j) {
            window.put(S.charAt(j), window.getOrDefault(S.charAt(j), 0) + 1);
            while (window.size() > 1) {
                int cnt = window.get(S.charAt(i));
                if(cnt == 1) window.remove(S.charAt(i));
                else window.put(S.charAt(i), cnt - 1);
                ++i;
            }
            ans += j - i + 1;
        }
        return ans;
    }
}
