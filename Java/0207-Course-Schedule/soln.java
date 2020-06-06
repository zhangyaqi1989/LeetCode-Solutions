class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] degrees = new int[numCourses];
        Stack<Integer> frees = new Stack<>();
        ArrayList<Integer>[] graph = new ArrayList[numCourses];
        for(int i = 0; i < numCourses; ++i) graph[i] = new ArrayList<>();
        for(int [] ab : prerequisites) {
            int a = ab[0], b = ab[1];
            ++degrees[a];
            graph[b].add(a);
        }
        for(int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) frees.push(i);
        }
        int cnt = 0;
        while (!frees.isEmpty()) {
            int node = frees.pop();
            ++cnt;
            for(int nei : graph[node]) {
                if (--degrees[nei] == 0) frees.push(nei);
            }
        }
        return cnt == numCourses;
    }
}
