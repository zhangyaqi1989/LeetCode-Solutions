class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        List<String> sub = new ArrayList<>();
        helper(s, 0, sub, ans);
        return ans;
    }
    
    public void helper(String s, int idx, List<String> sub, List<List<String>> ans) {
        // System.out.println(idx);
        if (idx == s.length()) {
            List<String> c = new ArrayList<>(sub);
            ans.add(c);
        } else {
            for(int i = idx + 1; i < s.length() + 1; ++i) {
                if (isPalindrome(s.substring(idx, i))) {
                    sub.add(s.substring(idx, i));
                    helper(s, i, sub, ans);
                    sub.remove(sub.size() - 1);
                }
            }
        }
    }
    
    public boolean isPalindrome(String s) {
        int n = s.length();
        for(int i = 0; i < n / 2; ++i) {
            if (s.charAt(i) != s.charAt(n - 1 - i)) return false;
        }
        return true;
    }
    
    
}
