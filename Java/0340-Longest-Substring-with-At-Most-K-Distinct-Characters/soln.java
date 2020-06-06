class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> counter = new HashMap<>();
        int ans = 0, n = s.length(), lo = 0;
        for(int hi = 0; hi < n; ++hi) {
            counter.put(s.charAt(hi), counter.getOrDefault(s.charAt(hi), 0) + 1);
            while (counter.size() > k) {
                counter.put(s.charAt(lo), counter.get(s.charAt(lo)) - 1);
                if (counter.get(s.charAt(lo)) == 0) {
                    counter.remove(s.charAt(lo));
                }
                ++lo;
            }
            ans = Math.max(ans, hi - lo + 1);
        }
        return ans;        
    }
}
