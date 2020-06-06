class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int first = 0, second = 1;
        int cnt1 = 0, cnt2 = 0;
        for(int num : nums) {
            if (num == first) {
                ++cnt1;
            } else if (num == second) {
                ++cnt2;
            } else if (cnt1 == 0) {
                first = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                second = num;
                cnt2 = 1;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        List<Integer> ans = new ArrayList<>();
        cnt1 = cnt2 = 0;
        for(int num : nums) {
            if (num == first) {
                ++cnt1;
            } else if (num == second) {
                ++cnt2;
            }
        }
        if (cnt1 > nums.length / 3) ans.add(first);
        if (cnt2 > nums.length / 3) ans.add(second);
        return ans;
    }
}
