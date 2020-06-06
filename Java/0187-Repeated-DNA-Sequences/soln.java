class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set seen = new HashSet(), repeated = new HashSet();
        int n = s.length();
        for(int i = 0; i < n - 9; ++i) {
            String sub = s.substring(i, i + 10);
            if (seen.contains(sub)) repeated.add(sub);
            else seen.add(sub);
        }
        return new ArrayList(repeated);
    }
}
