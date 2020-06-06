class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] visited = new boolean[n];
        visited[0] = true;
        Stack<Integer> s = new Stack<Integer>();
        s.push(0);
        int cnt = 0;
        while (!s.isEmpty()) {
            int room = s.pop();
            ++cnt;
            for(int nei : rooms.get(room)) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    s.push(nei);
                }
            }
        }
        return cnt == n;
    }
}
