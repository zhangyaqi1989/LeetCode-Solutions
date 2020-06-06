class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int card : deck) counter.put(card, counter.getOrDefault(card, 0) + 1);
        int ans = 0;
        for(int v : counter.values()) ans = gcd(ans, v);
        return ans > 1;
    }
    
    public int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
}
