class Solution {
    public String getHint(String secret, String guess) {
        Map<Character, Integer> m = new HashMap<>();
        int bull = 0, cow = 0, n = secret.length();
        for(int i = 0; i < n; ++i) {
            if (secret.charAt(i) == guess.charAt(i)) ++bull;
            else m.put(secret.charAt(i), m.getOrDefault(secret.charAt(i), 0) + 1);
        }
        for(int i = 0; i < n; ++i) {
            if (secret.charAt(i) != guess.charAt(i)) {
                char ch = guess.charAt(i);
                if(m.getOrDefault(ch, 0) > 0) {
                    ++cow;
                    m.put(ch, m.get(ch) - 1);
                }
            }
        }
        return String.format("%dA%dB", bull, cow);
        
    }
}
