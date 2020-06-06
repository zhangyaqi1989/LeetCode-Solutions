class Solution {
    public List<String> buildArray(int[] target, int n) {
        int nxt = 1;
        List<String> ans = new ArrayList<>();
        for(int num : target) {
            while(nxt != num) {
                ans.add("Push");
                ans.add("Pop");
                ++nxt;
            }
            ans.add("Push");
            ++nxt;
        }
        return ans;
    }
}
