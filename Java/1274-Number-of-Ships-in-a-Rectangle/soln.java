/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *     public boolean hasShips(int[] topRight, int[] bottomLeft);
 * }
 */

class Solution {
    public int countShips(Sea sea, int[] topRight, int[] bottomLeft) {
        return helper(sea, topRight, bottomLeft);
    }
    
    private int helper(Sea sea, int[] topRight, int[] bottomLeft) {
        int x1 = bottomLeft[0], y1 = bottomLeft[1];
        int x2 = topRight[0], y2 = topRight[1];
        if (x1 > x2 || y1 > y2 || !sea.hasShips(topRight, bottomLeft)) return 0;
        if (x1 == x2 && y1 == y2) return 1;
        int xmid = x1 + (x2 - x1) / 2;
        int ymid = y1 + (y2 - y1) / 2;
        return helper(sea, new int [] {xmid, ymid}, new int [] {x1, y1}) + 
               helper(sea, new int [] {x2, ymid}, new int [] {xmid + 1, y1}) + 
               helper(sea, new int [] {x2, y2}, new int [] {xmid + 1, ymid + 1}) + 
               helper(sea, new int [] {xmid, y2}, new int [] {x1, ymid + 1});
    }
}
