class Solution {
    public List<Integer> transformArray(int[] arr) {
        int n = arr.length;
        while(true) {
            boolean change = false;
            int [] new_arr = arr.clone();
            for(int i = 1; i < n - 1; ++i) {
                if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    change = true;
                    ++new_arr[i];
                }
                if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    change = true;
                    --new_arr[i];
                }
            }
            
            arr = new_arr;
            if(!change) break;
        }
        List<Integer> ans = new ArrayList<>();
        for(int num : arr) ans.add(num);
        return ans;
    }
}
