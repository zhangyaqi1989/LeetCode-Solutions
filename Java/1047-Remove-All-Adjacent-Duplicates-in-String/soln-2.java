class Solution {
    public String removeDuplicates(String S) {
        List<Character> chars = new ArrayList<>();
        for(char ch : S.toCharArray()) {
            if (!chars.isEmpty() && chars.get(chars.size() - 1) == ch) {
                chars.remove(chars.size() - 1);
            } else {
                chars.add(ch);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(char ch : chars) sb.append(ch);
        return sb.toString();
    }
}
