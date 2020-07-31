class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        int d = (arr[n - 1] - arr[0]) / n;
        for(int i = 0; i < n - 1; ++i) {
            if(arr[i + 1] != arr[i] + d) return arr[i] + d;
        }
        return arr[0];
    }
}
