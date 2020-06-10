class Solution {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        int n = friends.length;
        int [] levels = new int [n];
        Arrays.fill(levels, -1);
        List<Integer> frontier = new ArrayList<>();
        frontier.add(id);
        levels[id] = 0;
        int nsteps = 0;
        while (!frontier.isEmpty()) {
            if (level-- == 0) break;
            List<Integer> next_level = new ArrayList<>();
            ++nsteps;
            for(int u : frontier) {
                for(int v : friends[u]) {
                    if (levels[v] == -1) {
                        levels[v] = nsteps;
                        next_level.add(v);
                    }
                }
            }
            frontier = next_level;
        }
        Map<String, Integer> counter = new HashMap<>();
        for(int u : frontier) {
            for(String v : watchedVideos.get(u)) {
                counter.put(v, counter.getOrDefault(v, 0) + 1);
            }
        }
        List<String> ans = new ArrayList<>();
        for(String v : counter.keySet()) {
            ans.add(v);
        }
        Comparator<String> comp = (String a, String b) -> (counter.get(a) == counter.get(b) ? a.compareTo(b) : (counter.get(a) - counter.get(b)));
        Collections.sort(ans, comp);
        return ans; 
    }
}
