class Solution {
    public List<String> ambiguousCoordinates(String S) {
        S = S.substring(1, S.length() - 1);
        int n = S.length();
        List<String> ans = new ArrayList<>();
        for(int i = 1; i < n; ++i) {
            String left = S.substring(0, i);
            String right = S.substring(i);
            for(String l : toNums(left))
                for(String r : toNums(right)) {
                    ans.add("(" + l + ", " + r + ")");
                }
        }
        return ans;
    }
    
    public List<String> toNums(String s) {
        int n = s.length();
        List<String> ans = new ArrayList<>();
        if (s.charAt(n - 1) != '0') {
            for(int i = 1; i < n; ++i) {
                if (s.charAt(0) == '0' && i > 1) continue;
                boolean valid = false;
                for(int j = i; j < n; ++j) {
                    if (s.charAt(j) != '0') {
                        valid = true;
                        break;
                    }
                }
                if (valid) ans.add(s.substring(0, i) + "." + s.substring(i));
            }
        }
        if (s.charAt(0) != '0' || n == 1) ans.add(s);
        return ans;
    }
}
