class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        int n = hand.length;
        if (n % W != 0) return false;
        TreeMap<Integer, Integer> counter = new TreeMap<>();
        for(int card : hand) {
            counter.put(card, counter.getOrDefault(card, 0) + 1);
        }
        int m = n / W;
        for(int i = 0; i < m; ++i) {
            int first = counter.firstKey();
            for(int num = first; num < first + W; ++num) {
                if (!counter.containsKey(num)) return false;
                counter.put(num, counter.get(num) - 1);
                if (counter.get(num) == 0) counter.remove(num);
            }
        }
        return true;
    }
}
