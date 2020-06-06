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
        set<pair<int, int>> seen;
        dfs(0, 0, -1, 0, seen, robot);
    }
    
    void dfs(int r, int c, int dr, int dc, set<pair<int, int>> & seen, Robot & robot) {
        seen.insert({r, c});
        robot.clean();
        for (int i = 0; i < 4; ++i) {
            int newr = r + dr, newc = c + dc;
            if(seen.find({newr, newc}) == seen.end() && robot.move()) {
                // robot.move(); has already moved in conditions
                dfs(newr, newc, dr, dc, seen, robot);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            int temp = dc;
            dc = dr;
            dr = -temp;
            robot.turnLeft();
        }
    }
};
