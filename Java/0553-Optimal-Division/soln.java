class Solution {
    public String optimalDivision(int[] nums) {
        int n = nums.length;
        if (n == 1) return Integer.toString(nums[0]);
        else if (n == 2) return Integer.toString(nums[0]) + "/" + Integer.toString(nums[1]);
        else {
            List<String> lst = new ArrayList<>();
            for(int i = 1; i < n; ++i) {
                lst.add(Integer.toString(nums[i]));
            }
            return Integer.toString(nums[0]) + "/(" + String.join("/", lst) + ")";
        }
    }
}
