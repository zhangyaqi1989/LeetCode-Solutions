class Solution {
    public String removeDuplicates(String S) {
        while (true) {
            String news = helper(S);
            if (news.length() == S.length()) break;
            S = news;
        }
        return S;
    }
    
    public String helper(String S) {
        StringBuilder sb = new StringBuilder();
        int i = 0, n = S.length();
        for(int j = 0; j < n; ++j) {
            if (S.charAt(j) != S.charAt(i)) {
                if ((j - i) % 2 == 1) sb.append(S.charAt(i));
                i = j;
            }
        }
        if ((n - i) % 2 == 1) sb.append(S.charAt(i));
        return sb.toString();
    }
}
