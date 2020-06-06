class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> ans = new ArrayList<>();
        int num = 0;
        for(int d : A) {
            num = (num * 2 + d) % 5;
            if (num == 0) {
                ans.add(true);
            } else {
                ans.add(false);
            }
        }
        return ans;
    }
}
