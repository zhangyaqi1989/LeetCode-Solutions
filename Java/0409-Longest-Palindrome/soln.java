class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> chars = new HashMap<>();
        for(char ch : s.toCharArray()) {
            chars.put(ch, chars.getOrDefault(ch, 0) + 1);
        }
        int odds = 0;
        for(int cnt : chars.values()) {
            odds += cnt % 2;
        }
        return odds > 0 ? s.length() + 1 - odds : s.length();
    }
}
