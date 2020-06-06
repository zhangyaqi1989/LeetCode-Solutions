class Solution {
    public int numberOfSubstrings(String str) {
        int ans = 0;
        int i = 0;
        Map<Character, Integer> window = new HashMap<>();
        for(char ch : str.toCharArray()) {
            window.put(ch, window.getOrDefault(ch, 0) + 1);
            if (window.size() == 3) {
                while (window.containsKey(str.charAt(i)) && window.get(str.charAt(i)) > 1) {
                    window.put(str.charAt(i), window.get(str.charAt(i)) - 1);
                    ++i;
                }
                ans += i + 1;
            }
            
        }
        return ans;
    }
}
