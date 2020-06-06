/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        dfs(robot, 0, 0, 0, -1, visited);
    }
    
private:
    void dfs(Robot & robot, int i, int j, int di, int dj, unordered_set<string> & visited) {
        visited.insert(to_string(i) + " " + to_string(j));
        robot.clean();
        for(int k = 0; k < 4; ++k) {
            int ni = i + di, nj = j + dj;
            if (!visited.count(to_string(ni) + " " + to_string(nj)) && robot.move()) {
                dfs(robot, ni, nj, di, dj, visited);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
            int temp = di;
            di = -dj;
            dj = temp;
        }
    }
};
