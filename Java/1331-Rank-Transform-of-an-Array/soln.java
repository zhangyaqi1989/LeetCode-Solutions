class Solution {
    public int[] arrayRankTransform(int[] arr) {
        Set<Integer> nums = new TreeSet<>();
        for(int num : arr) nums.add(num);
        Map<Integer, Integer> idxes = new HashMap<>();
        int idx = 1;
        Iterator<Integer> it = nums.iterator();
        while(it.hasNext()) {
            idxes.put(it.next(), idx++);
        }
        int n = arr.length;
        int [] ans = new int [n];
        for(int i = 0; i < n; ++i) {
            ans[i] = idxes.get(arr[i]);
        }
        return ans;
    }
}
