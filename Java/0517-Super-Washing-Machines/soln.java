class Solution {
    public int findMinMoves(int[] machines) {
        int sum = 0, n = machines.length;
        for(int cloth : machines) sum += cloth;
        if (sum % n != 0) return -1;
        int target = sum / n;
        int ans = 0;
        int to_left = 0;
        for(int cloth : machines) {
            int to_right = cloth - target - to_left;
            ans = Math.max(ans, Math.max(Math.max(to_left, to_right), to_left + to_right));
            to_left = -to_right;
        }
        return ans;
    }
}
