class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = arr.length;
        Arrays.sort(arr);
        int min_diff = arr[n - 1] - arr[0];
        for(int i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] <= min_diff) {
                if (arr[i] - arr[i - 1] < min_diff) {
                    ans.clear();
                    min_diff = arr[i] - arr[i - 1];
                }
                List<Integer> temp = new ArrayList<>();
                temp.add(arr[i - 1]);
                temp.add(arr[i]);
                ans.add(temp);
            }
        }
        return ans;
    }
}
