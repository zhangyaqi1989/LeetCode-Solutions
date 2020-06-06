class Solution {
    public List<Integer> partitionLabels(String S) {
        int [] lasts = new int[26];
        int n = S.length();
        for(int i = 0; i < n; ++i) {
            lasts[S.charAt(i) - 'a'] = i;
        }
        int lo = 0, last = 0;
        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            char ch = S.charAt(i);
            last = Math.max(last, lasts[ch - 'a']);
            if (last == i) {
                ans.add(i - lo + 1);
                lo = i + 1;
            }
        }
        return ans;
    
    }
}
