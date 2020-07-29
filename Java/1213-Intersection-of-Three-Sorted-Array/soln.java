class Solution {
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3) {
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : arr1) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        for(int num : arr2) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        for(int num : arr3) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        List<Integer> ans = new ArrayList<>();
        for(int num : counter.keySet()) {
            if(counter.get(num) == 3) ans.add(num);
        }
        return ans;
    }
}
