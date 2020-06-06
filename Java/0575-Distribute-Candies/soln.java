class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> s = new HashSet<>();
        for(int cand : candies) s.add(cand);
        return Math.min(s.size(), candies.length / 2);
    }
}
