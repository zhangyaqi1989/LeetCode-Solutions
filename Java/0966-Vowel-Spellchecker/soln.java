class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> words = new HashSet<>();
        Map<String, String> words_lower = new HashMap<>();
        Map<String, String> words_no_vowel = new HashMap<>();
        for(String word : wordlist) {
            words.add(word);
            String word_lower = word.toLowerCase();
            if (!words_lower.containsKey(word_lower)) words_lower.put(word_lower, word);
            String word_no_vowel = toNoVowel(word);
            if (!words_no_vowel.containsKey(word_no_vowel)) words_no_vowel.put(word_no_vowel, word);
        }
        int n = queries.length;
        String [] ans = new String [n];
        for(int i = 0; i < n; ++i) {
            String q = queries[i];
            if (words.contains(q)) {
                ans[i] = q;
            } else {
                String word_lower = q.toLowerCase();
                String word_no_vowel = toNoVowel(q);
                if (words_lower.containsKey(word_lower)) {
                    ans[i] = words_lower.get(word_lower);
                } else if (words_no_vowel.containsKey(word_no_vowel)) {
                    ans[i] = words_no_vowel.get(word_no_vowel);
                } else {
                    ans[i] = "";
                }
            }
        }
        return ans;
    }
    
    private String toNoVowel(String word) {
        StringBuilder sb = new StringBuilder();
        for(char ch : word.toCharArray()) {
            char ch_lower = Character.toLowerCase(ch);
            if (ch_lower == 'a' || ch_lower == 'e' || ch_lower == 'i' || ch_lower == 'o' || ch_lower == 'u') {
                ch_lower = '#';
            }
            sb.append(ch_lower);
        }
        // String word_no_vowel = sb.toString();
        return sb.toString();
    }
}
