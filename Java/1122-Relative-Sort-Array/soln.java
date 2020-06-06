class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int [] idxes = new int [1001];
        Arrays.fill(idxes, 2000);
        for(int i = 0; i < arr2.length; ++i) idxes[arr2[i]] = i;
        List<int []> temp = new ArrayList<>();
        for(int num : arr1) temp.add(new int [] {idxes[num], num});
        Collections.sort(temp, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        int [] ans = new int[arr1.length];
        for(int i = 0; i < arr1.length; ++i) {
            ans[i] = temp.get(i)[1];
        }
        return ans;
    }
}
