class Solution {
    public String longestWord(String[] words) {
        Arrays.sort(words);
        String ans = "";
        Set<String> s = new HashSet<>();
        for(String word : words) {
            if (word.length() == 1 || s.contains(word.substring(0, word.length() - 1))) {
                if (word.length() > ans.length())
                    ans = word;
                s.add(word);
            }
        }
        return ans;
    }
}
