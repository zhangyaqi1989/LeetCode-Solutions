class Solution {
    public String toGoatLatin(String S) {
        String [] tokens = S.split(" ");
        List<String> lst = new ArrayList<>();
        int idx = 1;
        String end = "a";
        String vowels = "aeiouAEIOU";
        for (String token : tokens) {
            if (vowels.indexOf(token.charAt(0)) != -1) {
                lst.add(token + "ma" + end);
            } else {
                lst.add(token.substring(1) + token.substring(0, 1) + "ma" + end);
            }
            ++idx;
            end += "a";
        }
        return String.join(" ", lst);
    }
}
