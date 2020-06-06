class Solution {
    public boolean wordPattern(String pattern, String str) {
        String [] tokens = str.split(" ");
        if (tokens.length != pattern.length()) return false;
        Map<Character, Integer> p_map = new HashMap<>();
        Map<String, Integer> w_map = new HashMap<>();
        for(int i = 0; i < tokens.length; ++i) {
            char ch = pattern.charAt(i);
            String word = tokens[i];
            p_map.put(ch, p_map.getOrDefault(ch, p_map.size()));
            w_map.put(word, w_map.getOrDefault(word, w_map.size()));
            if (p_map.get(ch) != w_map.get(word)) return false;
        }
        return true;
    }
}
