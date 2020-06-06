/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * interface Robot {
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     public boolean move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     public void turnLeft();
 *     public void turnRight();
 *
 *     // Clean the current cell.
 *     public void clean();
 * }
 */
class Solution {
    public void cleanRoom(Robot robot) {
        Set<String> seen = new HashSet<>();
        dfs(0, 0, -1, 0, seen, robot);
    }
    
    public void dfs(int r, int c, int dr, int dc, Set<String> seen, Robot robot) {
        seen.add(r + "-" + c);
        // System.out.println(r + "-" + c);
        robot.clean();
        for(int i = 0; i < 4; ++i) {
            int newr = r + dr, newc = c + dc;
            if ((!seen.contains(newr + "-" + newc)) && robot.move()) {
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
}
