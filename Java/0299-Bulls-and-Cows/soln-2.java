class Solution {
    public String getHint(String secret, String guess) {
        int [] g_counter = new int [10];
        int [] s_counter = new int [10];
        int n = secret.length();
        int bulls = 0;
        for(int i = 0; i < n; ++i) {
            if (guess.charAt(i) == secret.charAt(i)) ++bulls;
            ++g_counter[guess.charAt(i) - '0'];
            ++s_counter[secret.charAt(i) - '0'];
        }
        int cows = 0;
        for(int i = 0; i < 10; ++i) {
            cows += Math.min(g_counter[i], s_counter[i]);
        }
        return bulls + "A" + (cows - bulls) + "B";
    }
}
