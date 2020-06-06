class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int mx = 0;
        for(int num : candies) {
            if(num > mx) mx = num;
        }
        List<Boolean> ans = new ArrayList<>();
        for(int num : candies) {
            if(num + extraCandies >= mx) ans.add(true);
            else ans.add(false);
        }
        return ans;
    }
}
