class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int ans = 0;
        Set<String> obs = new HashSet<>();
        for(int [] ob : obstacles) {
            obs.add(ob[0] + " " + ob[1]);
        }
        int[][] dirs = new int[][] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, idx = 0;
        for(int command : commands) {
            if (command == -2) {
                --idx;
                if (idx < 0) idx += 4;
            } else if (command == -1) {
                ++idx;
                idx = idx % 4;
            } else {
                int dx = dirs[idx][0], dy = dirs[idx][1];
                for(int i = 0; i < command; ++i) {
                    x += dx;
                    y += dy;
                    if (obs.contains(x + " " + y)) {
                        x -= dx;
                        y -= dy;
                        break;
                    } else {
                        ans = Math.max(ans, x * x + y * y);
                    }
                }
            }
        }
        return ans;
    }
}
