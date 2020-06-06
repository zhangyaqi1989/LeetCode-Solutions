class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> words = new HashSet<>();
        for(String word : wordList) words.add(word);
        if (!words.contains(endWord)) return 0;
        Set<String> s1 = new HashSet<>(), s2 = new HashSet<>();
        s1.add(beginWord);
        s2.add(endWord);
        int step = 1;
        while (!s1.isEmpty() && !s2.isEmpty()) {
            if (s1.size() > s2.size()) {
                Set<String> temp = s1;
                s1 = s2;
                s2 = temp;
            }
            Set<String> s = new HashSet<>();
            ++step;
            for(String word : s1) {
                for(int i = 0; i < word.length(); ++i)
                    for(char ch = 'a'; ch <= 'z'; ++ch) {
                        String new_word = word.substring(0, i) + ch + word.substring(i + 1);
                        if (s2.contains(new_word)) return step;
                        if (words.contains(new_word)) {
                            words.remove(new_word);
                            s.add(new_word);
                        }
                    }
            }
            s1 = s;
        }
        return 0;
    }
}
