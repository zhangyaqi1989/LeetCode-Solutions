class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans = new ArrayList<>();
        if (words.length == 0) return ans;
        int ns = s.length(), nw = words[0].length(), total_len = nw * words.length;
        Map<String, Integer> counter = new HashMap<>();
        for(String word : words) counter.put(word, counter.getOrDefault(word, 0) + 1);
        for(int i = 0; i < ns - total_len + 1; ++i) {
            int j = i;
            Map<String, Integer> seen = new HashMap<>();
            boolean valid = true;
            while (j < i + total_len) {
                String word = s.substring(j, j + nw);
                if (counter.containsKey(word) && seen.getOrDefault(word, 0) < counter.get(word)) {
                    seen.put(word, seen.getOrDefault(word, 0) + 1);
                    j += nw;
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.add(i);
        }
        return ans;
    }
}
