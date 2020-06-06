/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    public void findSecretWord(String[] wordlist, Master master) {
        Random rand = new Random();
        for(int i = 0; i < 10; ++i) {
            int n = wordlist.length;
            int idx = rand.nextInt(n);
            String word = wordlist[idx];
            int match = master.guess(word);
            if (match == 6) break;
            List<String> temp = new ArrayList<>();
            for(String w : wordlist) {
                if (count_matchs(w, word) == match) temp.add(w);
            }
            wordlist = temp.toArray(new String[0]);
        }
    }
    
    public int count_matchs(String w1, String w2) {
        int n = w1.length(), cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (w1.charAt(i) == w2.charAt(i)) ++cnt;
        }
        return cnt;
    }
    
}
