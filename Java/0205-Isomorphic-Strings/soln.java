class Solution {
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Integer> m1 = new HashMap<>();
        Map<Character, Integer> m2 = new HashMap<>();
        int n = s.length();
        int idx1 = 0, idx2 = 0;
        for(int i = 0; i < n; ++i) {
            char c1 = s.charAt(i), c2 = t.charAt(i);
            if(!m1.containsKey(c1)) {
                idx1 = m1.size();
                m1.put(c1, idx1);
            } else {
                idx1 = m1.get(c1);
            }
            if (!m2.containsKey(c2)) {
                idx2 = m2.size();
                m2.put(c2, idx2);
            } else {
                idx2 = m2.get(c2);
            }
            if (idx1 != idx2) return false;
        }
        return true;
    }
}
