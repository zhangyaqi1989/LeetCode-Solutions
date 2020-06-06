class Solution {
    public int firstUniqChar(String s) {
        int[] chars = new int[26];
        for(char ch : s.toCharArray()) ++chars[ch - 'a'];
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            if (chars[s.charAt(i) - 'a'] == 1) return i;
        }
        return -1;
    }
}
