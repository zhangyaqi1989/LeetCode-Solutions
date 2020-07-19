class Solution {
    public int closestToTarget(int[] arr, int target) {
        HashSet<Integer> s = new HashSet<>();
        int best = 1000000000;
        for(int num : arr) {
            HashSet<Integer> ns =  new HashSet<>();
            ns.add(num);
            for(int val : s) {
                ns.add(val & num);
            }
            for(int val : ns) {
                best = Math.min(best, Math.abs(target - val));
            }
            s = ns;
        }
        return best;
    }
}
