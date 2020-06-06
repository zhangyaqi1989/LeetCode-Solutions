class Solution {
    public int maxNumberOfApples(int[] arr) {
        int cnt = 0, basket = 0;
        Arrays.sort(arr);
        for(int num : arr) {
            if (basket + num <= 5000) {
                ++cnt;
                basket += num;
            }
        }
        return cnt;
    }
}
