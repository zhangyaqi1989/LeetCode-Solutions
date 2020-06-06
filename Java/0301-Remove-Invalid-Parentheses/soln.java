class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans = new ArrayList<>();
        Set<String> level = new HashSet<>();
        level.add(s);
        while (true) {
            for(String item : level) {
                if (is_valid(item)) ans.add(item);
            }
            if (!ans.isEmpty()) break;
            Set<String> temp = new HashSet<>();
            for(String item : level) {
                for(int i = 0; i < item.length(); ++i) {
                    temp.add(item.substring(0, i) + item.substring(i + 1));
                }
            }
            level = temp;
        }
        return ans;
    }
    
    public boolean is_valid(String s) {
        int cnt = 0;
        for(char ch : s.toCharArray()) {
            if (ch == '(') {
                ++cnt;
            } else if (ch == ')') {
                --cnt;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
}
