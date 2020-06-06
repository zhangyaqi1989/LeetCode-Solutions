class Solution {
    public String getHint(String secret, String guess) {
        int [] m = new int [10];
        int bull = 0, cow = 0, n = secret.length();
        for(int i = 0; i < n; ++i) {
            if (secret.charAt(i) == guess.charAt(i)) ++bull;
            else ++m[secret.charAt(i) - '0'];
        }
        for(int i = 0; i < n; ++i) {
            if (secret.charAt(i) != guess.charAt(i)) {
                char ch = guess.charAt(i);
                if(m[ch - '0'] > 0) {
                    ++cow;
                    --m[ch - '0'];
                }
            }
        }
        return String.format("%dA%dB", bull, cow);
        
    }
}
