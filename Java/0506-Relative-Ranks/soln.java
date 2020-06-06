class Solution {
    public String[] findRelativeRanks(int[] nums) {
        int n = nums.length;
        int [][] array = new int[n][2];
        for(int i = 0; i < n; ++i) {
            array[i][0] = nums[i];
            array[i][1] = i;
        }
        Arrays.sort(array, (a, b) -> (b[0] - a[0]));
        String[] res = new String[n];
        for(int i = 0; i < n; ++i) {
            int pos = array[i][1];
            if (i == 0) res[pos] = "Gold Medal";
            else if (i == 1) res[pos] = "Silver Medal";
            else if (i == 2) res[pos] = "Bronze Medal";
            else res[pos] = (i + 1) + "";
        }
        return res;
    }
}
