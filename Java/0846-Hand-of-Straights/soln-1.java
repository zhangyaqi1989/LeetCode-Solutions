class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        int n = hand.length;
        if (n % W != 0) return false;
        TreeMap<Integer, Integer> counter = new TreeMap<>();
        for(int num : hand) counter.put(num, counter.getOrDefault(num, 0) + 1);
        for(int i = 0; i < n / W; ++i) {
            int start = counter.firstKey();
            for(int m = start; m < start + W; ++m) {
                if (!counter.containsKey(m)) return false;
                if (counter.get(m) == 1) counter.remove(m);
                else counter.put(m, counter.get(m) - 1);
            }
        }
        return true;
    }
}
