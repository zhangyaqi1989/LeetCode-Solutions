class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> pool = new HashSet<>();
        for(String word : words) pool.add(word);
        for(String word : words) {
            int len = word.length();
            for(int i = 1; i < len; ++i) {
                pool.remove(word.substring(i));
            }
        }
        int ans = 0;
        for(String word : pool) {
            ans += word.length() + 1;
        }
        return ans;
    }
}
