class Solution {
    public int[] replaceElements(int[] arr) {
        int right = -1;
        int n = arr.length;
        for(int i = n - 1; i >= 0; --i) {
            int num = arr[i];
            arr[i] = right;
            right = Math.max(right, num);
        }
        return arr;
    }
}
