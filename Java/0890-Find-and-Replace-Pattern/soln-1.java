class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        String np = normalize(pattern);
        List<String> ans = new ArrayList<>();
        for(String word : words) {
            if (np.equals(normalize(word)))
                ans.add(word);
        }
        return ans;
    }
    
    public String normalize(String word) {
        int[] m = new int[256];
        Arrays.fill(m, -1);
        int size = 0;
        for(char ch : word.toCharArray()) {
            if (m[ch] == -1) m[ch] = size++;
        }
        StringBuilder sb = new StringBuilder();
        for(char ch : word.toCharArray()) {
            sb.append((char) m[ch]);
        }
        return sb.toString();
    }
}
