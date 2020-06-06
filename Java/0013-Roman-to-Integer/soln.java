class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> units = new HashMap<>();
        units.put('I', 1);
        units.put('V', 5);
        units.put('X', 10);
        units.put('L', 50);
        units.put('C', 100);
        units.put('D', 500);
        units.put('M', 1000);
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            ans += units.get(s.charAt(i));
            if (i > 0 && units.get(s.charAt(i)) > units.get(s.charAt(i - 1)))
                ans -= 2 * units.get(s.charAt(i - 1));
        }
        return ans;
    }
}
