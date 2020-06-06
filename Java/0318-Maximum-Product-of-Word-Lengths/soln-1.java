class Solution {
    public int maxProduct(String[] words) {
        Map<Integer, Integer> masks = new HashMap<>();
        for(String word : words) {
            int temp = 0;
            int n = word.length();
            for(char ch : word.toCharArray()) {
                temp |= (1 << (ch - 'a'));
            }
            if (masks.get(temp) == null || masks.get(temp) < n) 
                masks.put(temp, n);
        }
        int ans = 0;
        for(int a : masks.keySet())
            for(int b : masks.keySet()) {
                if ((a & b) == 0)
                    ans = Math.max(ans, masks.get(a) * masks.get(b));
            }
        return ans;
    }
}
