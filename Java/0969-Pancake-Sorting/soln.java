class Solution {
    public List<Integer> pancakeSort(int[] A) {
        int [] SA = A.clone();
        Arrays.sort(SA);
        List<Integer> ans = new ArrayList<>();
        if (Arrays.equals(SA, A)) return ans;
        int n = A.length;
        for(int top = n; top >= 1; --top) {
            int idx = find(A, top);
            if (idx == top - 1) continue;
            ans.add(idx + 1);
            reverse(A, 0, idx);
            ans.add(top);
            reverse(A, 0, top - 1);
        }
        // for(int num : A) System.out.println(num);
        return ans;
    }
    
    private int find(int [] A, int num) {
        for(int i = 0; i < A.length; ++i) {
            if (A[i] == num) return i;
        }
        return -1;
    }

    private void reverse(int [] A, int lo, int hi) {
        while (lo < hi) {
            int temp = A[lo];
            A[lo] = A[hi];
            A[hi] = temp;
            ++lo;
            --hi;
        }
    }
}
