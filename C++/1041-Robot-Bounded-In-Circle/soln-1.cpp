class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int idx = 0;
        int x = 0, y = 0;
        for(char inst : instructions) {
            if(inst == 'L') idx = (idx + 3) % 4;
            else if(inst == 'R') idx = (idx + 1) % 4;
            else {
                int dx = dirs[idx][0], dy = dirs[idx][1];
                x += dx;
                y += dy;
            }
        }
        return (x == 0 && y == 0) || (idx != 0);
    }
};
