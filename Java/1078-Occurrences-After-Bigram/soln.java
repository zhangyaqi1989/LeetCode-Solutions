class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] tokens = text.split(" ");
        List<String> ans = new ArrayList<>();
        int n = tokens.length;
        for(int i = 0; i < n - 2; ++i) {
            if (tokens[i].equals(first) && tokens[i + 1].equals(second)) ans.add(tokens[i + 2]);
        }
        int m = ans.size();
        String[] format_ans = new String[m];
        for(int i = 0; i < m; ++i) format_ans[i] = ans.get(i);
        return format_ans;
    }
}
