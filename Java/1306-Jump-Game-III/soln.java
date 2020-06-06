class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        Stack<Integer> frontier = new Stack<>();
        frontier.push(start);
        boolean [] seen = new boolean [n];
        seen[start] = true;
        while (!frontier.isEmpty()) {
            int u = frontier.pop();
            if (arr[u] == 0) return true;
            if (u + arr[u] < n && !seen[u + arr[u]]) {
                seen[u + arr[u]] = true;
                frontier.push(u + arr[u]);
            }
            if (u - arr[u] >= 0 && !seen[u - arr[u]]) {
                seen[u - arr[u]] = true;
                frontier.push(u - arr[u]);
            }
        }
        return false;
    }
}
