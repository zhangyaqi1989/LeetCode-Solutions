class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        ArrayList<String>[] pres = new ArrayList[26];
        for(int i = 0; i < 26; ++i) pres[i] = new ArrayList<>();
        for(String word : words) {
            int idx = word.charAt(0) - 'a';
            pres[idx].add(word.substring(1));
        }
        int cnt = 0;
        for(char ch : S.toCharArray()) {
            ArrayList<String> temp = new ArrayList<>(pres[ch - 'a']);
            if (temp.size() != 0) {
                pres[ch - 'a'].clear();
                for(String item : temp) {
                    if (item.length() == 0) ++cnt;
                    else pres[item.charAt(0) - 'a'].add(item.substring(1));
                }
            }
        }
        return cnt;
    }
}
