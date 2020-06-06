class Solution {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> set = new HashSet<>();
        for(String word : A) {
            String even = helper(word, 0, 2);
            String odd = helper(word, 1, 2);
            set.add(even + " " + odd);
        }
        return set.size();
    }

    private String helper(String str, int start, int d) {
        List<Character> chars = new ArrayList<>();
        int n = str.length();
        for(int i = start; i < n; i += d) {
            chars.add(str.charAt(i));
        }
        Collections.sort(chars);
        StringBuilder sb = new StringBuilder();
        for(char ch : chars) sb.append(ch);
        return sb.toString();
    }
}
