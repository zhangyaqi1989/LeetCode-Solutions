class Solution {
    public char findKthBit(int n, int k) {
        List<Integer> lst = new ArrayList<>();
        lst.add(0);
        for(int i = 1; i < n; ++i) {
            int m = lst.size();
            lst.add(1);
            for(int j = m - 1; j >= 0; --j) lst.add(1 - lst.get(j));
        }
        return (char) ('0' + lst.get(k - 1));
    }
}
