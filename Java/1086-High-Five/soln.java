class Solution {
    public int[][] highFive(int[][] items) {
        Map<Integer, List<Integer>> scores = new TreeMap<>();
        for(int [] item : items) {
            int id = item[0];
            scores.putIfAbsent(id, new ArrayList<>());
            scores.get(id).add(item[1]);
        }
        int [][] ans = new int [scores.size()][2];
        int idx = 0;
        for(int id : scores.keySet()) {
            List<Integer> nums = scores.get(id);
            Collections.sort(nums, (a, b) -> (b - a));
            int avg = 0;
            for(int i = 0; i < 5; ++i) avg += nums.get(i);
            ans[idx][0] = id;
            ans[idx][1] = avg / 5;
            ++idx;
        }
        return ans;
    }
}
