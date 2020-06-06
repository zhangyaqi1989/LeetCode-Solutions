class Solution {
    public int findLucky(int[] arr) {
        final int N = 501;
        int [] counter = new int [N];
        for(int num : arr) ++counter[num];
        for(int i = N - 1; i > 0; --i) {
            if (counter[i] == i) return i;
        }
        return -1;
    }
}
