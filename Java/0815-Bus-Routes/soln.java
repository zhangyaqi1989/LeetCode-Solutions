class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        Map<Integer, List<Integer>> stops = new HashMap<>();
        int n = routes.length;
        for(int i = 0; i < n; ++i) {
            for(int stop : routes[i]) {
                if (!stops.containsKey(stop)) stops.put(stop, new ArrayList<>());
                stops.get(stop).add(i);
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(S);
        Set<Integer> seen = new HashSet<>();
        boolean [] line_used = new boolean[501];
        Arrays.fill(line_used, false);
        int steps = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; ++i) {
                int stop = queue.poll();
                if (stop == T) return steps;
                for(int line : stops.get(stop)) {
                    if (line_used[line]) continue;
                    line_used[line] = true;
                    for(int s : routes[line]) {
                        if (!seen.contains(s)) {
                            seen.add(s);
                            queue.add(s);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
}
