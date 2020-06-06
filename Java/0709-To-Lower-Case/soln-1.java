class Solution {
    public String toLowerCase(String str) {
        StringBuilder sb = new StringBuilder();
        for(char ch : str.toCharArray()) {
            if (ch >= 'A' && ch <= 'Z') {
                sb.append((char)(ch + 'a' - 'A'));
            } else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}
