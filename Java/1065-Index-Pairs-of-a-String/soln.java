class Solution {
    public int[][] indexPairs(String text, String[] words) {
        List<int []> idxes = new ArrayList<>();
        int n = text.length();
        for(int i = 0; i < n; ++i) {
            for(String word : words) {
                if (text.startsWith(word, i)) {
                    idxes.add(new int [] {i, i + word.length() - 1});
                }
            }
        }
        Collections.sort(idxes, (a, b)->{return a[0] != b[0] ? a[0] - b[0] : a[1] - b[1];});
        int m = idxes.size();
        int [][] ans = new int [m][2];
        for(int i = 0; i < m; ++i) {
            ans[i] = idxes.get(i);
        }
        return ans;
    }
}
