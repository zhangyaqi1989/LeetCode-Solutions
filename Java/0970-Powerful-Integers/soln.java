class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> set = new HashSet<>();
        for(int left = 1; left <= bound; left *= x) {
            for(int right = 1; left + right <= bound; right *= y) {
                if (left + right <= bound) set.add(left + right);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        List<Integer> ans = new ArrayList<>();
        for(int num : set) ans.add(num);
        return ans;
    }
}
