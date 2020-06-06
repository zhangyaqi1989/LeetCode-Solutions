class Solution {
    public int shortestBridge(int[][] A) {
        int [] dirs = {0, 1, 0, -1, 0};
        int m = A.length, n = A[0].length;
        Queue<int []> frontier = new LinkedList<>();
        Stack<int []> stk = new Stack<>();
        Set<String> seen = new HashSet<>();
        int step = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    A[i][j] = 0;
                    stk.push(new int[]{i, j});
                    
                    while (!stk.empty()) {
                        int [] node = stk.pop();
                        int r = node[0], c = node[1];
                        // System.out.println(r + " " + c);
                        frontier.offer(new int[] {r, c});
                        seen.add(i + " " + j);
                        for (int k = 0; k < 4; ++k) {
                            int dr = dirs[k], dc = dirs[k + 1];
                            int newr = r + dr, newc = c + dc;
                            if (0 <= newr && newr < m && 0 <= newc && newc < n && A[newr][newc] == 1) {
                                stk.push(new int[] {newr, newc});
                                A[newr][newc] = 0;
                            }
                        }
                    }
                    // System.out.println(frontier.size());
                    while (!frontier.isEmpty()) {
                        int sz = frontier.size();
                        for(int p = 0; p < sz; ++p) {
                            int [] node = frontier.poll();
                            int r = node[0], c = node[1];
                            if (A[r][c] == 1) return step - 1;
                            for(int k = 0; k < 4; ++k) {
                                int dr = dirs[k], dc = dirs[k + 1];
                                int newr = r + dr, newc = c + dc;
                                if (0 <= newr && newr < m && 0 <= newc && newc < n && !seen.contains(newr + " " + newc)) {
                                    seen.add(newr + " " + newc);
                                    frontier.offer(new int [] {newr, newc});
                                }
                            }
                        }
                        ++step;
                    }
                    
                    return 0;
                }
            }
        }
        return 0;
    }
}
