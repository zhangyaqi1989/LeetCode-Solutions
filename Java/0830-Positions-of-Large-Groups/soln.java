class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = S.length();
        int lo = 0, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (S.charAt(i) == S.charAt(lo)) ++cnt;
            else {
                if (i - lo >= 3) {
                    List<Integer> temp = new ArrayList<>();
                    temp.add(lo);
                    temp.add(i - 1);
                    ans.add(temp);
                }
                lo = i;
                cnt = 1;
            }
        }
        if (n - lo >= 3) {
            List<Integer> temp = new ArrayList<>();
            temp.add(lo);
            temp.add(n - 1);
            ans.add(temp);
        }
        return ans;
    }
}
