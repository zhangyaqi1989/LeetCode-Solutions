class Solution {
    public int[] decompressRLElist(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        for(int i = 0; i < n;) {
            int cnt = nums[i++];
            int num = nums[i++];
            for(int j = 0; j < cnt; ++j) ans.add(num);
        }
        n = ans.size();
        int [] ans_array = new int [n];
        for(int i = 0; i < n; ++i) {
            ans_array[i] = ans.get(i);
        }
        return ans_array;
    }
}
