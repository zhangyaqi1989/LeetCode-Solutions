class Solution {
    public List<String> generatePossibleNextMoves(String s) {
        List<String> ans = new ArrayList<>();
        int i = 0, n = s.length();
        while (i < n) {
            int j = s.indexOf("++", i);
            if (j == -1) return ans;
            else {
                ans.add(s.substring(0, j) + "--" + s.substring(j + 2));
                i = j + 1;
            }
        }
        return ans;
    }
}
