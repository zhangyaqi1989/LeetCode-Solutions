class Solution {
    public List<String> commonChars(String[] A) {
        int[] chars = new int[26];
        Arrays.fill(chars, Integer.MAX_VALUE);
        for(String str : A) {
            int[] temp = new int[26];
            for(char ch : str.toCharArray()) {
                ++temp[ch - 'a'];
            }
            for(int i = 0; i < 26; ++i) chars[i] = Math.min(chars[i], temp[i]);
        }
        List<String> ans = new ArrayList<>();
        for(int i = 0; i < 26; ++i) {
            for(int j = 0; j < chars[i]; ++j) {
                ans.add(Character.toString((char)('a' + i)));
            }
        }
        return ans;
    }
}
