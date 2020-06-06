class TrieNode {
    public boolean is_word;
    public TrieNode [] children;
    TrieNode() {
        is_word = false;
        children = new TrieNode[26];
        Arrays.fill(children, null);
    }
}

class Trie {
    public TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode cur = root;
        for(char ch : word.toCharArray()) {
            if(cur.children[ch - 'a'] == null) cur.children[ch - 'a'] = new TrieNode();
            cur = cur.children[ch - 'a'];
        }
        cur.is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode cur = root;
        for(char ch : word.toCharArray()) {
            cur = cur.children[ch - 'a'];
            if(cur == null) return false;
        }
        return cur.is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode cur = root;
        for(char ch : prefix.toCharArray()) {
            cur = cur.children[ch - 'a'];
            if(cur == null) return false;
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
