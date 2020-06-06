class TrieNode {
    boolean is_word;
    TrieNode [] children;
    
    public TrieNode() {
        is_word = false;
        children = new TrieNode[26];
    }
}


class StreamChecker {
    TrieNode root;
    List<Character> stream;
    public StreamChecker(String[] words) {
        stream = new ArrayList<>();
        root = new TrieNode();
        for(String word : words) {
            int m = word.length();
            TrieNode cur = root;
            for(int i = m - 1; i >= 0; --i) {
                if(cur.children[word.charAt(i) - 'a'] == null) {
                    cur.children[word.charAt(i) - 'a'] = new TrieNode();
                }
                cur = cur.children[word.charAt(i) - 'a'];
            }
            cur.is_word = true;
        }
    }
    
    public boolean query(char letter) {
        stream.add(letter);
        int m = stream.size();
        TrieNode cur = root;
        for(int i = m - 1; i >= 0; --i) {
            cur = cur.children[stream.get(i) - 'a'];
            if (cur == null) return false;
            else if (cur.is_word) return true;
        }
        return false;
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words);
 * boolean param_1 = obj.query(letter);
 */
