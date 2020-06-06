class Solution {
    public boolean isAnagram(String s, String t) {
        int[] chars = new int[26];
        for(char ch : s.toCharArray()) ++chars[ch - 'a'];
        for(char ch : t.toCharArray()) --chars[ch - 'a'];
        for(int i = 0; i < 26; ++i) 
            if (chars[i] != 0)
                return false;
        return true;
    }
}
