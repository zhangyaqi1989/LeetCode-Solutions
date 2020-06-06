class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        int cnt = 0;
        Map<Integer, List<Integer>> diags = new TreeMap<>();
        int h = nums.size();
        for(int i = 0; i < h; ++i) {
            List<Integer> row = nums.get(i);
            int w = row.size();
            cnt += w;
            for(int j = 0; j < w; ++j) {
                int num = row.get(j);
                diags.putIfAbsent(i + j, new ArrayList<>());
                diags.get(i + j).add(row.get(j));
            }
        }
        int [] ans = new int [cnt];
        int idx = 0;
        for(int key : diags.keySet()) {
            List<Integer> row = diags.get(key);
            int n = row.size();
            for(int i = n - 1; i >= 0; --i) {
                ans[idx++] = row.get(i);
            }
        }
        return ans;
    }
}
