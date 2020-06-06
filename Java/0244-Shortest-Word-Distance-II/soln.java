class WordDistance {
    public HashMap<String, ArrayList<Integer>> idxes;
    public WordDistance(String[] words) {
        int n = words.length;
        idxes = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            String word = words[i];
            if (idxes.containsKey(word)) idxes.get(word).add(i);
            else {
                ArrayList<Integer> lst = new ArrayList<Integer> ();
                lst.add(i);
                idxes.put(word, lst);
            }
        }
    }
    
    public int shortest(String word1, String word2) {
        ArrayList<Integer> lst1 = idxes.get(word1);
        ArrayList<Integer> lst2 = idxes.get(word2);
        int n1 = lst1.size(), n2 = lst2.size();
        int i1 = 0, i2 = 0;
        int ans = Integer.MAX_VALUE;
        while (i1 < n1 && i2 < n2) {
            ans = Math.min(ans, Math.abs(lst1.get(i1) - lst2.get(i2)));
            if (lst1.get(i1) < lst2.get(i2)) ++i1;
            else ++i2;
        }
        return ans;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
