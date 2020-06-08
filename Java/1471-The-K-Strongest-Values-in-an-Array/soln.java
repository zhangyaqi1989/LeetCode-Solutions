class Solution {
    public int[] getStrongest(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;
        int median = arr[(n - 1) / 2];
        int [] ans = new int [k];
        int idx = 0, i = 0, j = n - 1;
        while(k --> 0) {
            if(median - arr[i] > arr[j] - median) ans[idx++] = arr[i++];
            else ans[idx++] = arr[j--];
        }
        return ans;
    }
}
