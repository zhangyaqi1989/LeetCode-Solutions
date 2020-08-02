class Solution {
    public int getWinner(int[] arr, int k) {
        int cur = arr[0], win = 0;
        for(int i = 1; i < arr.length; ++i) {
            if(arr[i] > cur) {
                cur = arr[i];
                win = 0;
            }
            win += 1;
            if(win == k) return cur;
        }
        return cur;
    }
}
