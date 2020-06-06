class Solution {
    public boolean areSentencesSimilar(String[] words1, String[] words2, List<List<String>> pairs) {
        if (words1.length != words2.length) return false;
        Map<String, Set<String>> dict = new HashMap<>();
        for(List<String> pair : pairs) {
            dict.putIfAbsent(pair.get(0), new HashSet<>());
            dict.putIfAbsent(pair.get(1), new HashSet<>());
            dict.get(pair.get(0)).add(pair.get(1));
            dict.get(pair.get(1)).add(pair.get(0));
        }
        int n = words1.length;
        for(int i = 0; i < n; ++i) {
            if (words1[i].equals(words2[i])) continue;
            if (!dict.containsKey(words1[i]) || !dict.get(words1[i]).contains(words2[i])) return false;
        }
        return true;
        
    }
}
